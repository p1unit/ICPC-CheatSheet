void dfss(ll cur, ll prev){
  lev[cur] = lev[prev] + 1;
  parent[cur][0] = prev;
  for (ll i=0; i<v[cur].size(); i++)
    if (v[cur][i] != prev)
      dfss(v[cur][i], cur);
}
void precomputeSparseMatrix(ll n){
  ll kk=20;
  for (ll i=1; i<kk; i++)
    for (ll node = 1; node <= n; node++)
      if (parent[node][i-1] != -1)
        parent[node][i]=parent[parent[node][i-1]][i-1];
}
ll lca(ll u, ll v){
  ll kk=20;
  if (lev[v] < lev[u])
    swap(u, v);
  ll diff = lev[v] - lev[u];
  for (ll i=0; i<kk; i++)
    if ((diff>>i)&1)
      v = parent[v][i];
  if(u == v)
    return u;
  for(ll i=kk-1; i>=0; i--)
    if(parent[u][i] != parent[v][i]){
      u = parent[u][i];
      v = parent[v][i];
    }
  return parent[u][0];
}