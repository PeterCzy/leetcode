bool canJump(int* nums, int numsSize){
    int pos = 0;
    
	for (int i = 0; i < numsSize && i <= pos; i++){
        pos = pos > i + nums[i] ? pos : i + nums[i];
        
		if (pos >= numsSize - 1)
			return true;
    }

	return false;
}
