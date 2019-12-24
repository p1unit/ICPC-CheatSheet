#define mod 1000000007
void dfs(int u, vector<vector<int> >& adjList, vector<int>& disc, vector<int>& low,
vector<bool>& visited, vector<bool>& ap,
vector<pair<int, int> >& bridges, int parent){
static int time=1;
disc[u] = low[u] = time++;
int child=0;
visited[u] = true;
for (auto& ele: adjList[u]){
if (!visited[ele]){
child++;
dfs(ele, adjList, disc, low, visited, ap, bridges, u);
low[u] = min(low[u], low[ele]);
if (parent==-1 && child>1) ap[u] = true;
else if (parent!=-1 && low[ele]>=disc[u]) ap[u] = true;
if (low[ele]>disc[u]) bridges.push_back({u, ele});
}else if (ele != parent){
low[u] = min(low[u], disc[ele]);}}}
int main() {
int n, m;
cin >> n >> m;
vector<vector<int> > adjList(n);
for (int i=0;i<m;i++){
int a, b;
cin >> a >> b;
adjList[a].push_back(b);
adjList[b].push_back(a);}
vector<bool> visited(n, false);
vector<bool> ap(n, false);
vector<pair<int, int> > bridges;
vector<int> disc(n, INT_MAX);
vector<int> low(n, INT_MAX);
int count=0;
for (int i=0;i<n;i++){
if (!visited[i])
dfs(i, adjList, disc, low, visited, ap, bridges, -1);
}
for (int i=0;i<n;i++){
if (ap[i]) count++;}
cout << count << endl;
for (int i=0;i<n;i++){
if (ap[i]) cout << i << " ";}
cout << endl;
auto compare = [&](auto a, auto b){
return a.first<b.first || (a.first==b.first && a.second<b.second);
};
sort(bridges.begin(), bridges.end(), compare);
cout << bridges.size() << endl;
for (auto& ele: bridges){
cout << ele.first << " " << ele.second << endl;}
return 0;}
