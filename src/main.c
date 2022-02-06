#include <stdio.h>
#include <math.h>

#include "./libs/statistic.h"

int main()
{
    float x[] = {15, 12, 3, 5, 0};

    printf("%f\n", variance(1, x));

    return 0;
}
