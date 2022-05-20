#include <stdio.h>
#include <stdlib.h>
//#include "geek.h"

// перестановка элементов местами
void swap(int *a, int *b) {
   int t = *a;
   *a = *b;
   *b = t;
}

//печать 2м массива 3х3
void printIntArr(int arr[3][3]) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            printf("%2d", arr[i][j]);
        }
        printf("\n");
    }
}

//пузырьковая сортировка двумерного целочисленного массива
void bubbleSort (int row, int col, int arr[row][col]) {
    for (int k = 0; k < row + col; k++) {
       for (int i = 0; i < row; i++) {
          for (int j = 0; j < col; j++) {
             if (j + 1 < col && arr[i][j] > arr[i][j+1])
                swap (&arr[i][j] , &arr[i][j+1]);
             if (j + 1 == col && arr[i][j] > arr[i+1][0] && i + 1 < row )
                swap (&arr[i][j], &arr[i+1][0]);
          }
       }
    }
}

//реализация алгоритма Трабба-Прадо-Кнута
void myTPK(int n) {
    int P[n];
    for (int i = 0; i < n; i++) {
        int a;
        printf("Enter number %d:", i+1);
        scanf("%d", &a);
        P[i] = a;
    }
    for (int i = 0; i < n / 2; i++) {
        swap (&P[i], &P[n - i]);
    }
    for (int i = 0; i < n; i++) {
        if (sqrt(fabs(P[i])) + 5*pow(P[i],3) > 400)
            printf("Inform about %d \n", P[i]);
    }
}


int main(const int argc, const char** argv)
{
    int myarr[3][3] = { {1,9,2}, {5,7,6}, {4,3,8} };
    printIntArr (myarr);
    bubbleSort (3,3,myarr);
    printIntArr (myarr);
    myTPK(11);
    return 0;
}
