ll x,y,d;
void extende(ll a,ll b){
if(b==0){
    d=a;x=1;y=0;
}else{
extende(b,a%b);
ll temp=x;
x=y;
y=temp-(a/b)*y;}}
int main(){
   ll t,i,j,k,m,n;
   extende(16,10);
   cout<<d<<"\n";
   cout<<x<<" "<<y;
    return 0;}
