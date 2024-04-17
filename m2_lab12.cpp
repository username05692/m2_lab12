#include<stdio.h>
#include <math.h>//підключення бібліотек
#include <locale.h>

#define Nx 7
#define Ny 5//визначення розмірів масивів
#define Nz 9
//прототип ф. для вводу
void vvod(float x[], int n, char q);
//прототип ф. для аналізу
void analiz(float x[], int n, float znah, float* s1, float* av);
//прототип ф. для виводу
void vuvid(float x[], int l, char q);

int main() {
    setlocale(LC_CTYPE, "ukr");// встановлення локалізації
    // оголошення змінних
    float x[Nx], y[Ny], z[Nz], sum, average;
    float znah;

    printf("Введiть цiльове значення: ");
    scanf_s("%f", &znah);
    //використання ф. для введення
    vvod(x, Nx, 'x');
    vvod(y, Ny, 'y');
    vvod(z, Nz, 'z');
    //використвння ф. для виведення
    vuvid(x, Nx, 'x');
    vuvid(y, Ny, 'y');
    vuvid(z, Nz, 'z');
    printf(" \n");
    //використання ф. для аналізу
    analiz(x, Nx, znah, &sum, &average);
    printf("Для масиву x: sum=%.2f average=%.2f  \n", sum, average);
    printf(" \n");

    analiz(y, Ny, znah, &sum, &average);
    printf("Для масиву y: sum=%.2f average=%.2f  \n", sum, average);
    printf(" \n");

    analiz(z, Nz, znah, &sum, &average);
    printf("Для масиву z: sum=%.2f average=%.2f  \n", sum, average);

    return 0;
}
//визначення ф. для аналізу
void analiz(float x[], int n, float znah, float* s1, float* av) {
    *s1 = 0;
    *av = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] < znah) {
            *s1 += x[i];
            k++;
        }
    }
    if (k > 0) {
        *av = *s1 / k;
    }
    
}
//визначення ф. для введення 
void vvod(float x[], int n, char q) {
    printf("Масив %c \n", q);
    for (int i = 0; i < n; i++) {
        printf("Введiть %c[%i] = ", q, i + 1);
        scanf_s("%f", &x[i]);
        
    }
    printf(" \n");
    return;
}
//визначення ф. для виведеення 
void vuvid(float x[], int l, char q) {
    printf("Масив %c \n", q);
    for (int i = 0; i < l; i++) {
        printf(" %.1f ", x[i]);
    }
    printf("\n");
    return;
}
