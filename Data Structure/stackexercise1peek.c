#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    unsigned int size;
    int *array;
} Stack;

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == s->size - 1;
}
int peek(Stack *s){
    if(!isEmpty(s))
    return s->array[s->top];
    else
    return 0;
}
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack top index: %d\n", s->top);
    for (int i = s->top; i >= 0; i--) {
        printf("%d", s->array[i]);
        if (i > 0) {
            printf(" -> ");
        }
    }
    printf("\n");
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->array[++s->top] = value;
    } else {
        printf("Stack is full, cannot push element %d\n", value);
    }
}

void pop(Stack *s) {
    if (!isEmpty(s)) {
        --s->top;
    } else {
        printf("Stack is empty, cannot pop\n");
    }
}

Stack* Create(unsigned int size) {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    s->size = size;
    s->array = (int*)malloc(s->size * sizeof(int));
    return s;
}

int main() {
    Stack *stack1, *stack2, *stack3;
    unsigned int n, m;

    // Input number of elements for Stack 1
    printf("Enter number of elements for Stack 1: ");
    scanf("%u", &n);
    stack1 = Create(n);

    // Input number of elements for Stack 2
    printf("Enter number of elements for Stack 2: ");
    scanf("%u", &m);
    stack2 = Create(m);

    // Stack 3 should be large enough to hold all elements from both Stack 1 and Stack 2
    unsigned int sizeStack3 = n + m;
    stack3 = Create(sizeStack3);  // Fix: Stack 3 can now hold all the popped values from Stack 1 and Stack 2

    int value;

    // Input elements for Stack 1
    printf("Enter elements for Stack 1:\n");
    for (unsigned int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(stack1, value);
    }

    // Input elements for Stack 2
    printf("Enter elements for Stack 2:\n");
    for (unsigned int i = 0; i < m; i++) {
        scanf("%d", &value);
        push(stack2, value);
    }

    // Pop elements from both stacks, add them, and push to Stack 3 until both are empty
    while (!isEmpty(stack1) || !isEmpty(stack2)) {
        int val1 = isEmpty(stack1) ? 0 : peek(stack1); // Pop or 0 if empty
        int val2 = isEmpty(stack2) ? 0 : peek(stack2); // Pop or 0 if empty
        pop(stack1);
        pop(stack2);
        int sum = val1 + val2;
        push(stack3, sum);
    }

    // Display Stack 3
    printf("Stack 3 after adding top elements from Stack 1 and Stack 2:\n");
    display(stack3);

    // Free memory
    free(stack1->array);
    free(stack1);
    free(stack2->array);
    free(stack2);
    free(stack3->array);
    free(stack3);

    return 0;
}
