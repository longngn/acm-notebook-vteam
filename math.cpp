typedef long long ll;

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