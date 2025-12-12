#include <stdio.h>

#include "../utils/calculate-water-force.h"
#include "../utils/custom-sys-pause.h"

int main() {
    double depth, area, force;

    printf("Программа вычисляет силу давления в воде на глубине Н метров, по формуле: F = ρ * g * H * S (ρ=1000, g=9.81)");
    printf("\nИсполнитель: Новиков Д. А.");
    printf("\nВариант: №14");
    
    printf("\n\nВведите глубину погружения H (м): ");
    scanf("%lf", &depth);
    printf("\nВведите площадь поверхности S (м^2): ");
    scanf("%lf", &area);

    // Вызов функции вычисления
    force = calculateWaterForce(depth, area);

    // Вывод с единицами измерения
    printf("РЕЗУЛЬТАТ: Сила давления воды F = %.2f Ньютон (Н)\n", force);
    
    printf("\n--------------------------------------------------\n");

    customSystemPause(0);
    
    return 0;
}