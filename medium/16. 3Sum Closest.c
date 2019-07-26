int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    int mindiff = INT_MAX, diff;
    int sum = 0;
    
    for(int i = 0; i < numsSize - 2; i++){
        int tail = i + 1;
        int head = numsSize - 1;
        
        while(tail < head){
            diff = nums[i] + nums[tail] + nums[head] - target;
            if(abs(diff) < mindiff){
                mindiff = abs(diff);
                sum = nums[i] + nums[tail] + nums[head];
            }
            
            if(diff > 0)
                head--;
            else if(diff < 0)
                tail++;
            else if(diff == 0)
                return sum;
        }
    }
    
    return sum;
}
