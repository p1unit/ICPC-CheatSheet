ll bfs(ll a,ll b){
    queue<ll>q;q.push(a);q.push(b);ar[a][b]=0;
    ll ax[]={1,0,-1,0}; ll ay[]={0,1,0,-1};
    while(!q.empty()){
        ll u=q.front();q.pop();
        ll v=q.front();q.pop();
        ll i,j;
        for(i=0;i<4;i++){
            ll uu=ax[i]+u;ll vv=ay[i]+v;
            if(check(uu,vv)){
                if(ar[u][v]+1<ar[uu][vv]){
                    ar[uu][vv]=ar[u][v]+1;
                    q.push(uu);
                    q.push(vv);
                }
            }
        }
    }
}