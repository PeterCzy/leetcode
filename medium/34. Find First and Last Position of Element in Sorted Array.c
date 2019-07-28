/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binarysearch(int* a, int l, int r, int key, int left){
	while(l < r){
        int mid = (l + r) >> 1;
        if(a[mid] > key || (left && a[mid] == key))
            r = mid;
        else
            l = mid + 1;
    }
    
    return l;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* ret = (int*)malloc(2 * sizeof(int));
    ret[0] = -1;
    ret[1] = -1;
    *returnSize = 2;
    
    int l = 0, r = numsSize - 1;
    int leftid = binarysearch(nums, l, r, target, 1);
    
    if(leftid == numsSize || nums[leftid] != target)
        return ret;
    
    ret[0] = leftid;
    if(nums[numsSize - 1] == target)
        ret[1] = numsSize - 1;
    else
        ret[1] = binarysearch(nums, l, r, target, 0) - 1;
    
    return ret;
}
