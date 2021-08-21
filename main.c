#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <stdbool.h>

#include <ctype.h>

bool doub(double x)
{
    const double EPSILON = 0.000001;
    return (fabs(x - 0) < EPSILON);
}


int quadro(double a, double b, double c, int solutionNo, double *x1, double *x2)
{
    /* ax^2 + bx + c = 0 - a, b, c are the coefficients of the quadratic equation*/
    double D = 0;
    if (doub(a) && !(b) && !doub(c))  /*in order to avoid any problems with errors, we take a very small number of epsilon constants*/
    {
            solutionNo = 4;
    }
    else if (doub(a) && doub(b) && doub(c)) /*in the part up to main, we will consider all possible cases with a discriminant, and coefficients*/
    {
            solutionNo = 3;
    }
    else if (doub(a) && doub(b) && !doub(c))
    {
            solutionNo = 0;
    }
    else
    {
        D = b * b - 4 * a * c;
        if (D > 0)
        {
            *x1 = (-b + sqrt(D)) / (2 * a);
			*x2 = (-b - sqrt(D)) / (2 * a);
			solutionNo = 2;
        }
        else if (D == 0)
        {
            *x1 = -b / (2 * a);
            if (*x1 == -*x1)
            {
                *x1 = abs(*x1);
            }
            solutionNo = 1;
        }
        else
        {
            solutionNo = 0;
        }
    }
    return solutionNo;
}

int main()
{
    int solutionNo;
    double x1, x2, a, b, c;
    int res = scanf("%lf %lf %lf", &a, &b, &c);
    if (res < 3)
    {
        printf("you need to write double a,b,c\n");
    }
    else
    {
        solutionNo = quadro(a,b,c, solutionNo, &x1, &x2);
    }
    switch (solutionNo) /*let's determine what is the number of roots of the equation*/
    {
        case 0:
            printf("the equation hasn't roots\n");
            break;
        case 1:
            printf("the equation has one root: %.2f\n", x1);
            break;
        case 2:
            printf("the equation has two roots:\n1)%.2f\n2)%.2f\n", x1, x2);
            break;
        case 3:
            printf("the equation has infinity many roots.\n");
            break;
        case 4:
            printf("it's not quadro equation.\n");
            break;
        default:
            printf("repeat the operation.\n");
            break;
    }
    return 0;
}
