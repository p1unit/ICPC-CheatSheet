vector<ll>v[10000],vv[10000];
ll visit[10000];vector<ll>s;
void dfs(ll a){
  visit[a]=1;
  for(ll i=0;i<v[a].size();i++)
    if(!visit[v[a][i]])
      dfs(v[a][i]);
  s.push_back(a);
}
void dfss(ll a){
  visit[a]=1;cout<<a<<" ";
  for(ll i=0;i<vv[a].size();i++)
    if(!visit[vv[a][i]])
      dfss(vv[a][i]);
}
int main(){
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>j>>k;
        v[j].push_back(k);
        vv[k].push_back(j);}
    for(i=1;i<=n;i++){
        if(!visit[i]){
          dfs(i);
}}
memset(visit,0,sizeof(visit));
for(i=s.size()-1;i>=0;i--){
  if(!visit[s[i]]){
    dfss(s[i]);
    cout<<"\n";
  }
}}