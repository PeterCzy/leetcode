int cmpfunc(const void* a, const void* b){
    return * (int*)a - * (int*)b;
}

int binarysearch(int *a, int l, int r, int key)
{
	while(l <= r) {
		int mid = l + ((r - l) >> 1);
		if(a[mid] == key)
			return mid;
		else if(a[mid] > key)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int search(int* nums, int numsSize, int target){
    if(numsSize == 0)
        return -1;
    
    int first = nums[0];
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    
    int l = 0, r = numsSize - 1;
    int sfirstid = binarysearch(nums, l, r, first);
    int stargetid = binarysearch(nums, l, r, target);
    
    if(stargetid == -1)
        return -1;
    
    int diff = sfirstid;
    return (numsSize + stargetid - diff)%numsSize;
}
