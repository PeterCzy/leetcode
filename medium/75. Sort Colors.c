void sortColors(int* nums, int numsSize){
    int temp, id, min = INT_MAX;
    
    
    for(int i = 0; i < numsSize; i++){
        for(int j = i; j < numsSize; j++){
            if(nums[j] < min){
                min = nums[j];
                id = j;
            }
        }
        
        temp = nums[i];
        nums[i] = min;
        nums[id] = temp;
        min = INT_MAX;
    }
}
