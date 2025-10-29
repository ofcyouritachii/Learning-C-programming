#include <stdio.h>

int main() {
    float angle1, angle2, angle3;
    printf("Enter The 1st value for Angle1:");
    scanf("%f", &angle1);
    printf("Enter The 2nd value for Angle2:");
    scanf("%f", &angle2);
    printf("Enter The 3rd value for Angle3:");
    scanf("%f", &angle3);
    if((angle1+angle2+angle3)==180)
    printf("The triangle has valid angles");
    else
    printf("The triangle has invalid angles");
    return 0;
}
