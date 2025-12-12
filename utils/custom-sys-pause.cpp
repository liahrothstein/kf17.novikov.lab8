#include <stdio.h>

/* Функция преостановки выполнения программы
   Назначение: Замена system(“pause”), потому что выполнение программы происходит на ОС Linux */

void customSystemPause(int param) {
    if (param == 1) {
        printf("Нажмите Enter для продолжения...");
    } else {
        printf("Нажмите Enter для выхода...");
    }

    while (getchar() != '\n'); // Очистка буфера
    getchar(); // Ожидание Enter
}