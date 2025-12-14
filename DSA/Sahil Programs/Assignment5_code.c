/*
Question 6:
Write a program to manage customer support tickets. Utilize a circular queue implemented using arrays to handle incoming support requests. Each ticket represents a customer support request, ensuring memory-efficient management. Implement features for ticket submission, processing, and displaying the current queue status
*/

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
int nextTicket = 1;   

int isFull() {
    return (front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front;
}

int isEmpty() {
    return front == -1;
}

void submitTicket() {
    if (isFull()) {
        printf("\nQueue is FULL! Cannot add more tickets.\n");
        return;
    }

    int ticketID = nextTicket++;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = ticketID;
    printf("\nTicket submitted successfully. Ticket ID: %d\n", ticketID);
}

void processTicket() {
    if (isEmpty()) {
        printf("\nNo tickets to process. Queue is EMPTY.\n");
        return;
    }

    printf("\nProcessing Ticket ID: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("\nQueue is EMPTY.\n");
        return;
    }

    printf("\nCurrent Tickets in Queue:\n");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Customer Support Ticket System =====\n");
        printf("1. Submit Ticket\n");
        printf("2. Process Ticket\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: submitTicket(); break;
            case 2: processTicket(); break;
            case 3: displayQueue(); break;
            case 4: printf("\nExiting...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}




