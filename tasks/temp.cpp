#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

// --- ПРОТОТИПЫ ФУНКЦИЙ ---

// Функции для Задачи 1
void task1_info();
double calculate_water_force(double h, double s);

// Функции для Задачи 2
void task2_info();
void calculate_cube_params(double a, double *volume, double *surface_area, double *face_area);

// Функции для Задачи 3
void task3_array_process(int *arr, int size, int m, long long *product, int *count);

int main() {
    setlocale(LC_ALL, "Rus"); // Подключение русского языка

    // ================== ЗАДАЧА 1 ==================
    task1_info(); // Вывод условия

    double depth, area, force;
    
    printf("Введите глубину погружения H (м): ");
    scanf("%lf", &depth);
    printf("Введите площадь поверхности S (м^2): ");
    scanf("%lf", &area);

    // Вызов функции вычисления
    force = calculate_water_force(depth, area);

    // Вывод с единицами измерения
    printf("РЕЗУЛЬТАТ: Сила давления воды F = %.2f Ньютон (Н)\n", force);
    
    printf("\n--------------------------------------------------\n");
    system("pause"); // Пауза для просмотра
    printf("\n");

    // ================== ЗАДАЧА 2 ==================
    task2_info(); // Вывод условия задачи 2

    double edge_a;
    double vol, s_total, s_face; // Переменные для хранения результатов

    printf("Введите длину ребра куба A (м): ");
    scanf("%lf", &edge_a);

    // Вызов функции с передачей адресов переменных для записи результатов
    calculate_cube_params(edge_a, &vol, &s_total, &s_face);

    // Вывод результатов
    printf("РЕЗУЛЬТАТЫ:\n");
    printf("Объем куба V = %.2f м^3\n", vol);
    printf("Площадь полной поверхности S_total = %.2f м^2\n", s_total);
    printf("Площадь одной грани S_face = %.2f м^2\n", s_face);

    printf("\n--------------------------------------------------\n");
    system("pause");
    printf("\n");

    // ================== ЗАДАЧА 3 ==================
    printf("ЗАДАЧА 3. Обработка массива.\n");
    printf("Задание: Найти произведение и количество элементов, по модулю меньших m.\n\n");

    int arr[10];
    int i, m_limit;
    long long prod_result = 1; // Инициализация произведения
    int count_result = 0;      // Инициализация счетчика

    // Ввод массива
    printf("Введите 10 целых чисел для массива:\n");
    for (i = 0; i < 10; i++) {
        printf("Элемент [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Введите ограничивающее число m: ");
    scanf("%d", &m_limit);

    // Вызов функции обработки массива
    task3_array_process(arr, 10, m_limit, &prod_result, &count_result);

    // Вывод результатов
    if (count_result > 0) {
        printf("РЕЗУЛЬТАТЫ:\n");
        printf("Количество элементов (|x| < %d): %d шт.\n", m_limit, count_result);
        printf("Произведение этих элементов: %lld\n", prod_result);
    } else {
        printf("Элементов, удовлетворяющих условию (|x| < %d), не найдено.\n", m_limit);
    }

    printf("\n");
    system("pause");
    
    return 0;
}

// --- РЕАЛИЗАЦИЯ ФУНКЦИЙ ---

// Функция вывода информации о Задаче 1
// Назначение: Информирование пользователя о сути первой задачи
void task1_info() {
    printf("ЗАДАЧА 1 (Вариант 14)\n");
    printf("Выполнил: Студент [Ваша Фамилия]\n");
    printf("Условие: Вычислить силу давления в воде на глубине Н метров.\n");
    printf("Формула: F = rho * g * H * S (прим. rho=1000, g=9.81)\n\n");
}

// Функция вычисления силы давления
// Назначение: Расчет силы по формуле гидростатики. Возвращает одно значение.
double calculate_water_force(double h, double s) {
    const double G = 9.81;    // Ускорение свободного падения
    const double RHO = 1000.0; // Плотность воды (кг/м^3)
    return RHO * G * h * s;
}

// Функция вывода информации о Задаче 2
// Назначение: Информирование пользователя о сути второй задачи
void task2_info() {
    printf("ЗАДАЧА 2 (Вариант 14)\n");
    printf("Условие: Для куба с ребром А вычислить объем, площадь поверхности и грани.\n\n");
}

// Функция вычисления параметров куба
// Назначение: Вычисляет 3 параметра и возвращает их через указатели (по адресу)
void calculate_cube_params(double a, double *volume, double *surface_area, double *face_area) {
    *face_area = a * a;          // Площадь одной грани
    *surface_area = 6 * (*face_area); // Полная площадь (6 граней)
    *volume = a * a * a;         // Объем
}

// Функция обработки массива
// Назначение: Проход по массиву и поиск элементов по условию |x| < m
void task3_array_process(int *arr, int size, int m, long long *product, int *count) {
    *product = 1;
    *count = 0;
    
    for (int i = 0; i < size; i++) {
        // abs() - функция модуля из stdlib.h
        if (abs(arr[i]) < m) {
            *product *= arr[i];
            (*count)++;
        }
    }
}