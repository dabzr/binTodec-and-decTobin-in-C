#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binaryToDecimal(char *bin) {
  int j, dec = 0;
  for (int i=strlen(bin), j = 0;i>=0;i--, j++)
    if (bin[i] == '1') dec += (1 << (j-1));

  return dec;
}

char * decimalToBinary(int dec) {
    char *bin = malloc(sizeof(int)*8);
    char tempchar[2];
    while (1) {
        if (dec == 1) {
            strcat(bin, "1");
            break;
        }
        sprintf(tempchar, "%d", dec%2);
        strcat(bin, tempchar);
        dec >>= 1;
    }
    char *tmp = malloc(strlen(bin));
    for (int i = 0; i < strlen(bin); i++)
      tmp[i] = bin[strlen(bin)-i-1];
    strcpy(bin, tmp);
    free(tmp);
    return bin;
}
int main (){
    printf("%d\n", binaryToDecimal("100000"));
    printf("%s\n", decimalToBinary(127));
}
