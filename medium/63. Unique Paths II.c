int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int n = obstacleGridSize;
    int m = *obstacleGridColSize;
    
    long long** path = (long long**)malloc(n * sizeof(long long*));
    for(int i = 0; i < n; i++)
        path[i] = (long long*)malloc(m * sizeof(long long));
    
    int flag = 0;
    for(int i = 0; i < m; i++){
        if(obstacleGrid[0][i] == 1 || flag == 1){
            path[0][i] = 0;
            flag = 1;
        }
        else
            path[0][i] = 1;
    }
    
    flag = 0;
    for(int i = 0; i < n; i++){
        if(obstacleGrid[i][0] == 1 || flag == 1){
            path[i][0] = 0;
            flag = 1;
        }
        else
            path[i][0] = 1;
    }

    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(obstacleGrid[j][i] == 1)
                path[j][i] = 0;
            else
                path[j][i] = path[j - 1][i] + path[j][i - 1];
        }
    }
    
    return path[n - 1][m - 1];
}
