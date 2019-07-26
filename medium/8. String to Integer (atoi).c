int myAtoi(char * str){
    int numsign = 0, len, num;
    long long ret = 0;
    
    while(str[0] == ' '){
        str++;
    }
    
    if(str[0] == '-' || str[0] == '+'){
        numsign = str[0] == '-' ? 1 : 0;
        str++;
    }
    else if(str[0] - '0' < 0 || str[0] - '0' > 9)
        return 0;
    
    len = strlen(str);
    
    for(int i = 0; i < len; i++){
        if(str[i] - '0' < 0 || str[i] - '0' > 9)
            return numsign == 0 ? ret : -ret;
        
        num = str[i] - '0';
        ret = ret*10 + num;
        
        if(ret > INT_MAX)
            return numsign == 0 ? INT_MAX : INT_MIN;
    }

    return numsign == 0 ? ret : -ret;
}
