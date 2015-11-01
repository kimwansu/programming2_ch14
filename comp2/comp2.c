#include <stdio.h>
#include <stdlib.h>

double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double divide(double a, double b);

int main(int argc, char** argv)
{
    double a;
    double b;
    double c;
    char op;

    double (*pf)(double, double) = NULL;

    if (argc < 4)
    {
        printf("사용법: %s 수1 수2 연산자\n", argv[0]);
        return 1;
    }

    a = atof(argv[1]);
    b = atof(argv[2]);
    op = argv[3][0];

    switch (op)
    {
    case '+':
        pf = add;
        break;
    case '-':
        pf = sub;
        break;
    case '*':
        pf = mul;
        break;
    case '/':
        pf = div;
        break;
    default:
        printf("연산자는 '+', '-', '*', '/'만 사용 가능\n");
        return 1;
    }

    c = pf(a, b);

    //printf("계산 결과: %lf %c %lf = %lf\n", a, op, b, c);
    printf("%lf\n", c);

    return 0;
}

double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

double mul(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
    {
        printf("0으로 나눌 수 없습니다.\n");
        exit(1);
    }
    return a / b;
}
