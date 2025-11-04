#include<stdio.h>
int main(){
    int m1, m2, m3, m4, m5, aggr;
    float per;
    printf("Enter marks for 1st subject: ");
    scanf("%d", &m1);
    printf("Enter marks for 2nd subject: ");
    scanf("%d", &m2);
    printf("Enter marks for 3rd subject: ");
    scanf("%d", &m3);
    printf("Enter marks for 4th subject: ");
    scanf("%d", &m4);
    printf("Enter marks for 5th subject: ");
    scanf("%d", &m5);
    aggr=m1+m2+m3+m4+m5;
    per=aggr/5;
    printf("\n\nAggregate Marks = %d", aggr);
    printf("\nPercentage Marks = %f", per);
    return 0;
    
    
}