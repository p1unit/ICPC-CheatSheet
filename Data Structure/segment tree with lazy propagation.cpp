ll ar1[200000];
ll tree1[500000],lazy1[500000];
void build1(ll node,ll start,ll en){
  if(start==en){
    tree1[node]=ar1[start];}
  else{
    ll mid=(start+en)/2;
    build1(2*node+1,start,mid);
    build1(2*node+2,mid+1,en);
    tree1[node]=tree1[2*node+1]+tree1[2*node+2];
  }
}
void updatelazy1(ll node,ll start,ll en,ll l,ll r,ll val){
  if(lazy1[node]!=0){
    tree1[node]+=(en-start+1)*lazy1[node];
    if(start!=en){
      lazy1[2*node+1]+=lazy1[node];
      lazy1[2*node+2]+=lazy1[node];
    }
    lazy1[node]=0;
  }
  if(start>r||en<l||start>en) return;
  if(start>=l&&en<=r){
    tree1[node]+=(en-start+1)*val;
    if(start!=en){
      lazy1[2*node+1]+=val;
      lazy1[2*node+2]+=val;
    }
    return;
  }
  ll mid=(start+en)/2;
  updatelazy1(2*node+1,start,mid,l,r,val);
  updatelazy1(2*node+2,mid+1,en,l,r,val);
  tree1[node]=tree1[2*node+1]+tree1[2*node+2];
}
ll querylazy1(ll node,ll start,ll en,ll l,ll r){
  if(lazy1[node]!=0){
    tree1[node]+=(en-start+1)*lazy1[node];
    if(start!=en){
      lazy1[2*node+1]+=lazy1[node];
      lazy1[2*node+2]+=lazy1[node];
    }
    lazy1[node]=0;
  }
  if(start>r||en<l||start>en) return 0;
  if(start>=l&&en<=r) return tree1[node];
  ll mid=(start+en)/2;
  ll p1=querylazy1(2*node+1,start,mid,l,r);
  ll p2=querylazy1(2*node+2,mid+1,en,l,r);
  return p1+p2;
}