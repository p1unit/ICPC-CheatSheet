typedef complex<double> base;
# define PI          3.141592653589793238462643383279502884L /* pi */
void fft (vector<base> & a, bool invert) {
	ll n = (ll) a.size(),i,j,len;
	for (i=1, j=0; i<n; ++i) {
		ll bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
	for (len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (i=0; i<n; i+=len) {
			base w (1);
			for (j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}
void multiply (vector<ll> & a,vector<ll> & b,vector<ll> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	ll n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
	fft (fa, false),  fft (fb, false);
	for (ll i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);
	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = (ll) (fa[i].real() + 0.5);
}