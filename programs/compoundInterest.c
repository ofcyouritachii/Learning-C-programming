#include <stdio.h>
#include <math.h>

int main1()
{
    double principal = 10000;
    double rate = 5;
    double time = 2;

    double amount = principal * pow((1 + rate / 100), time);
    double ci = amount - principal;

    printf("Compound Interest is: %lf\n", ci);

    return 0;
}

int main()
{
    main1();
    return 0;
}
