bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    if(matrixSize == 0 || (*matrixColSize) == 0)
        return false;
    
    int l = 0, r;
    
    for(int i = 0; i < matrixSize; i++){
        if(matrix[i][0] == target)
            return true;
        else if(matrix[i][0] > target){
            l = i;
            break;
        }
        
        if(i == matrixSize - 1)
            l = matrixSize;
    }
    
    int row = l > 0 ? l - 1: 0;
    
    l = 0; 
    r = (*matrixColSize) - 1;
    
    while(l <= r){
        int mid = (r + l) >> 1;
        if(matrix[row][mid] == target){
            return true;
        }
        else if(matrix[row][mid] > target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    
    return false;
}
