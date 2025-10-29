#include <stdio.h>

int main() {
    int no;
    printf("Enter any number: ");
    scanf("%d",&no);
    if(no<0)
    no = no* -1;
    printf("the absolute number is : %d",no);
    return 0;
}
