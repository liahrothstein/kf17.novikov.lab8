/* Функция вычисления параметров куба
   Назначение: Вычисляет 3 параметра и возвращает их через указатели (по адресу) */

void calculateCubeParams(double a, double *volume, double *surfaceArea, double *faceArea) {
    *faceArea = a * a;          // Площадь одной грани
    *surfaceArea = 6 * (*faceArea); // Полная площадь (6 граней)
    *volume = a * a * a;         // Объем
}