#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "./statistic.h"

float sum(size_t qt_numbers, float numbers[])
{
    float sum_result = 0;

    for (size_t i = 0; i < qt_numbers; i++)
    {
        sum_result += numbers[i];
    }

    return sum_result;
}

float min(size_t qt_numbers, float numbers[])
{
    assert(qt_numbers != 0);

    float curr_min = numbers[0];

    for (size_t i = 1; i < qt_numbers; i++)
    {
        if (numbers[i] < curr_min)
        {
            curr_min = numbers[i];
        }
    }

    return curr_min;
}

float max(size_t qt_numbers, float numbers[])
{
    assert(qt_numbers != 0);

    float curr_max = numbers[0];

    for (size_t i = 1; i < qt_numbers; i++)
    {
        if (numbers[i] > curr_max)
        {
            curr_max = numbers[i];
        }
    }

    return curr_max;
}

float average(size_t qt_numbers, float numbers[])
{
    assert(qt_numbers != 0);
    return sum(qt_numbers, numbers) / qt_numbers;
}

int _compare_float(const void *a, const void *b)
{
    float *x = (float *)a;
    float *y = (float *)b;

    if (*x < *y)
    {
        return -1;
    }
    else if (*x == *y)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

float median(size_t qt_numbers, float numbers[])
{
    assert(qt_numbers != 0);

    float numbers_cpy[qt_numbers];

    for (size_t i = 0; i < qt_numbers; i++)
    {
        numbers_cpy[i] = numbers[i];
    }

    qsort(numbers_cpy, qt_numbers, sizeof(float), _compare_float);

    if (qt_numbers % 2 == 1)
    {
        return numbers_cpy[qt_numbers / 2];
    }
    else
    {
        return (numbers_cpy[qt_numbers / 2 - 1] + numbers_cpy[qt_numbers / 2]) / 2;
    }
}

int _count_float(size_t qt_numbers, float numbers[], float number)
{
    assert(qt_numbers != 0);

    int counter = 0;

    for (size_t i = 0; i < qt_numbers; i++)
    {
        if (numbers[i] == number)
        {
            counter += 1;
        }
    }

    return counter;
}

float popular(size_t qt_numbers, float numbers[])
{
    assert(qt_numbers != 0);

    float most_popular_number = numbers[0];
    float most_popular_frequency = _count_float(qt_numbers, numbers, numbers[0]);

    for (size_t i = 1; i < qt_numbers; i++)
    {
        int curr_frequency = _count_float(qt_numbers, numbers, numbers[i]);

        if (curr_frequency > most_popular_frequency)
        {
            most_popular_frequency = curr_frequency;
            most_popular_number = numbers[i];
        }
    }

    return most_popular_number;
}

float variance(size_t qt_numbers, float numbers[])
{
    assert(qt_numbers != 0);

    float variance_result = 0;
    float numbers_average = average(qt_numbers, numbers);

    for (size_t i = 0; i < qt_numbers; i++)
    {
        variance_result += pow(numbers[i] - numbers_average, 2);
    }

    variance_result /= qt_numbers;

    return variance_result;
}

float standard_deviation(size_t qt_numbers, float numbers[])
{
    assert(qt_numbers != 0);
    return sqrt(variance(qt_numbers, numbers));
}