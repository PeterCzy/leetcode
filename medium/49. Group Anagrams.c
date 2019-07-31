/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmpfunc(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){

    char** sortstrs = (char**)malloc(strsSize*sizeof(char*));
    for(int i = 0; i < strsSize; i++){
        sortstrs[i] = (char*)malloc((strlen(strs[i]) + 1)*sizeof(char));
        strcpy(sortstrs[i], strs[i]);    
    }
    
    int* label = (int*)malloc(strsSize*sizeof(int));
    memset(label, 0, strsSize*sizeof(int));
    
    for(int i = 0; i < strsSize; i++){
        qsort(sortstrs[i], strlen(sortstrs[i]), sizeof(char), cmpfunc);
    }
    
    int labelid = 1;
    for(int i = 0; i < strsSize; i++){
        if(label[i] == 0){
            label[i] = labelid;
            labelid++;
            
            for(int j = i; j < strsSize; j++){
                if(j > i && label[j] == 0){
                    if(strcmp(sortstrs[i], sortstrs[j]) == 0){
                        label[j] = label[i];
                    }
                }
            }
        }
    }
    
    *returnSize = labelid - 1;
    
    char*** ret = (char***)malloc((*returnSize)*sizeof(char**));
    *returnColumnSizes = (int*)malloc((*returnSize)*sizeof(int));
    for(int i = 0; i < (*returnSize); i++){
        ret[i] = (char**)malloc(1000*sizeof(char*));
        (*returnColumnSizes)[i] = 0;
    }

    
   
    for(int i = 0; i < strsSize; i++){
        int id = label[i] - 1;
        
        ret[id][(*returnColumnSizes)[id]] = (char*)malloc((strlen(strs[i]) + 1)*sizeof(char));
        strcpy(ret[id][(*returnColumnSizes)[id]], strs[i]);
        (*returnColumnSizes)[id]++;
    }
   
    return ret;

}
