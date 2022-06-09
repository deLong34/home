#include <stdio.h>
#include <stdlib.h>
#include "head.h"

typedef char K;
typedef int htIndex;

int htSize;

//наша Жэш-функция
htIndex hash(char *data) {
    int codSum = 0;
    //char buf[100] = data;
    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        codSum+=(int)(data[i]);
    }
    return codSum;
}

//вставка в хэш-таблицу
boolean insertNodeHash( OneLinkNode** table, K data) {
    OneLinkNode *p, *p0;
    htIndex bucket = hash(data);
    p = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (p == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    p0 = table[bucket];
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}

//поиск по хэш-таблице
OneLinkNode* findNodeHash(OneLinkNode** table, K data) {
    OneLinkNode *p = table[hash(data)];
    while (p && !(p->dat == data))
        p = p->next;
    return p;
}

//удаление узла по значению из хэш-таблицы
void deleteNodeHash(OneLinkNode** table, K data) {
    OneLinkNode *parent, *current;
    parent = NULL;
    htIndex bucket = hash(data);
    current = table[bucket];
    while (current && !(current->dat == data)) {
        parent = current;
        current = current->next;
    }
    if (!current) {
        printf("Value not found \n");
        return;
    }
    if (parent)
        parent->next = current->next;
    else
        table[bucket] = current->next;
    free(current);
}

//функция вывода на экран
void printTableHash(OneLinkNode** table, int size) {
    OneLinkNode *p;
    for (int i = 0; i < size; ++i) {
        p = table[i];
        while (p) {
            printf("%5d", p->dat);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

///////////////////////////////////2
int coinCounter(int* naminal, int sum, const int SIZE) {
    int counter = 0;
    for (int i = 0; i < SIZE; i++) {
        while (sum >= naminal[i]) {
            sum-= naminal[i];
            counter++;
            printf("%3d", naminal[i]);
        }
        if (sum == 0) continue;
    }
    return counter;
}

int main() {
    htSize = 10;
    const int SZ = 10;
    char* arr;
    arr[10] = "stroka";
    OneLinkNode** hashTable = (OneLinkNode**) calloc(htSize, sizeof(OneLinkNode*));
    for (int i = 0; i < SZ; ++i) {
        insertNodeHash(hashTable, arr[i]);
    }
    printTableHash(hashTable, htSize);
    /////////////////////2
    int naminal[] = {50, 10, 5, 2, 1};
    const int SUM = 98;
    printf("\n Number of coins: %d", coinCounter(naminal, SUM, 5));
    return 0;
}
