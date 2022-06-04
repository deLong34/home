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
