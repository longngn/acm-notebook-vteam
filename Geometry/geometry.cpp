#include <cmath>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

typedef long long ll;
const double PI = atan(1)*4;

// Calculate angle base on formula a*b = |a|*|b|*cos(a,b)
// The result is radian and always positive
double angle(Point p0, Point c, Point p1) {
    double p0c = sqrt(pow(c.x-p0.x,2)+pow(c.y-p0.y,2)); // p0->c (b)   
    double p1c = sqrt(pow(c.x-p1.x,2)+pow(c.y-p1.y,2)); // p1->c (a)
    double p0p1 = sqrt(pow(p1.x-p0.x,2)+pow(p1.y-p0.y,2)); // p0->p1 (c)
    double res = acos((p1c*p1c+p0c*p0c-p0p1*p0p1)/(2*p1c*p0c));
    return res;
}

ll area(vector<Point> p) {
    ll res = 0;
    for(int i = 0; i <= p.size()-2; i++) res += ll(p[i+1].x-p[i].x) * (p[i+1].y+p[i].y);
    res += ll(p[0].x-p.back().x) * (p[0].y+p.back().y);
    return abs(res);
}

bool isInside(Point p, vector<Point>& polygon) {
    ll sum = 0;
    for(int i = 0; i <= polygon.size()-2; i++) {
        sum += area(vector<Point>{polygon[i], p, polygon[i+1]});
    }
    sum += area(vector<Point>{polygon.back(), p, polygon[0]});
    return sum == area(polygon);
}