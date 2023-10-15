/*Linked list Implementation of Priority Queue */

/*
Name = Shaikh Masud
Roll No = 55
pid = 20
SE-IT
2023-24
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

PriorityQueue* initializePriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    if (pq) {
        pq->head = NULL;
    }
    return pq;
}

Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(PriorityQueue* pq, int data, int priority) {
    Node* newNode = createNode(data, priority);
    if (!pq->head || priority > pq->head->priority) {
        newNode->next = pq->head;
        pq->head = newNode;
    } else {
        Node* current = pq->head;
        while (current->next && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeue(PriorityQueue* pq) {
    if (!pq->head) {
        printf("Priority queue is empty.\n");
        return -1;
    }
    Node* temp = pq->head;
    int data = temp->data;
    pq->head = pq->head->next;
    free(temp);
    return data;
}

int isEmpty(PriorityQueue* pq) {
    return !pq->head;
}

void displayPriorityQueue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Priority queue is empty.\n");
    } else {
        Node* current = pq->head;
        printf("Priority Queue Elements: ");
        while (current) {
            printf("(%d, %d) ", current->data, current->priority);
            current = current->next;
        }
        printf("\n");
    }
}

void destroyPriorityQueue(PriorityQueue* pq) {
    while (!isEmpty(pq)) {
        dequeue(pq);
    }
    free(pq);
}

int main() {
    PriorityQueue* pq = initializePriorityQueue();

    int choice, data, priority;
    while (1) {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority to enqueue: ");
                scanf("%d %d", &data, &priority);
                enqueue(pq, data, priority);
                break;

            case 2:
                if (!isEmpty(pq)) {
                    int dequeuedData = dequeue(pq);
                    printf("Dequeued: %d\n", dequeuedData);
                } else {
                    printf("Priority queue is empty.\n");
                }
                break;

            case 3:
                displayPriorityQueue(pq);
                break;

            case 4:
                destroyPriorityQueue(pq);
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
