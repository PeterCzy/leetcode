/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmpfunc(const void* a, const void* b){
    return ((int**)a)[0][0]-((int**)b)[0][0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    qsort(intervals, intervalsSize, sizeof(*intervals), cmpfunc);
    
    int** ret;
    *returnSize = 0;
    
    for(int i = 0; i < intervalsSize; i++){
        if(i == 0){
            *returnColumnSizes = (int*)malloc((*returnSize + 1) * sizeof(int));
            (*returnColumnSizes)[*returnSize] = 2;

            ret = (int**)malloc((*returnSize + 1) * sizeof(int*));
            ret[*returnSize] = (int*)malloc(2 * sizeof(int));
            ret[*returnSize][0] = intervals[*returnSize][0];
            ret[*returnSize][1] = intervals[*returnSize][1];
            (*returnSize)++;
        }
        
        
        if(intervals[i][0] <= ret[(*returnSize) - 1][1] && intervals[i][1] > ret[(*returnSize) - 1][1]){
            ret[(*returnSize) - 1][1] = intervals[i][1];
        }
        else if(intervals[i][0] > ret[(*returnSize) - 1][1]){
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
            (*returnColumnSizes)[*returnSize] = 2;
            
            ret = (int**)realloc(ret, (*returnSize + 1) * sizeof(int*));
            ret[*returnSize] = (int*)malloc(2 * sizeof(int));
            ret[*returnSize][0] = intervals[i][0];
            ret[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        }
    }
    
    return ret;
    
}
