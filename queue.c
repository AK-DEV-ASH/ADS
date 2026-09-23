#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int ele) {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = ele;
    } else {
        rear++;
        queue[rear] = ele;
    }
}

int dequeue(void) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1; /* sentinel for empty */
    }

    int ele = queue[front];
    if (front == rear) {
        /* last element removed */
        front = rear = -1;
    } else {
        front++;
    }
    return ele;
}

void display(void) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; ++i) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(void) {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued: %d\n", dequeue());
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60); 
    display();

    return 0;
}
