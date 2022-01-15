vector<bool> prime;
void sieve(int n) {
	prime.assign(n+1, true);
	prime[0] = prime[1] = false;
	for(int i=2; i<=n; i++) {
		if(prime[i])
			for(ll j=1ll*i*i; j<=n; j+=i)
				prime[j] = false;
	}
}
