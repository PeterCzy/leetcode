
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize == 0 || (*matrixColSize == 0)){
        *returnSize = 0;
        return NULL;
    }
    
    int id = 0;
    *returnSize = matrixSize * (*matrixColSize);
    int* ret = (int*)malloc((*returnSize) * sizeof(int));
    int rmin = 0, rmax = matrixSize - 1;
    int cmin = 0, cmax = (*matrixColSize) - 1;
    
    while(id < *returnSize){
        for(int c = cmin; c <= cmax; c++) //from left to right including the last;
            ret[id++] = matrix[rmin][c];
        
        if(id == *returnSize) break; //only one row;
        
        for(int r = rmin+1; r <= rmax; r++) //from top to bottom including the last;
            ret[id++] = matrix[r][cmax];
        
        if(id == *returnSize) break; //only one column;
        
        for(int c = cmax-1; c >= cmin; c--) //from right to left including the last;
            ret[id++] = matrix[rmax][c];
        
        for(int r = rmax-1; r > rmin; r--) //from bottom to top excluding the last;
            ret[id++] = matrix[r][cmin];
        
        rmin++; rmax--; cmin++; cmax--;
    }
    
    return ret;
}
