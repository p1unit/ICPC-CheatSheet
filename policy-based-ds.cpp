#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 
int main(){
	new_data_set p; 
	p.insert(8LL);
	*p.find_by_order(3);//element
	p.order_of_key(6);//index
	return 0;
}