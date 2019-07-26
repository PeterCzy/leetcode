int maxArea(int* height, int heightSize){
    int maxarea = 0;
    
    for(int i = 0, j = heightSize - 1; i != j; ){
        int bound = height[i] > height[j] ? height[j] : height[i];
        int area = bound*(j - i);
        maxarea = area > maxarea ? area : maxarea;
        
        if(height[i] < height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    
    return maxarea;
}
