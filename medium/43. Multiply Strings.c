char * multiply(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxlen = len1 + len2;
    int* table = (int*)malloc(maxlen * sizeof(int));
    memset(table, 0, sizeof(int) * maxlen);
    int* carry = (int*)malloc((maxlen + 1) * sizeof(int));
    memset(carry, 0, sizeof(int) * (maxlen + 1));
    char* ret = (char*)malloc((maxlen + 1) * sizeof(char));
    int valid = 0;
    
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            int val1 = num1[len1 - 1 - i] - '0';
            int val2 = num2[len2 - 1 - j] - '0';
            
            int val = val1*val2;
            
            table[i + j] += val%10;
            carry[i + j + 1] += val/10;
            
            if(table[i + j] != 0 || carry[i + j + 1] != 0)
                valid = 1;
        }
    }
    
    if(valid == 0)
        return "0";

    for(int i = 0; i < maxlen; i++){
        int val = table[i] + carry[i];
        ret[maxlen - 1 - i] = '0' + val%10;
        carry[i + 1] += val/10;
    }
    ret[maxlen] = '\0';
    
    while(ret[0] == '0')
        ret = ret + 1;
   
    return ret;
}
