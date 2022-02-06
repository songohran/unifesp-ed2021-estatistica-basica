#include <stdio.h>
#include <math.h>

// #include "./libs/statistic.h"
#include "./libs/float_list.h"

void _print_list(float value, size_t index, FloatList *list)
{
    printf("%f - %ld\n", value, index);
}

int main()
{
    FloatList *list = float_list.create();

    for (size_t i = 0; i < 10; i++)
    {

        float_list.append(list, (i * 2));
    }

    float_list.clear(list);

    float_list.foreach (list, _print_list);

    return 0;
}
