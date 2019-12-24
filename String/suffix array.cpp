// add with $ in the back
vector<ll> suffix(string &s){
	ll n = s.size(),i,j,alphabet=267;
	vector<ll> p(n,0),cnt(alphabet,0),c(n,0),pn(n,0),cn(n,0);
	vector<pair<char,ll> > Fi;
	for(i=0;i<n;++i)Fi.push_back({s[i],i});
	sort(Fi.begin(),Fi.end());
	for(i=0;i<n;++i){p[i]=Fi[i].second;++cnt[s[i]];}
	c[p[0]] = 0;
	ll classes = 1;
	for (i=1;i<n;++i) {
		if (s[p[i]] != s[p[i-1]])  ++classes;
		c[p[i]] = classes-1;
	}
	for (ll h=0; (1<<h)<n; ++h) {
		for (i=0; i<n; ++i) {
			pn[i] = p[i] - (1<<h);
			if (pn[i] < 0)  pn[i] += n;
		}
		cnt.clear();
		cnt.resize(classes,0);
		for (i=0; i<n; ++i)
			++cnt[c[pn[i]]];
		for (i=1; i<classes; ++i)
			cnt[i] += cnt[i-1];
		for (i=n-1; i>=0; --i)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (i=1; i<n; ++i) {
			ll mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
			if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
				++classes;
			cn[p[i]] = classes-1;
		}
		c = cn;
	}
	return p;
}