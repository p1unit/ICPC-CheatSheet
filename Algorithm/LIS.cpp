void LIS(vector<ll>&ar, ll n){
	vector<ll>dp(n+1,mod);
	dp[0]=-mod;
	rep(i,0,n){
		ll j=upper_bound(all(dp),ar[i])-dp.begin();
		if(dp[j-1]<ar[i]&&ar[i]<dp[j]){
			dp[j]=ar[i];}}
	ll x=0;
	rep(i,0,n+1){
		if(dp[i]!=mod){
			x=i;}
	}
	cout<<x;
}