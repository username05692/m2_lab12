#include<stdio.h>
#include <math.h>//���������� �������
#include <locale.h>

#define Nx 7
#define Ny 5//���������� ������ ������
#define Nz 9
//�������� �. ��� �����
void vvod(float x[], int n, char q);
//�������� �. ��� ������
void analiz(float x[], int n, float znah, float* s1, float* av);
//�������� �. ��� ������
void vuvid(float x[], int l, char q);

int main() {
    setlocale(LC_CTYPE, "ukr");// ������������ ����������
    // ���������� ������
    float x[Nx], y[Ny], z[Nz], sum, average;
    float znah;

    printf("����i�� �i����� ��������: ");
    scanf_s("%f", &znah);
    //������������ �. ��� ��������
    vvod(x, Nx, 'x');
    vvod(y, Ny, 'y');
    vvod(z, Nz, 'z');
    //������������ �. ��� ���������
    vuvid(x, Nx, 'x');
    vuvid(y, Ny, 'y');
    vuvid(z, Nz, 'z');
    printf(" \n");
    //������������ �. ��� ������
    analiz(x, Nx, znah, &sum, &average);
    printf("��� ������ x: sum=%.2f average=%.2f  \n", sum, average);
    printf(" \n");

    analiz(y, Ny, znah, &sum, &average);
    printf("��� ������ y: sum=%.2f average=%.2f  \n", sum, average);
    printf(" \n");

    analiz(z, Nz, znah, &sum, &average);
    printf("��� ������ z: sum=%.2f average=%.2f  \n", sum, average);

    return 0;
}
//���������� �. ��� ������
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
//���������� �. ��� �������� 
void vvod(float x[], int n, char q) {
    printf("����� %c \n", q);
    for (int i = 0; i < n; i++) {
        printf("����i�� %c[%i] = ", q, i + 1);
        scanf_s("%f", &x[i]);
        
    }
    printf(" \n");
    return;
}
//���������� �. ��� ���������� 
void vuvid(float x[], int l, char q) {
    printf("����� %c \n", q);
    for (int i = 0; i < l; i++) {
        printf(" %.1f ", x[i]);
    }
    printf("\n");
    return;
}
