void process2(int M[MAXN][LOGMAXN], int A[MAXN], int N){
int i, j; 
//initialize M for the intervals with length 1
for (i = 0; i < N; i++)
	M[i][0] = i;
//compute values from smaller to bigger intervals
for (j = 1; 1 << j <= N; j++)
	for (i = 0; i + (1 << j) - 1 < N; i++)
		if (A[M[i][j-1]] < A[M[i+(1<<(j-1))][j-1]])
			M[i][j] = M[i][j - 1];
		else
			M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
// query
int j = log[R - L + 1];
int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);