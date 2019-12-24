void build(int id = ir,int l = 0,int r = n){
	s[id] = 0;
	if(r - l < 2)
		return ;
	int mid = (l+r)/2;
	L[id] = NEXT_FREE_INDEX ++;
	R[id] = NEXT_FREE_INDEX ++;
	build(L[id], l, mid);
	build(R[id], mid, r);
	s[id] = s[L[id]] + s[R[id]];
}
// Update function :
int upd(int p, int v,int id,int l = 0,int r = n){
	int ID =  NEXT_FREE_INDEX ++; // index of the node in new version of segment tree
	s[ID] = s[id] + 1;
	if(r - l < 2)
		return ID;
	int mid = (l+r)/2;
	L[ID] = L[id], R[ID] = R[id]; // in case of not updating the interval of left child or right child
	if(p < mid)
		L[ID] = upd(p, v, L[ID], l, mid);
	else
		R[ID] = upd(p, v, R[ID], mid, r);
	return ID;
}
// Ask function (it returns i, so you should print api :4
int ask(int id, int ID, int k, int l = 0,int r = n){// id is the index of the node after l-1-th update (or ir) and ID will be its index after r-th update
	if(r - l < 2)	return l;
	int mid = (l+r)/2;
	if(s[L[ID]] - s[L[id]] >= k)// answer is in the left child's interval
		return ask(L[id], L[ID], k, l, mid);
	else
		return ask(R[id], R[ID], k - (s[L[ID]] - s[L[id]] ), mid, r);// there are already s[L[ID]] - s[L[id]] 1s in the left child's interval
}