#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

struct Node* pop(struct Node* top, int* value) {
    if (top == NULL) return NULL;

    struct Node* temp = top;
    *value = top->data;
    top = top->next;
    free(temp);
    return top;
}

int evaluatePostfix(char* expr) {
    struct Node* stack = NULL;
    char* token = strtok(expr, " ");

    while (token != NULL) {

        if (isdigit(token[0])) {
            stack = push(stack, atoi(token));
        }
        else {
            int b, a;
            stack = pop(stack, &b);
            stack = pop(stack, &a);

            int result;

            switch(token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            stack = push(stack, result);
        }

        token = strtok(NULL, " ");
    }

    int final;
    stack = pop(stack, &final);
    return final;
}

int main() {
    char expr[200];

    fgets(expr, sizeof(expr), stdin);

    printf("%d\n", evaluatePostfix(expr));

    return 0;
}