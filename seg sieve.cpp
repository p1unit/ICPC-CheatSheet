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