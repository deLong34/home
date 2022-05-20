#include <stdio.h>
#include <stdlib.h>
#include "head.h"

//быстрая сортировка Хоара
void qsUpd(int* arr, int first, int last) {
    int i = first;
    int j = last;

    if ((arr[first] <= arr[(first + last) / 2] && arr[first] >= arr[last] ) || (arr[first] >= arr[(first + last) / 2] && arr[first] <= arr[last]))
        swapInt(&arr[first], &arr[(first + last) / 2]);
    if ((arr[last] <= arr[(first + last) / 2] && arr[last] >= arr[first] ) || (arr[last] >= arr[(first + last) / 2] && arr[last] <= arr[first]))
        swapInt(&arr[last], &arr[(first + last) / 2]);
    int x =  arr[(first + last) / 2];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swapInt(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (last - i > 10) {
            qsUpd(arr, i, last);
    }
    else sortInsert (arr, last - i);

    if (j - first > 10) {
            qsUpd(arr, first, j);
    }
    else sortInsert (arr, j - first);
}

//
void chetSort (int* arr, int len) {
    int min;
    for (int i = 0; i < len - 1; ++i) {
        min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr [min] && arr[j] % 2 == 0 )
                min = j;
        }
        if ((arr[i] % 2 == 0) && (arr[min] % 2 == 0))
            swapInt(&arr[i], &arr[min]);
    }
}


int main()
{
   const int SZ = 30;
   int arr[SZ];
   fillIntRandom(arr, SZ, 100);
   printIntArray(arr, SZ, 3);
   //qsUpd(arr, 0, SZ - 1);
   //printIntArray(arr, SZ, 3);
   chetSort(arr, SZ);
   printIntArray(arr, SZ, 3);
   return 0;
}
