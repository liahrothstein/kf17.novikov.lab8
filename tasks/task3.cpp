#include <stdio.h>

#include "../utils/calculate-water-force.h"
#include "../utils/calculate-cube-params.h"
#include "../utils/array-process.h"
#include "../utils/custom-sys-pause.h"
#include "../utils/task-info.h"

int main() {
    double depth, area, force;

    taskInfo(3);

    // ================== ЗАДАЧА 1 ==================
    
    printf("\n\nВведите глубину погружения H (м): ");
    scanf("%lf", &depth);
    printf("\nВведите площадь поверхности S (м^2): ");
    scanf("%lf", &area);

    // Вызов функции вычисления
    force = calculateWaterForce(depth, area);

    // Вывод с единицами измерения
    printf("РЕЗУЛЬТАТ: Сила давления воды F = %.2f Ньютон (Н)\n", force);
    
    printf("\n--------------------------------------------------\n");
    
    customSystemPause(1);
    
    // ================== ЗАДАЧА 2 ==================
    
    double edgeA;
    double vol, sTotal, sFace; // Переменные для хранения результатов
    
    printf("\n\nВведите длину ребра куба A (м): ");
    scanf("%lf", &edgeA);
    
    // Вызов функции с передачей адресов переменных для записи результатов
    calculateCubeParams(edgeA, &vol, &sTotal, &sFace);
    
    // Вывод результатов
    printf("РЕЗУЛЬТАТЫ:\n");
    printf("Объем куба V = %.2f м^3\n", vol);
    printf("Площадь полной поверхности S_полн = %.2f м^2\n", sTotal);
    printf("Площадь одной грани S_гр = %.2f м^2\n", sFace);
    
    printf("\n--------------------------------------------------\n");

    customSystemPause(1);

    // ================== ЗАДАЧА 3 ==================

    int arr[10];
    int i, mLimit;
    long long prodResult = 1; // Инициализация произведения
    int countResult = 0;      // Инициализация счетчика

    // Ввод массива
    printf("\n\nВведите 10 целых чисел для массива:\n");
    for (i = 0; i < 10; i++) {
        printf("Элемент [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Введите ограничивающее число m: ");
    scanf("%d", &mLimit);

    // Вызов функции обработки массива
    arrayProcess(arr, 10, mLimit, &prodResult, &countResult);

    // Вывод результатов
    if (countResult > 0) {
        printf("РЕЗУЛЬТАТЫ:\n");
        printf("Количество элементов (|x| < %d): %d шт.\n", mLimit, countResult);
        printf("Произведение этих элементов: %lld\n", prodResult);
    } else {
        printf("Элементов, удовлетворяющих условию (|x| < %d), не найдено.\n", mLimit);
    }

    customSystemPause(0);
    
    return 0;
}