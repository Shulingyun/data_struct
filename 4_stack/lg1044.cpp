/*************************************************************************
	> File Name: stack.cpp
	> Author: sly
	> Mail: shulingyun@hrbeu.edu.cn
	> Created Time: 2019年04月14日 星期日 14时06分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top, length;
} Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->top = -1;
    s->length = n;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}

void push(Stack *s, int val) {
    if (s->top == s->length - 1) return ;
    s->top += 1;
    s->data[s->top] = val;
    return ;
}

void pop(Stack *s) {
    if (empty(s)) return ;
    s->top -= 1;
    return ;
}


void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

void output(Stack *s) {
    printf("stack = [");
    for (int i = s->top; i >= 0; i--) {
        printf(" %d", s->data[i]);
    }
    printf("]\n");
    return ;
}


int main() {
    srand(time(0));
    #define MAX_OP 20
    Stack *s = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 2, val = rand() % 100;
        switch (op) {
            case 0: {
                printf("push %d to stack\n", val);
                push(s, val);
            } break;
            case 1: {
                printf("push %d from stack\n", top(s));
            } break;
        }
        output(s);
    }
    clear(s);
    return 0;
}
