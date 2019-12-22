class SqrtDecomposition {
    public void solve() {
        int n=in.ni();
        int[] arr=in.intarr(n);
        int BUCKET_SIZE=(int)Math.sqrt(n*1.0)+1;
        int[][] preArr=new int[BUCKET_SIZE][BUCKET_SIZE];

        for(int i=0;i<n;++i){
            preArr[i/BUCKET_SIZE][i%BUCKET_SIZE]=arr[i];
        }
        for(int i=0;i<BUCKET_SIZE;++i){
            sort(preArr[i]);
        }
        int q=in.ni();
        while (q-->0){
            int t=in.ni();
            int ans=0;
            if(t==0){
                int l=in.ni()-1,r=in.ni()-1,c=in.ni();
                int BL=l/BUCKET_SIZE,BR=r/BUCKET_SIZE;
                if(BL==BR){
                    for(int i=l;i<=r;++i){
                        if(arr[i]>=c)
                            ++ans;
                    }
                }else {
                    int end=(BL+1)*BUCKET_SIZE-1;
                    for(int i=l;i<=Math.min(end,n-1);++i){
                        if(arr[i]>=c)
                            ++ans;
                    }
                    for(int i=BL+1;i<BR;++i){
                        ans+=lowerBound(preArr[i],0,BUCKET_SIZE,c);
                    }
                    for(int i=BR*BUCKET_SIZE;i<=r;++i){
                        if(arr[i]>=c)
                            ++ans;
                    }
                }
                out.println(ans);
            }else {
                int idx=in.ni()-1,val=in.ni();
                int B=idx/BUCKET_SIZE;
                for(int i=0;i<BUCKET_SIZE;++i){
                    if(preArr[B][i]==arr[idx]){
                        preArr[B][i]=val;
                        break;
                    }
                }
                sort(preArr[B]);
                arr[idx]=val;
            }

        }

    }
}