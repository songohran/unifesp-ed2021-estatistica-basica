#ifndef STATISTIC_HEADER
#define STATISTIC_HEADER

#include "./float_list.h"

float sum(size_t qt_numbers, float numbers[]);
float min(size_t qt_numbers, float numbers[]);
float max(size_t qt_numbers, float numbers[]);
float average(size_t qt_numbers, float numbers[]);
float median(size_t qt_numbers, float numbers[]);
FloatList *popular(size_t qt_numbers, float numbers[]);
float variance(size_t qt_numbers, float numbers[]);
float standard_deviation(size_t qt_numbers, float numbers[]);

#endif