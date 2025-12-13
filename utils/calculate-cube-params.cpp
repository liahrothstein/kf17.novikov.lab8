#include <cmath>

/* Функция вычисления параметров куба
   Назначение: Вычисляет 3 параметра и возвращает их через указатели (по адресу) */

void calculateCubeParams(double a, double *volume, double *surfaceArea, double *faceArea) {
    *faceArea = pow(a, 2);          // Площадь одной грани
    *surfaceArea = 6 * (*faceArea); // Полная площадь (6 граней)
    *volume = pow(a, 3);         // Объем
}