ll tot[200005];
void totient(){
	ll i,j;tot[1]=1;
	for(i=2;i<=200000;i++){
	if(tot[i]==0){
			tot[i]=i-1;
		for(j=i*2;j<=200000;j+=i){
			if(tot[j]==0)
				tot[j]=j;
			tot[j]=(tot[j]/i)*(i-1);
		}
	}
}}