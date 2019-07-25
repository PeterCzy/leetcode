int expand(char* s, int l, int r){
    int left = l, right = r;
    while(left >= 0 && right < strlen(s) && s[left] == s[right]){
        left--;
        right++;
    }
    
    return right - left - 1;
}


char * longestPalindrome(char * s){
    int len = strlen(s);
    int tail = 0, head = 0, maxlen = 0;
    
    for(int i = 0; i < len; i++){
        int odd = expand(s, i, i);
        int even = expand(s, i, i + 1);
        int strlen = fmax(odd, even);
        if(strlen > head - tail){
            tail = i - (strlen - 1)/2;
            head = i + strlen/2;
            maxlen = strlen;
        }
    }
    
    char* ret = (char*)calloc(maxlen + 1, sizeof(char));
    strncpy(ret, s + tail, maxlen);
    
    return ret;
}
