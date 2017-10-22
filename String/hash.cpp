const int BASE = 101, MOD = 1e9+7;

void  makeHash() {
    forf(i,1,n) {
        hsh[i][i] = s[i];
        forf(j,i+1,n) hsh[i][j] = (ll(hsh[i][j-1]) * BASE + s[i]) % MOD;
    }
}