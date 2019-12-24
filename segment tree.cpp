long long int sum[10000000]={0},A[3000000]={0};
void SumBuild(ll node,ll l,ll r){
    if(l==r)
    sum[node] = A[l];
    else{
    ll mid = (l+r)/2;
    SumBuild(2*node+1,l,mid);
    SumBuild(2*node+2,mid+1,r);
    sum[node] = sum[2*node+1] +  sum[2*node+2];}}
 
void SumUpdate(ll node,ll l,ll r,ll index,long long int value){
    if(index<l||index>r){
    return;}
    if(l==r){
    sum[node]+=value;
    A[l] +=value;
    }else{
    ll mid = (l+r)/2;
    if(index<=mid){
         SumUpdate(2*node+1,l,mid,index,value);}
   else{
        SumUpdate(2*node+2,mid+1,r,index,value);}
    sum[node] = sum[2*node+1]+sum[2*node+2];}}
long long int SumQuery(ll node,ll ss,ll se,ll l,ll r){
    if(l>=ss&&se>=r){
    return sum[node];
    }
    else if(ss>r||se<l){
    return 0;}
   else{
    ll mid = (l+r)/2;
    return SumQuery(2*node +1,ss,se,l,mid)+SumQuery(2*node+2,ss,se,mid+1,r);}}
 
 