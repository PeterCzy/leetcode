int minPathSum(int** grid, int gridSize, int* gridColSize){
    int n = gridSize;
    int m = *gridColSize;
    
    int** path = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        path[i] = (int*)malloc(m * sizeof(int));
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            path[j][i] = grid[j][i];
        }
    }
    
    for(int i = 1; i < m; i++)
        path[0][i] += path[0][i - 1];
    
    for(int i = 1; i < n; i++)
        path[i][0] += path[i - 1][0];
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            int min = path[j - 1][i] > path[j][i - 1] ? path[j][i - 1] : path[j - 1][i];
            path[j][i] += min;
        }
    }
    
    return path[n - 1][m - 1];
    
}
