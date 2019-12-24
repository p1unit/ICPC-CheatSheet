vector<ll>f;
void ss(ll l,ll r){
	bool isPrime[r - l + 1];
  memset(isPrime,true,sizeof(isPrime));
	for (ll i = 2; i * i <= r; ++i)
		for (ll j = max(i*i, (l+(i-1))/i*i); j<=r;j+= i)
			isPrime[j - l] = false;
	ll k=2;
	for (ll i = max(l, k); i <= r; ++i){
		if (isPrime[i - l])
			f.push_back(i);
	}
}
////
// 1 <= l <= r <= ??
vector<bool> seg_sieve(ll l,ll r){
	ll i,j;
	vector<bool> V(r-l+1,true);
	for(i=2;i*i<=r;++i){
		for(j=max(2LL,(l+i-1)/i)*i;j<=r;j+=i)
			V[j-l]=false;
	}
	if(l==1) V[1-l]=0;
	return V;
}
 