void build(int idx, int ss, int se, 
    vector<int> a[], vector<int> sTree[]){ 
    if (ss == se) { 
        sTree[idx] = a[ss]; 
        return; 
    } 
    int mid = (ss+se)/2; 
    build(2*idx+1, ss, mid, a, sTree); 
    build(2*idx+2, mid+1, se, a, sTree); 
    merge(sTree[2*idx+1].begin(), sTree[2*idx+1].end(), 
          sTree[2*idx+2].begin(), sTree[2*idx+2].end(), 
          back_inserter(sTree[idx])); 
} 
  
int queryRec(int node, int start, int end, int ss, int se, 
         int k, vector<int> a[], vector<int> sTree[]) { 
    if (ss > end || start > se) 
        return 0; 
    if (ss <= start && se >= end) { 
        return upper_bound(sTree[node].begin(), 
                           sTree[node].end(), k) - 
                           sTree[node].begin(); 
    } 
    int mid = (start+end)/2; 
    int p1 = queryRec(2*node+1, start, mid, ss, se, k, a, sTree); 
    int p2 = queryRec(2*node+2, mid+1, end, ss, se, k, a, sTree); 
    return p1 + p2; 
} 