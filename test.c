#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <math.h>

static struct AllTests
{
   double a;
   double b;
   double c;
   double x1;
   double x2;
   int noSolution;
};

bool equal(double x, double y)
{
    static const double EPSILON = 0.00001;
    return fabs(x - y) < EPSILON;
}

bool test(struct AllTests Al)
{
    double x1 = -17.00, x2 = -17.00;
    int noSolution = quadro(Al.a, Al.b, Al.c, &x1, &x2);
    switch(noSolution)
    {
    case 1:
        return (noSolution == Al.noSolution) && equal(Al.x1, x1);
        break;
    case 2:
        return (noSolution == Al.noSolution) && equal(Al.x1, x1) && equal(Al.x2, x2);
        break;
    default:
        return false;
        break;
    }
}

bool check_result()
{
    bool right = true;
    static struct AllTests Tests[4] =
    {
        {1,2,1,-1.00,-17.00,1},
        {4,4,1,-0.50,-17.00,1},
        {1,2,-3,1.00,-3.00,2},
        {25,10,1,-0.20,-17.00,1},
    };
    for (int i = 0; i < 4; i++)
    {
        bool x = test(Tests[i]);
        printf("Test #%d %d\n", i, x);
        right = right && test(Tests[i]);
    }
    return right;
}
