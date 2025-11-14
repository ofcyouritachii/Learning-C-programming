#include <stdio.h>

int main() {
    char operator;
    double num, num2;

    printf("Simple Calculator in C\n");
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num, &num2);
    switch(operator) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", num, num2, num + num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", num, num2, num - num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf\n", num, num2, num * num2);
            break;
        case '/':
		
            if (num2 != 0) {
                printf("%.2lf / %.2lf = %.2lf\n", num, num2, num / num2);
            } else {
                printf("Error! Division by zero.\n");
            }
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }
    return 0;
}
