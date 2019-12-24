struct trie{
    trie *children[26];
    bool endofword;
    ll weight;
};
trie *newnode(){
    struct trie *node=new trie();
    for(ll i=0;i<26;i++){
    node->children[i]=NULL;
    }
    nodode->endofword=false;
    node->weight=-1;
    return node;
}
void inser(trie *root,string s,ll weight){
    struct trie *node=new trie();
    node=root;
    for(ll i=0;i<s.length();i++){
        ll ind=s[i]-'a';
        if(!node->children[ind]){
            node->children[ind]=newnode();
        }
        node=node->children[ind];
        if(node->weight<weight){
            node->weight=weight;
        }
        node->endofword=true;
    }
}

void searc(trie *root,string s){
    struct trie *node=new trie();
    node = root;
    for(ll i=0;i<s.length();i++){
        ll ind=s[i]-'a';
        if(!node->children[ind]){
            cout<<"-1\n";
            return;
        }
        node=node->children[ind];
    }
cout<<node->weight<<"\n";
return;}