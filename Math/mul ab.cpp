ll mul(ll a,ll b,ll mod){
  ll res=0;
  while(b>0){
    if(b%2!=0)
      res=(res+a)%mod;
    a=(a*2)%mod;
    b/=2;
  }
  return res;
}