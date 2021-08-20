#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#define EPSILON 0.000001

void quadro(double a, double b, double c, double *x1, double *x2, int *solutionNo)
{
    /* ax^2 + bx + c = 0 - a, b, c - коэф., переданные пользователем*/
    double D;
    if ((a - 0) < EPSILON && (b - 0) > EPSILON && (c - 0) > EPSILON)
    {
            *x1 = -c / b;
            *solutionNo = 1;
    }
    else if ( (a - 0) < EPSILON && (b - 0) < EPSILON && (c - 0) < EPSILON )
    {
            *solutionNo = 3;
    }
    else if ( (a - 0) < EPSILON && (b - 0) < EPSILON && (c - 0) > EPSILON )
    {
            *solutionNo = 0;
    }
    else
    {
        D = b * b - 4 * a * c;
        if (D > 0)
        {
            *x1 = (-b + sqrt(D)) / (2 * a);
			*x2 = (-b - sqrt(D)) / (2 * a);
			*solutionNo = 2;
        }
        else if (D == 0)
        {
            *x1 = -b / (2 * a);
            *solutionNo = 1;
        }
        else
        {
            *solutionNo = 0;
        }
    }
}

int main()
{
    int solutionNo;
    double x1, x2, a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    quadro(a,b,c, &x1, &x2, &solutionNo);
    switch (solutionNo)
    {
        case 0: printf("the equation hasn't roots\n"); break;
        case 1: printf("the equation has one root: %.2f\n", x1); break;
        case 2: printf("the equation has two roots:\n1)%.2f\n2)%.2f\n", x1, x2); break;
        default: printf("the equation has infinity many roots\n"); break;

    }
    return 0;
}
