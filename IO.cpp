#include <iostream>
#include <vector>
using namespace std;

template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& a) { 
    return os << a.first << ' ' << a.second << '\n';
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& a) { 
    for(auto x: a) os << x << ' '; os << '\n';
    return os;
}

int main() {
    pair<double, int> P(0.5, 3);
    cout << P;
    vector<int> V(5, 3);
    cout << V;
}