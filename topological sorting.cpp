vector<int>v;vector<int> adj[25];
bool vis[25];
void dfs(int s){
vis[s] = true;
for(int i=0;i<adj[s].size();i++){
int to = adj[s][i];
if(vis[to]==false){
dfs(to);}}
v.push_back(s);}
void init(){
for(int i=0;i<25;i++) vis[i] = false;}
int main(){
int n,m;int x,y;
cin>>n>>m;init();
for(int i=0;i<m;i++){
cin>>x>>y;
adj[x].push_back(y);}
for(int i=1;i<=n;i++){
sort(adj[i].rbegin(),adj[i].rend());}
for(int i=n;i>=1;i--){
if(vis[i]==false) dfs(i);}
for(int i=v.size()-1;i>=0;i--){
    cout<<v[i]<<" ";}
return 0;}
