#include <stdio.h>
#include <stdlib.h>

// Queue structure
struct Queue {
    int *items;  // Dynamic array for storing queue elements
    int head;    // Points to the front of the queue
    int tail;    // Points to the rear of the queue
    int size;    // Max size of the queue
};

// Function to create a queue with a given size
void createQueue(struct Queue* q, int size) {
    q->size = size;
    q->items = (int*)malloc(size * sizeof(int));
    q->head = -1;
    q->tail = -1;
    printf("Queue created with size %d!\n", size);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->head == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->tail == q->size - 1);
}

// Function to add an element to the queue (Enqueue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot add %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->head = 0;  // Initialize head for the first element
    }

    q->tail++;
    q->items[q->tail] = value;
    printf("Enqueued %d\n", value);
}

// Function to remove an element from the queue (Dequeue)
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    
    printf("Dequeued %d\n", q->items[q->head]);
    
    if (q->head == q->tail) {
        // Queue becomes empty after this operation
        q->head = -1;
        q->tail = -1;
    } else {
        q->head++;
    }
}

// Function to view the queue
void viewQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue contents: ");
    for (int i = q->head; i <= q->tail; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}
// Function to peek at the front element of the queue
void peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No element to peek.\n");
        return;
    }
    
    printf("Front element is %d\n", q->items[q->head]);
}
int main() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));  // Create a pointer to Queue
    int choice, value, size;

    // Get the queue size from the user
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    createQueue(q, size);  // Pass the queue pointer to the createQueue function

    // Menu-driven program
    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Peek Front Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(q, value);  // Use the queue pointer for enqueue
                break;
            case 2:
                dequeue(q);  // Use the queue pointer for dequeue
                break;
            case 3:
                viewQueue(q);  // Use the queue pointer for viewing the queue
                break;
            case 4:
                peek(q);  // Use the queue pointer for peeking
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    // Free the dynamically allocated memory for the queue
    free(q->items);
    free(q);

    return 0;
}