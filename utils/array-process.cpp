#include <cmath>

/* Функция обработки массива
   Назначение: Проход по массиву и поиск элементов по условию |x| < m */

void arrayProcess(int *arr, int size, int m, long long *product, int *count) {
    *product = 1;
    *count = 0;
    
    for (int i = 0; i < size; i++) {
        if (abs(arr[i]) < m) {
            *product *= arr[i];
            (*count)++;
        }
    }
}