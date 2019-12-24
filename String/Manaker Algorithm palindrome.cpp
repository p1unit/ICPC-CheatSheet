// string s = "aabaabaa";
// d1: [1, 1, 3, 2, 1, 3, 2, 1]
// d2: [0, 1, 0, 0, 4, 0, 0, 1]
vector<ll> d1 (n);
 l=0, r=-1;
for ( i=0; i<n; ++i) {
	ll k = (i>r ? 0 : min (d1[l+r-i], r-i)) + 1;
	while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
	d1[i] = k--;
	if (i+k > r)
		l = i-k,  r = i+k;
}
vector<ll> d2 (n);
l=0, r=-1;
for ( i=0; i<n; ++i) {
	ll k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1LL)) + 1;
	while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k])  ++k;
	d2[i] = --k;
	if (i+k-1 > r)
		l = i-k,  r = i+k-1;
}