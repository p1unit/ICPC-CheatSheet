ll trie[100005][26],finish[100005],nodeweight[100005];
ll nxt=1;
void add(string s,ll weight){
ll node=0;ll i,j,k;
for(i=0;i<s.length();i++){
    if(trie[node][s[i]-'a']==0){
        trie[node][s[i]-'a']=nxt;
        node=nxt;
        nxt++;
    }else{
        node=trie[node][s[i]-'a'];
    }
    if(nodeweight[node]<weight){
        nodeweight[node]=weight;
    }
    finish[nxt-1]=1;
    }
}
void findd(string s){
ll node=0;ll i,j;
for(i=0;i<s.length();i++){
    if(trie[node][s[i]-'a']==0){
    cout<<"-1\n";return ;}
    node=trie[node][s[i]-'a'];
}
    cout<<nodeweight[node]<<"\n";
}
