/* Функция вычисления силы давления
   Назначение: Расчет силы по формуле гидростатики */

double calculateWaterForce(double h, double s) {
    const double G = 9.81;    // Ускорение свободного падения
    const double RHO = 1000.0; // Плотность воды (кг/м^3)

    return (RHO * G * h * s);
}