long long power(long long a, long long b, long long MOD = 1000'000'007) {
	long long ret = 1;
	while(b) {
		if(b&1)	ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}
