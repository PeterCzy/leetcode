char * convert(char * s, int numRows){
    int len = strlen(s);
    char* ret = (char*)calloc(len + 1, sizeof(char));
    int period = 2*numRows - 2;
    int id = 0;
    
    if(numRows == 1) return s;
    
    for(int i = 0; i < numRows; i++){
        for(int j = 0; i + j < len; j = j + period){
            ret[id] = s[i + j];
            id++;
            if(i != 0 && i != numRows - 1 && j + period - i < len){
                ret[id] = s[j + period - i];
                id++;
            }
        }
    }
    
    return ret;
}
