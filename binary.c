#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binaryToDecimal(char *bin){
    int i, j, dec =0;
    char num[2] = "1";
    for (i=strlen(bin);i>=0;i--){
        if (bin[i] == num[0])
            dec = dec + (1 << (j-1));
        j++;
    }
    return dec;
}

char * decimalToBinary(int dec){
    char *bin = malloc(sizeof(double));
    char tempchar[2];
    while (1){
        if (dec == 1){
            strcat(bin, "1");
            break;
        }
        sprintf(tempchar, "%d", dec%2);
        strcat(bin, tempchar);
        dec /= 2;
    }
    char *tmp = malloc(sizeof(char) * strlen(bin));
    for (int i = 0; i <= strlen(bin); i++)
      tmp[i] = bin[strlen(bin)-i-1];
    strcpy(bin, tmp);
    free(tmp);
    return bin;
}
int main (){
    printf("%d\n", binaryToDecimal("100000"));
    printf("%s\n", decimalToBinary(127));
}
