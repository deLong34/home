#include <stdio.h>
#include <stdlib.h>
#define T char
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct Node {
    T dat;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Stack;

void init(Stack *stack) {
    stack->head = NULL;
    stack->size = 0;
}

boolean push(Stack *stack, T value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

void printOneLinkCharNode(Node *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%c]", n->dat);
}

void printOneLinkCharStack(Stack *stack) {
    Node *current = stack->head;
    if (current == NULL) {
        printOneLinkCharNode(current);
    } else {
        do {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", stack->size);
}

//для задания 2.

void ins(Stack *stack, T data) {
    Node *new = (Node*) malloc(sizeof(Node));
    new->dat = data;
    new->next = NULL;

    Node *current = stack->head;
    if (current == NULL) {
        stack->head = new;
        stack->size++;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        stack->size++;
    }
}

Node* rm(Stack *stack, T data) {
    Node *current = stack->head;
    Node *parent = NULL;
    if (current == NULL)
        return NULL;
    while (current->next != NULL && current->dat != data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data) {
        return NULL;
    }
    if (current == stack->head) {
        stack->head = current->next;
        stack->size--;
        return current;
    }
    parent->next = current->next;
    stack->size--;
    return current;
}
//функции копирования
void copyOneLinkCharStack(Stack *stack, Stack *name) {
    Node *current = stack->head;
    if (current == NULL) {
       return;
    } else {
        name->head = NULL;
        name->size = 0;
        do {
            ins(name, current->dat);
            current = current->next;
        } while (current != NULL);
    }
}



int main()
{
    //задание 1.
  // const int len = 13;
   int errFlag = 0;
   T formula[] = "[2/{5*(4+7)]]}";
   Stack *st = (Stack*) malloc(sizeof(Stack));
   init(st);
   for (int i = 0; i < 13; i++) {
      if (formula[i] == "(" || formula[i] == "[" || formula[i] == "{") {
        push(st, formula[i]); //если скобка открывающаяся - кладем её в стек
      }
      if (formula[i] == ")" && st->head->dat == "(") { //если скобка закрывается и совпадает с последней в стеке (открывающейся)
        pop(st); //удаляем из стека крайнюю скобку
      } else if (formula[i] == ")" && st->head->dat != "(") { //если закрывающаяся скобка не аналогична крайней в стеке открывающиейся
      printf("Sequense not correct, Where %c \n", st->head->dat);
      errFlag++;
      }
      if (formula[i] == "]" && st->head->dat == "[") {
        pop(st);
      } else if (formula[i] == "]" && st->head->dat != "[") {
      printf("Sequense not correct, Where %c \n", st->head->dat);
      errFlag++;
      }
      if (formula[i] == "}" && st->head->dat == "{") {
        pop(st);
      } else if (formula[i] == "}" && st->head->dat != "{") {
      printf("Sequense not correct, Where %c \n", st->head->dat);
      errFlag++;
      }
   }
   if (errFlag == 0 && st->size == 0)
   printf("Sequense correct \n");
//////////Задание 2.
   Stack *lst = (Stack*) malloc(sizeof(Stack));
   init(lst);
   Stack *newlist = (Stack*) malloc(sizeof(Stack));
   init(newlist);
   printOneLinkCharStack(lst);
   ins(lst, 1);
   printOneLinkCharStack(lst);
   ins(lst, 11);
   printOneLinkCharStack(lst);
copyOneLinkCharStack(lst, newlist);
printOneLinkCharStack(newlist);
ins(lst, 12);
printOneLinkCharStack(lst);
printOneLinkCharStack(newlist);
copyOneLinkCharStack(lst, newlist);
printOneLinkCharStack(newlist);
    return 0;
}
