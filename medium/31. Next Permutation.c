int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int closestbigger(int* array, int size, int target){
    int mindiff = INT_MAX, id;
    for(int i = 0; i < size; i++){
        int diff = array[i] - target;
        if(diff > 0 && diff < mindiff){
            mindiff = diff;
            id = i;
        }
    }
    return id;
}

void nextPermutation(int* nums, int numsSize){
    if(numsSize == 1) return;
    
    int id = 0, flag = 0;
    int* array = (int*)malloc(numsSize * sizeof(int));
    memset(array, 0, sizeof(array));
    
    int pos = numsSize - 1;
    while(pos > 0){
        array[id] = nums[pos];
        id++;
        if(nums[pos - 1] < nums[pos]){
            pos--;
            flag = 1;
            break;
        }
        else{
            pos--;
        }
    }
    
    if(flag == 0){
        qsort(nums, numsSize, sizeof(int), cmpfunc);
    }
    else{
        int tid = closestbigger(array, id, nums[pos]);
        int temp = array[tid];
        array[tid] = nums[pos];
        nums[pos] = temp;
        qsort(array, numsSize, sizeof(int), cmpfunc);
        memcpy(nums + numsSize - id, array + numsSize - id, sizeof(int) * id);
    }
    
    return;
}
