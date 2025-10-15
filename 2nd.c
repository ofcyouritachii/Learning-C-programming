#include <stdio.h>

int main() {
    int choice;
    float temp, converted;
    printf("Temperature Conversion Program
");
    printf("1. Celsius to Fahrenheit
");
    printf("2. Fahrenheit to Celsius
");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);
        converted = (temp * 9 / 5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit
", temp, converted);
    } else if(choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temp);
        converted = (temp - 32) * 5 / 9;
        printf("%.2f Fahrenheit = %.2f Celsius
", temp, converted);
    } else {
        printf("Invalid choice. Please restart the program.
");
    }

    return 0;
}