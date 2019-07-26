char * intToRoman(int num){
    char *chM[] = {"","M","MM","MMM"};
    char *chC[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char *chX[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char *chI[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    int step[] = {0,1,2,3,2,1,2,3,4,2};

    int temp = num;
    int m = temp/1000;
    temp = temp%1000;
    
    int c = temp/100;
    temp = temp%100;
    
    int x = temp/10;
    int i = temp%10;
    
    int len = strlen(chM[m]) + strlen(chC[c]) + strlen(chX[x]) + strlen(chI[i]);
    
    char* ret = (char*)malloc((len + 1) * sizeof(char));
    
    if(m != 0){
        strcpy(ret, chM[m]);
        strcat(ret, chC[c]);
        strcat(ret, chX[x]);
        strcat(ret, chI[i]);
    }
    else{
        if(c != 0){
            strcpy(ret, chC[c]);
            strcat(ret, chX[x]);
            strcat(ret, chI[i]);
        }
        else{
            if(x != 0){
                strcpy(ret, chX[x]);
                strcat(ret, chI[i]);
            }
            else{
                strcpy(ret, chI[i]);
            }
        }
    }
    
    return ret;
}
