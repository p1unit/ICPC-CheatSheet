int main(){
    ll t,i,j,k,m,n;
    cin>>n;ll arx1[n],arx2[n];
    for(i=0;i<n;i++){
        cin>>arx1[i]>>arx2[i];}
    vector<pair<pair<ll,ll>,ll> >v;
    for(i=0;i<n;i++){
    v.push_back(make_pair(make_pair(arx1[i],2),i));
    v.push_back(make_pair(make_pair(arx2[i]+1,-2),i));}
sort(v.begin(),v.end());
set<ll>ss;ll ans=0;
for(i=0;i<v.size();i++){
    if(v[i].first.second==2){
        ss.insert(v[i].second);}
    if(v[i].first.second==-2){
        ll y=ss.size();ans=max(ans,y);
        ll x=v[i].second;ss.erase (x);}}
cout<<ans;}
