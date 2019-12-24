// Following are some interesting properties of undirected graphs with an Eulerian path and cycle. We can use these properties to find whether a graph is Eulerian or not.
// Eulerian Cycle
// An undirected graph has Eulerian cycle if following two conditions are true.
// (a) All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
// (b) All vertices have even degree.
// Eulerian Path
// An undirected graph has Eulerian Path if following two conditions are true.
// (a) Same as condition (a) for Eulerian Cycle
// (b) If two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)
// Note that a graph with no edges is considered Eulerian because there are no edges to traverse.
find_tour(u):
  for each edge e=(u,v) in E:
    remove e from E
    find_tour(v)
  prepend u to tour
where u is any vertex with a non-zero degree.


