#include <stdio.h>
int main(){
    float  angle1, angle2, angle3;
    printf("Enter the 1st angle of the triangle: ");
    scanf("%f", &angle1);
    printf("Enter the 2nd angle of the triangle: ");
    scanf("%f", &angle2);
    printf("Enter the 3rd angle of the triangle: ");
    scanf("%f", &angle3);

    if(angle1 + angle2 + angle3 == 180){
        printf("The angles form a valid triangle.\n");
    } else {
        printf("The angles do not form a valid triangle.\n");
    }

    return 0;
}