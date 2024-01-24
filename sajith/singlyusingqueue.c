#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

// Function prototypes
struct Node* createNode(int data);
struct Queue* createQueue();
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int data);
int dequeue(struct Queue* queue);
void display(struct Queue* queue);
int search(struct Queue* queue, int key);

int main() {
    struct Queue* queue = createQueue();
    int choice, value, key, result;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;

            case 2:
                if (!isEmpty(queue)) {
                    printf("Dequeued element: %d\n", dequeue(queue));
                } else {
                    printf("Queue is empty\n");
                }
                break;

            case 3:
                if (!isEmpty(queue)) {
                    printf("Enter the key to search: ");
                    scanf("%d", &key);
                    result = search(queue, key);
                    if (result != -1) {
                        printf("%d found at position %d\n", key, result);
                    } else {
                        printf("%d not found in the queue\n", key);
                    }
                } else {
                    printf("Queue is empty\n");
                }
                break;

            case 4:
                if (!isEmpty(queue)) {
                    display(queue);
                } else {
                    printf("Queue is empty\n");
                }
                break;

            case 5:
                printf("Exiting the program\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enqueued\n", data);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }

    struct Node* temp = queue->front;
    int data = temp->data;

    queue->front = temp->next;

    
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    return data;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* current = queue->front;

    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int search(struct Queue* queue, int key) {
    int position = 1;
    struct Node* current = queue->front;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;  
}
