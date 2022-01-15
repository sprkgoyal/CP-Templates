ll phi(ll n) {
    ll result = n;
    ll s = sqrt(n)+1;
    for(ll i=2; i<s; ++i) {
        if (n % p == 0) {
            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    }
    if (n > 1) 
        result -= result / n; 
    return result; 
}
