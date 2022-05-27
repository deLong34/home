#include <stdio.h>
#include <stdlib.h>
#include "head.h"

#define SZ 10
#define T int
#define SIZE 100000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;
typedef struct {
    int pr;
    int dat;
} Node;
T Stack[SIZE];
Node* arr[SZ];
int items;
int cursor = -1;


void init() {
    for (int i = 0; i < SZ; ++i) {
        arr[i] = NULL;
    }
    items = 0;
}

void ins(int pr, int dat) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;

    if (items < SZ) {
        arr[items++] = node;
    } else {
        printf("%s \n", "Queue is full");
        return;
    }
}

Node* rem() {
    if (items == 0) {
        return NULL;
    } else {
        int buf = 0;
        int i = 0;
        Node *tmp = arr[0];
        for (i = 1; i < items; ++i) {
            if (arr[i]->pr > tmp->pr) {
                tmp = arr[i];
                buf = i;
            }
        }
        for (i = buf; i < items; i++) {
           arr[i] = arr[i + 1];
        }
        arr[items] = NULL;
        items--;
        return tmp;
    }
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SZ; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
     printf(" ]\n");
}

/////////////////////////////////////////////////
boolean push(T data) {
    if (cursor < SIZE) {
        Stack[++cursor] = data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T pop() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
         printf("%s \n", "Stack is empty");
         return -1;
    }
}

void tenToTwoStack (int num) {
    int nol = 0;
    int one = 1;
    while (num >= 1) {
        if (num % 2 == 0) {
          push(0);
        } else  {
            push(1);
        }
        num = num / 2;
    }
}

int main()
{
   init();
   ins(1, 11);
   ins(2, 22);
   ins(6, 33);
   ins(4, 44);
   ins(1, 55);
   ins(6, 66);
   ins(7, 77);
   ins(3, 88);
   ins(1, 99);
   printQueue();
   for (int i = 0; i < 5; ++i) {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
   }
   printQueue();
   ins(7, 77);
   printQueue();
  /////////////////////////
  int num = 15;
  tenToTwoStack(num);
  while (cursor != -1) {
    printf ("%d ", pop());
  }
    return 0;
}
