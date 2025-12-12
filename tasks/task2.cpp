#include <stdio.h>

#include "../utils/calculate-water-force.h"
#include "../utils/calculate-cube-params.h"

int main() {
    double depth, area, force;

    printf("Программа вычисляет:\n    - Силу давления в воде на глубине Н метров, по формуле: F = ρ * g * H * S (ρ=1000, g=9.81)\n    - Объем, площадь поверхности и грани куба с ребром А");
    printf("\nИсполнитель: Новиков Д. А.");
    printf("\nВариант: №14");

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
    
    printf("Нажмите Enter для продолжения...");
    while (getchar() != '\n'); // очистка буфера
    getchar(); // ожидание Enter
    
    // ================== ЗАДАЧА 2 ==================
    
    double edge_a;
    double vol, s_total, s_face; // Переменные для хранения результатов
    
    printf("\n\nВведите длину ребра куба A (м): ");
    scanf("%lf", &edge_a);
    
    // Вызов функции с передачей адресов переменных для записи результатов
    calculateCubeParams(edge_a, &vol, &s_total, &s_face);
    
    // Вывод результатов
    printf("РЕЗУЛЬТАТЫ:\n");
    printf("Объем куба V = %.2f м^3\n", vol);
    printf("Площадь полной поверхности S_полн = %.2f м^2\n", s_total);
    printf("Площадь одной грани S_гр = %.2f м^2\n", s_face);
    
    printf("\n--------------------------------------------------\n");

    printf("Нажмите Enter для выхода...");
    while (getchar() != '\n'); // очистка буфера
    getchar(); // ожидание Enter
    
    return 0;
}