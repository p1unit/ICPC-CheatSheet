vector<ll>v[10000];
ll dis[10000];
#define inf 1000000000
int main(){
   cin>>n>>m;
   for(i=0;i<m+2;i++){
       v[i].clear();
       dis[i]=inf;// upto n
       }
   for(i=0;i<m;i++){
       cin>>x>>y>>z;
       v[i].push_back(x);
       v[i].push_back(y);
       v[i].push_back(z);}
   dis[1]=0;//initiate dis[source]=0
   for(i=0;i<n-1;i++){
      for(j=0;j<m;j++){
           if(dis[v[j][0]]+v[j][2]<dis[v[j][1]]){
               dis[v[j][1]]=dis[v[j][0]]+v[j][2];}}}
   for(i=0;i<m;i++){
       if(dis[v[i][0]]!=inf){
       if(dis[v[i][0]]+v[i][2]<dis[v[i][1]]){
           cout<<"negative cycle\n";
           return 0;}}}
   cout<<"negative cycle not found";
    return 0;}
