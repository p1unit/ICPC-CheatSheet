vector<pair<ll,ll> >v[100005];
map<pair<ll,ll>,ll>mm;
ll dp[100005],visit[100005];
#define inf 1000000000000
ll dij(ll n){
    ll i,j;
    for(i=0;i<=n;i++){
        dp[i]=inf;}
    priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
    q.push(pair<ll,ll>(0,1));dp[1]=0;
    while(!q.empty()){
        ll u=q.top().second;
        ll w=q.top().first;q.pop();
        if(visit[u])
            continue;
        for(i=0;i<v[u].size();i++){
           if(!visit[v[u][i].first]&&dp[v[u][i].first]>w+v[u][i].second){
                dp[v[u][i].first]=w+v[u][i].second;
                q.push(pair<ll,ll>(dp[v[u][i].first],v[u][i].first));
            }
        }
        visit[u]=1;
        if(u==n)
            break;
    }
    if(dp[n]==inf)
        return -1;
    return dp[n];
}