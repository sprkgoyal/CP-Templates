const int ms = 4;
void matmul(ll a[][ms], ll b[][ms]) {
    ll ret[ms][ms] = {0};
    for(int i=0; i<ms; i++)
        for(int j=0; j<ms; j++)
            for(int k=0; k<ms; k++)
                ret[i][j] = (ret[i][j] + a[i][k]*b[k][j])%mod;
    for(int i=0; i<ms; i++)
        for(int j=0; j<ms; j++)
            a[i][j] = ret[i][j];
}
void matexp(ll mat[][ms], ll b) {
    ll ans[ms][ms] = {0};
    for(int i=0; i<ms; i++)
        ans[i][i] = 1;
    while(b) {
        if(b&1)
            matmul(ans, mat);
        matmul(mat, mat);
        b >>= 1;
    }
    for(int i=0; i<ms; i++)
        for(int j=0; j<ms; j++)
            mat[i][j] = ans[i][j];
}
