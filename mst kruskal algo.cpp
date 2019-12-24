const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];
void initialize(){
  for(int i = 0;i < MAX;++i)
    id[i] = i;
}
int root(int x){
  while(id[x] != x){
    id[x] = id[id[x]];
    x = id[x];}
  return x;
}
void union1(int x, int y){
  int p = root(x);
  int q = root(y);
  id[p] = id[q];
}
long long kruskal(pair<long long, pair<int, int> > p[]){
  // p is sorted
  int x, y;long long cost, minimumCost = 0;
  for(int i = 0;i < edges;++i){
    // Selecting edges one by one in increasing order 
    x = p[i].second.first;y = p[i].second.second;
    cost = p[i].first;
    // Check if the selected edge is creating a cycle or not
    if(root(x) != root(y)){
      minimumCost += cost;union1(x, y);
    }
  }
  return minimumCost;
}