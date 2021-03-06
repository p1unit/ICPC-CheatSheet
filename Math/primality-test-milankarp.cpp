bool miller(ll n,ll d,ll a){
	srand(time(0));
	//ll a=rand()%(n-4) + 2;
	ll x=me(a,d,n);
	if(x==1||x==n-1)
		return true;
	while(d!=n-1){
		//x=(x*x)%n;
		x=mulmod(x,x,n);
		d*=2;
		if(x==1){return false;}
		if(x==n-1){return true;}
	}
	return false;
}
bool isPrime(ll n){
	if(n==1){return false;}
	if(n<=3){return true;}
	if(n%2==0){return false;}
	ll d=n-1;
	while(d%2==0){
		d/=2;}
	vector<ll>a = {2,3,5,7,11,13,17,19,23,29,31,37,41};
	ll k=a.size();
	ll i=-1;
	while(k--){
		i++;
		if(a[i]<=(n-2)){
		if(!miller(n,d,a[i])){
			//cout<<a[i]<<" "<<d<<"\n";
			return false;
		}}
	}
	return true;
}