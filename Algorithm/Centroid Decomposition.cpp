int getCentroid(int src, bool visited[], int subtree_size[], int n){ 
/* assume the current node to be centroid */
bool is_centroid = true; 
/* mark it as visited */
visited[src] = true; 
/* track heaviest child of node, to use in case node is  not centroid */
int heaviest_child = 0; 
vector<int>::iterator it; 
/* iterate over all adjacent nodes which are children  
(not visited) and not marked as centroid to some  
subtree */
for (it = tree[src].begin(); it!=tree[src].end(); it++) 
  if (!visited[*it] && !centroidMarked[*it]){ 
  /* If any adjacent node has more than n/2 nodes, 
  * current node cannot be centroid */
  if (subtree_size[*it]>n/2) 
    is_centroid=false; 

/* update heaviest child */
  if (heaviest_child==0 || 
  subtree_size[*it]>subtree_size[heaviest_child]) 
  heaviest_child = *it; 
} 
/* if current node is a centroid */
if (is_centroid && n-subtree_size[src]<=n/2) 
return src; 
/* else recur on heaviest child */
return getCentroid(heaviest_child, visited, subtree_size, n); 
}