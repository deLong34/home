#include <stdio.h>
#include <stdlib.h>
#include "head.h"

const int n = 6;
int matrix[n][n] = {
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},
};

int visited[n] = {0};

void depthTravers(int st) {
    int r;
    printf("%d", st);
    visited[st] = 1;
    for (r = 0; r < n; ++r) {
        if (matrix[st][r] == 1 && !visited[r]) {
            depthTravers(r);
        }
    }
}

void resetArr() {
for (int i = 0; i < n; ++i) {
    visited[i] = 0;
    }
}
/////////////
int getUnvisitedVertex (int** matrix, int ver, int size) {
    for (int i = 0; i < size; i++) {
        if (get2dInt(matrix, ver, i) == 1 && !visited[i])
            return i;
    }
    return -1;
}

void depthStackTravers(int** matrix, int size) {
     Stack* stack = (Stack*) malloc(sizeof(Stack));
     initStack(stack);
     visited[0] = true;
     printf("%d", stack->dat); //любая функция работы с данными ячейки
     pushStack(stack, 0);
  
     while (stack->size) {
        int guv = getUnvisitedVertex(matrix, stack->head->dat, size);
        if (guv == -1) {
        popStack(stack);
     } else {
        visited[guv] = true;
        printf("%d", stack->dat);//любая функция работы с данными ячейки
        pushStack(stack, guv);
     }
     }
     resetArr();
}


int adMLinks[n] = {0};
//считаем количество ссылок на каждый узел по матрице
void adjacencyMatrixCount (int** matrix, const int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[j][i] == 1 && i != j)
                adMLinks[i]++;
        }
    }
}

int main() {
    depthTravers(0);
    resetArr();
    printf("\n");
    depthTravers(0);
    resetArr();
    printf("\n");
    depthTravers(0);
    resetArr();
    printf("\n");

    return 0;
}
