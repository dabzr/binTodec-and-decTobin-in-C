#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int binaryToDecimal(char *bin){
    int i, j, dec =0;
    char num[3] = "01";
    for (i=strlen(bin);i>=0;i--){
        if (bin[i] == num[1]){
            dec = dec + (pow(2, j-1));}
        j++;
    }
    return dec;
}

char * decimalToBinary(int dec){
    int i = 0;
    char *bin = malloc(sizeof(dec));
    char one[2] = "1";
    char tempchar[50];
    while (i==0){
        if (dec == 1){
            strcat(bin, one);
            break;
        }
        sprintf(tempchar, "%d", dec%2);
        strcat(bin, tempchar);
        dec = dec / 2;
    }
    size_t size = strlen(bin);
    for(int i = 0; i < size / 2; i++) {
       char tmp = bin[i];
       bin[i] = bin[size - i - 1];
       bin[size - i - 1] = tmp;
    }
    return bin;
}
int main (){
    printf("%d\n", binaryToDecimal("100000"));
    printf("%s\n", decimalToBinary(14));
}