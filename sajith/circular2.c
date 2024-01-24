#include <stdio.h>
#define MAX_SIZE 5 

int front = -1, rear = -1;
int queue[MAX_SIZE];

int is_empty() {
    return front == -1;
}

int is_full() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

void enqueue(int data) {
    if (is_full()) {
        printf("Queue is full. Cannot enqueue %d\n", data);
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = data;
        printf("%d enqueued to the queue\n", data);
    }
}

int dequeue() {
    int data = -1;
    if (is_empty()) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        data = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
        printf("%d dequeued from the queue\n", data);
    }
    return data;
}

int search(int value) {
    int i;
    if (is_empty()) {
        printf("Queue is empty. Cannot search.\n");
        return -1;
    } else {
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            if (queue[i] == value) {
                return i;
            }
        }
        if (queue[rear] == value) {
            return rear;
        }
        return -1;
    }
}

void display() {
    int i;
    if (is_empty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        if (front <= rear) {
            for (i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (i = front; i < MAX_SIZE; i++) {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, data, search_value;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                printf("Enter the value to search for: ");
                scanf("%d", &search_value);
                int index = search(search_value);
                if (index != -1) {
                    printf("Element found at index %d\n", index);
                } else {
                    printf("Element not found in the queue\n");
                }
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
