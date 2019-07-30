/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void helper(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int*** ret, int* temp, int* table, int index){
    if(index == numsSize){
        (*ret) = (int**)realloc((*ret), (*returnSize + 1)*sizeof(int*));
        (*ret)[*returnSize] = (int*)malloc(numsSize*sizeof(int));
        memcpy((*ret)[*returnSize], temp, numsSize*sizeof(int));
        
        (*returnColumnSizes) = (int*)realloc((*returnColumnSizes), (*returnSize + 1)*sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        
        (*returnSize)++;
        
        return;
    }
    else{
        for(int i = 0; i < numsSize; i++){
            
            if(table[i] == 0){
                temp[index] = nums[i];
                table[i] = 1;
                helper(nums, numsSize, returnSize, returnColumnSizes, ret, temp, table, index + 1);
                
                table[i] = 0;
            }  
        }
    }
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** ret = (int**)malloc(sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(sizeof(int));
    
    int* temp = (int*)malloc(numsSize*sizeof(int));
    
    int* table = (int*)malloc(numsSize*sizeof(int));
    memset(table, 0, numsSize*sizeof(int));
    
    *returnSize = 0;
    int index = 0;
    
    helper(nums, numsSize, returnSize, returnColumnSizes, &ret, temp, table, index);
    
    return ret;
}
