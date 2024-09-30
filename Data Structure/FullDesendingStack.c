#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int top;
    unsigned int size;
    int *array;
}Stack;

int isEmpty(Stack *s){
    return s->top==s->size;
}
int isFull(Stack *s)
{
    return s->top==0;
}
void display(Stack *s,int n) {
    int i;
    printf("Stack top index: %d\n", s->top);
    for (i = s->top; i <= n-1; i++) {
        printf("%d", s->array[i]);
        if (i < n-1) {
            printf(" -> ");
        }
    }
    printf("\n");
}
void push(Stack *s, int value) {
    if (!isFull(s)) 
        s->array[--s->top] = value;  // Use = for assignment, not ==
    else
        printf("Stack is Full to push element %d\n",value);
}
void pop(Stack *s)
{
    if(!(isEmpty(s)))
        ++s->top;
    else
        printf("Stack is Empty to pop\n");
}
void peek(Stack *s){
    if(!isEmpty(s))
    printf("Top element : %d",s->array[s->top]);
    else
    printf("Empty Stack");
}
Stack* Create(unsigned int size)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top=size;
    s->size = size;
    s->array = (int*)malloc(s->size*sizeof(int));
    return s;
}
int main() {
    unsigned int n;
    Stack *s;
    printf("Enter number of elements for Stack: ");
    scanf("%d", &n);
    s = Create(n);

    unsigned int Exit = 0, choice;
    int value;
    while (!Exit) {
        printf("\n *****Main Menu*****");
        printf("\n 1. Push");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &value);
                push(s, value);
                break;
            case 2:
                pop(s);
                printf("Last element is popped\n");
                break;
            case 3:
                peek(s);
                break;
            case 4:
                display(s,n);
                break;
            case 5:
                Exit = 1;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    // Free allocated memory before exit
    free(s->array);
    free(s);
    return 0;
}
