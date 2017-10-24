const int BASE = 101, MOD = 1e9+7;

void  makeHash() {
    for(int i = 0; i < S.length(); i++) {
        Hash[i][i] = S[i];
        for(int j = i+1; j < S.length(); j++) Hash[i][j] = (1LL * Hash[i][j-1] * BASE + S[j]) % MOD;
    }
}