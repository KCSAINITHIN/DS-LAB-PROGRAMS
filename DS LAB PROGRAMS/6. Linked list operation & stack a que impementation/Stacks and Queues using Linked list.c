#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = temp->next;
    free(temp);
    return poppedValue;
}

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

int dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = *front;
    int dequeuedValue = temp->data;
    *front = temp->next;
    free(temp);
    return dequeuedValue;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;
    int choice, data;

    while(1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Enqueue to Queue\n");
        printf("4. Dequeue from Queue\n");
        printf("5. Display Stack\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to push to stack: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                printf("Popped from stack: %d\n", pop(&stack));
                break;
            case 3:
                printf("Enter data to enqueue to queue: ");
                scanf("%d", &data);
                enqueue(&queueFront, &queueRear, data);
                break;
            case 4:
                printf("Dequeued from queue: %d\n", dequeue(&queueFront));
                break;
            case 5:
                printf("Stack: ");
                printList(stack);
                break;
            case 6:
                printf("Queue: ");
                printList(queueFront);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
