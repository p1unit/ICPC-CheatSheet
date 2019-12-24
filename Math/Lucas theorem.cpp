//Computes C(N,R) modulo P in O(log(n)) time.
LL Lucas(LL N,LL R,int P)
{
	if(R<0||R>N) return 0;	
	if(R==0||R==N) return 1;
	if(N>=P) return (Lucas(N/P,R/P,P)*Lucas(N%P,R%P,P))%P;
	return (Fact[N]*(Invfact[N-R]*Invfact[R])%P)%P;
} 
