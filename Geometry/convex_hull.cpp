#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

const int N = 1e4 + 2;
int n;
Point a[N];
vector<Point> upHull, lowHull, hull;

// Return positive if angle (OAB) form a CCW, negative if CW, 0 if collinear
ll cross(Point O, Point A, Point B) {
    return ll(A.x-O.x) * (B.y-O.y) - ll(A.y-O.y) * (B.x-O.x);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;

    sort(a+1, a+n+1, [](Point a, Point b) { return a.x == b.x? a.y < b.y : a.x < b.x; });

    upHull.push_back(a[1]);
    upHull.push_back(a[2]);
    for(int i = 3; i <= n; i++) {
        while (upHull.size() >= 2 && cross(upHull[upHull.size()-2], upHull.back(), a[i]) >= 0) upHull.pop_back();
        upHull.push_back(a[i]);
    }

    lowHull.push_back(a[n]);
    lowHull.push_back(a[n-1]);
    for(int i = n-2; i >= 1; i--) {
        while (lowHull.size() >= 2 && cross(lowHull[lowHull.size()-2], lowHull.back(), a[i]) >= 0) lowHull.pop_back();
        lowHull.push_back(a[i]);
    }
    
    for(int i = 0; i <= upHull.size()-2; i++) hull.push_back(upHull[i]);
    for(int i = 0; i <= lowHull.size()-2; i++) hull.push_back(lowHull[i]);

    for(auto x: hull) printf("%d %d\n", x.x, x.y);
}   
