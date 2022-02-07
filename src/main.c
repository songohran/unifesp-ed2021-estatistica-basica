#include <stdio.h>
#include <math.h>

#include "./libs/statistic.h"
#include "./libs/float_list.h"

void _print_list(float value, size_t index, FloatList *list)
{
    printf("(%.2f) ", value);
}

#define LIM 25

int main()
{
    float numbers[LIM];
    float qt_numbers;

    printf("Entre com uma lista de valores: ");
    scanf("%f", &qt_numbers);

    for (size_t i = 0; i < qt_numbers; i++)
    {
        printf("> ");
        scanf("%f", &numbers[i]);
    }

    FloatList *popular_numbers = popular(qt_numbers, numbers);

    printf("Soma: %.2f\n", sum(qt_numbers, numbers));
    printf("Minímo: %.2f\n", min(qt_numbers, numbers));
    printf("Máximo: %.2f\n", max(qt_numbers, numbers));
    printf("Média: %.2f\n", average(qt_numbers, numbers));
    printf("Mediana: %.2f\n", median(qt_numbers, numbers));
    printf("Moda: ");
    float_list.foreach (popular_numbers, _print_list);
    printf("\n");
    printf("Variância: %.2f\n", variance(qt_numbers, numbers));
    printf("Desvio Padrão: %.2f\n", standard_deviation(qt_numbers, numbers));

    return 0;
}
