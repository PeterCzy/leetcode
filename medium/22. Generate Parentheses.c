/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void function(char** ret, char* temp, int l, int r, int* size, int index){
    
    if(l == 0 && r == 0){
        temp[index] = '\0';
        ret[*size] = (char*)malloc((index + 1) * sizeof(char));
        strcpy(ret[*size], temp);
        (*size)++;
        return;
    }
    if(l > 0){
        temp[index] = '(';
        function(ret, temp, l - 1, r, size, index + 1);
    }
    if(r > 0 && l < r){
        temp[index] = ')';
        function(ret, temp, l, r - 1, size, index + 1);
    }
}

char ** generateParenthesis(int n, int* returnSize){
    int seq = 0, sum = 0, size = 0;
    char** ret = (char**)malloc(100000 * sizeof(char*));
    char* temp = (char*)calloc(2*n + 1, sizeof(char));
    int l = n, r = n, index = 0;
    
    *returnSize = 0;
    function(ret, temp, l, r, returnSize, index);
    return ret;
}
