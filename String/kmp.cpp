#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

#define forf(i, a, b) for(int i=(a); i<=(b); i++)
#define forb(i, a, b) for(int i=(a); i>=(b); i--)
#define ALL(c) c.begin(), c.end()

typedef long long ll;

const int N = 1e6 + 2;
int t[N];

int main() {
    string s, w;
    cin >> s >> w;

    auto m = s.length(), n = w.length();
    s = '!' + s; w = '!' + w;

    t[1] = 0;
    forf(i, 2, n) if (w[i] == w[t[i - 1] + 1]) t[i] = t[i - 1] + 1; else t[i] = 0;

    unsigned int j = 1;
    for(unsigned int i = 1; i <= m; i++) {
        while (j > 1 && s[i] != w[j]) j = t[j - 1] + 1;
        if (s[i] == w[j]) j++;
        if (j > n) {
            cout << i - j + 2 << ' ';
            j = t[n] + 1;
        }
    }
}
