#include <bits/stdc++.h>
#define ll long long int 
#define MOD 1000000007

using namespace std;

template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v){
    os<<"("<<v.first<<","<<v.second<<")";
    return os;
}
template <typename T> 
ostream& operator<<(ostream& os, const set<T>& v){ 
    os << "debug : ["; 
    for (auto it:v){os << it; 
        if (it != *v.rbegin()) 
            os << ", "; 
    }
    os << "]\n\n"; 
    return os; 
} 
template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "debug : ["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]\n\n"; 
    return os; 
}
template <typename T, typename S> 
ostream& operator<<(ostream& os, const map<T, S>& v) 
{ 
	os << "debug : \n";
    for (auto it : v)  
        os << it.first << " : " 
           << it.second << "\n\n"; 
      
    return os; 
} 
int main(){
	ll t,i,j,k,l,n,m,x,y,a,b,c,r,q;
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// fopen()
	return 0;
}