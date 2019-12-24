for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );}}}
for (int i = 0; i < V; i++) 
        if (dist[i][i] < 0) 
            return true; 
    return false;  