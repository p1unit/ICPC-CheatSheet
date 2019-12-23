int BIT[MAX];
void update(int idx,int MAX,int val) {
    while (idx <= MAX) {
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int rangeQuery(int x1,int x2){
	return query(x2)-query(x2-1);
}