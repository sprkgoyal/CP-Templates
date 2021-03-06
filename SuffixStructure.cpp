class SuffixStructure {
	string str;
	vector<int> p, lcp, c;

	void SuffixArrayUtil(string s) {
		s += " ";
		int n = s.size();
		this->c.resize(n);
		this->p.resize(n);
		vector<pair<char, int>> a(n);
		for(int i=0; i<n; i++)	a[i] = {s[i], i};
			sort(all(a));
		for(int i=0; i<n; i++)	this->p[i] = a[i].second;
			this->c[p[0]] = 0;
		for(int i=1; i<n; i++) {
			if(s[this->p[i]] == s[this->p[i-1]])
				this->c[this->p[i]] = this->c[this->p[i-1]];
			else
				this->c[this->p[i]] = this->c[this->p[i-1]]+1;
		}
		int k = 0, lgn = ceil(log2(n));
		while(k <= lgn) {
			vector<pair<pair<int, int>, int>> b(n);
			for(int i=0; i<n; i++) {
				b[i].first.first = this->c[i];
				b[i].first.second = this->c[(i + (1 << k))%n];
				b[i].second = i;
			}
			sort(all(b));
			for(int i=0; i<n; i++)	this->p[i] = b[i].second;
				this->c[this->p[0]] = 0;
			for(int i=1; i<n; i++) {
				if(b[i].first == b[i-1].first)
					this->c[this->p[i]] = this->c[this->p[i-1]];
				else
					this->c[this->p[i]] = this->c[this->p[i-1]]+1;
			}
			k++;
		}
	}
public:
	SuffixStructure(string s) {
		this->str = s;
		SuffixArrayUtil(s);
	}

	vector<int> SuffixArray() {
		return this->p;
	}

	vector<int> LCP() {
		if(not this->lcp.empty())
			return this->lcp;
		
		int n = this->str.size();
		this->lcp.resize(n+1);
		int k = 0;
		for(int i=0; i<n; i++) {
			int pi = this->c[i];
			int j = this->p[pi-1];
			while(this->str[i+k] == this->str[j+k])
				k++;
			this->lcp[pi] = k;
			k = max(0, k-1);
		}
		return this->lcp;
	}
};
