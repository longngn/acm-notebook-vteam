#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

ll gcd(ll a, ll b) { return b == 0? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a * b / gcd(a,b); }
ll fpow(ll x, ll k) {
    ll res = 1;
    for(; k; k >>= 1) {
        if (k & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}
vector<int> digits(ll x) {
	vector<int> res;
	for(; x/10; x/=10) res.push_back(x%10);
    res.push_back(x);
    return res;
}

// Complexity O(k), invented by Long, may not always correct =))
ll combination(ll n, ll k) {
    ll res = 1, j = 2;
    for(ll i = n-k+1; i <= n; i++) {
        res *= i;
        while (j <= k && res % j == 0) res /= j, j++;
    }
    return res;
}

void dp_combination() {
    const int N = 1002; // N is maximum number of n
    int C[N][N];
    const int MOD = 1e9+7;
    
    C[1][0] = C[1][1] = 1;
    for(int n = 2; n <= N; n++) {
        C[n][0] = 1;
        for(int k = 1; k <= n; k++) C[n][k] = (C[n-1][k-1] + C[n-1][k]) % MOD;
    }
}