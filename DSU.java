class DSU{
    private  int[] par;
    private  int[] size;
    public Dsu(int len){
        par=new int[len+1];
        size=new int[len+1];
        for(int i=0;i<len;++i){
            par[i]=i;
            size[i]=1;
        }
    }
    public int getParent(int u){
        if(par[u]==u)
            return u;
        return par[u]=getParent(par[u]);
    }

    public void merge(int u,int v){
        u=getParent(u);
        v=getParent(v);
        if(u!=v){
            if(size[u]<size[v]){
                int t=u;u=v;v=t;
            }
            par[v]=u;
            size[u]+=size[v];
        }
    }
}
