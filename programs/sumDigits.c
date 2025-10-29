#include <stdio.h>

int main() {
    int a , num, n, sum=0;
    printf("Enter a 5 digit number: ");
    scanf("%d", &num);
    a = num%10;
    n = num/10;
    sum = sum+a;
    a = n%10;
    n = n/10;
    sum = sum+a;
    a = n%10;
    n = n/10;
    sum = sum+a;
    a = n%10;
    n = n/10;
    sum = sum+a;
    a=n%10;
    sum = sum+a;
    printf("Sum of 5 digit %d=%d", num, sum);
    
    return 0;
}
