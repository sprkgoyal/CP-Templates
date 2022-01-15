ll power(ll x, ll y) {
    ll res = 1;
    while(y) {
        if (y & 1)  res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;
    }
    return res;
}

vector<ll> fact;

void preprocess(int n) {
    fact.resize(n+1, 1);
    for(int i = 2; i <= n; i++)
        fact[i] = (fact[i-1] * i) % mod;
    return;
}

ll nCr(ll n, ll r) {
    return fact[n] * power(fact[r], mod-2) % mod * power(fact[n-r], mod-2) % mod;
}
