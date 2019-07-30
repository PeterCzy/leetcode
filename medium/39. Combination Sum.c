/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void helper(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes, int** ret, int* temp, int index){
    if(target < 0)
        return;
    
    else if(target == 0){
        ret[*returnSize] = (int*)malloc(index*sizeof(int));
        memcpy(ret[*returnSize], temp, index*sizeof(int));
        (*returnColumnSizes)[*returnSize] = index;
        (*returnSize)++;
        return;
    }
    
    else{
        for(int i = 0; i < numsSize; i++){
            if(nums[i] > target)
                continue;
            else{
                if(index > 0 && nums[i] < temp[index - 1])
                    continue;
                
                temp[index] = nums[i];
                helper(nums, numsSize, target - nums[i], returnSize, returnColumnSizes, ret, temp, index + 1);
            }
        }
    }
}


int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates, candidatesSize, sizeof(int), cmpfunc);
    int** ret = (int**)malloc(10000 * sizeof(int*));
    int* temp = (int*)calloc(target + 1, sizeof(int));
    *returnSize = 0;
    (*returnColumnSizes) = (int*)malloc(10000 * sizeof(int));

    helper(candidates, candidatesSize, target, returnSize, returnColumnSizes, ret, temp, 0);
    
    return ret;
}
