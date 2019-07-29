/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/* not accepted*/

int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void generate(int* nums, int size, int target, int* returnSize, int** returnColumnSizes, int** ret, int* temp, int index){
    if(target < 0)
        return;
    
    if(target == 0){
        ret[*returnSize] = (int*)malloc(index * sizeof(int));
        memcpy(ret[*returnSize], temp, index);
        returnColumnSizes[*returnSize] = (int*)malloc(sizeof(int));
        returnColumnSizes[*returnSize][0] = index;
        (*returnSize)++;
        return;
    }
    
    for(int i = 0; i < size; i++){
        if(nums[i] > target) continue;
        if(nums[i] >= temp[index - 1]){
            temp[index] = nums[i];
            generate(nums, size, target - nums[i], returnSize, returnColumnSizes, ret, temp, index + 1);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), cmpfunc);
    int** ret = (int**)malloc(sizeof(int*));
    int* temp = (int*)malloc(target * sizeof(int));
    *returnColumnSizes = (int*)malloc(500 * sizeof(int));
    *returnSize = 0;
    
    generate(candidates, candidatesSize, target, returnSize, **returnColumnSizes, ret, temp, 0);
    return ret;
}
