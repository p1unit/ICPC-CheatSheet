void mul(lo g[2][2],lo h[2][2]){
    lo u=(g[0][0]*h[0][0])%mm+(g[0][1]*h[1][0])%mm;
    lo v=(g[0][0]*h[0][1])%mm+(g[0][1]*h[1][1])%mm;
    lo w=(g[1][0]*h[0][0])%mm+(g[1][1]*h[1][0])%mm;
    lo x=(g[1][0]*h[0][1])%mm+(g[1][1]*h[1][1])%mm;
    g[0][0]=u%mm;g[0][1]=v%mm;
    g[1][0]=w%mm;g[1][1]=x%mm;}
void pr(lo g[2][2],lo n,lo p){
    if(n==0||n==1){ 
	 return;}
    lo h[2][2]={{p,-1+mm},{1,0}};
    pr(g,n/2,p);mul(g,g);
    if(n%2!=0){
        mul(g,h);}}
