public class MOs {
  long ans=0L;
  long[] freq=new long[1000001]; 
  public void solve() {
    int n=in.ni(),q=in.ni();
    int[] arr=in.intarr(n);
    ArrayList<Query> list=new ArrayList<>();
    for(int i=0;i<q;++i)list.add(new Query(in.ni()-1,in.ni()-1,i));
    int sq=(int)Math.sqrt(n);
    list.sort((q1,q2)->{
      if(q1.l/sq==q2.l/sq)
        return q1.r/sq-q2.r/sq;
      return q1.l/sq-q2.l/sq;
    });
    long[] ans_arr=new long[q];
    Arrays.fill(ans_arr,-1);
    int l=0,r=-1;
    for(int i=0;i<q;++i){
      Query query=list.get(i);
      while (l < query.l) remove(arr[l++]);
      while (l > query.l) add(arr[--l]);
      while (r < query.r) add(arr[++r]);
      while (r > query.r) remove(arr[r--]);
      ans_arr[query.idx]=ans;
    }
    for(int i=0;i<q;++i)
      if(ans_arr[i]!=-1)
        out.println(ans_arr[i]);
  }
  void add(int num){
    ans += (long) (num ) * (((freq[num]++)<<1L) + 1L);
  }
  void remove(int num){
    ans -= (long) (num) * (((freq[num]--)<<1L) - 1L);
  }
  class Query{
    int l,r,idx;long ans;
    public Query(int l, int r, int idx) {
      this.l = l;
      this.r = r;
      this.idx = idx;
    }
  }
}