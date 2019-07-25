int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    int i, j, temp = 0, ret = 0;    
    int map[128];
    memset(map, -1, 128 * sizeof(int));
    
    for(i = 0, j = 0; i < len; i++){        
        int id = s[i] % 128;
        
        if(map[id] < j){
            map[id] = i;
            temp = i - j + 1;
        }
        else{
            j = map[id] + 1;
            map[id] = i;
        }
        
        if(temp > ret) ret = temp;
    }
    
    return ret;
}
