#include<stdio.h>
int main(){
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("Character: %c\tASCII value: %d\n", c, c);
    return 0;
}