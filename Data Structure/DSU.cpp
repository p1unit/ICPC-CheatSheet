class dsu
{   vector<int> A,size; 
    int U,V;
    public:
	dsu(int n)
	{
		A.resize(n+1);
		for(int i = 1; i <= n; i++)
		{
			A[i] = i;
		}
		size.resize(n+1,1);
	}
	int root(int i)
	{   
		while(A[i]!=i)
			i = A[i];
		return i;
	}
	int uniona(int u, int v)
	{
		U = root(u);
		V = root(v);
		if(U == V)
			return 0;
		if(size[U] > size[V])
		{
			A[V] = U;
			size[U] += size[V];
		}
		else
		{
			A[U] = V;
			size[V] += size[U];
		
		}
		return 1;
	}
};