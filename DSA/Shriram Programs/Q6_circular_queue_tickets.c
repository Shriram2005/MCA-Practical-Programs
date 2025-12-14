#include <stdio.h>

#define MAX 5

struct Ticket {
    int id;
};

struct Queue {
    struct Ticket arr[MAX];
    int front, rear, count;
};

void init(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(struct Queue *q) { return q->count == MAX; }
int isEmpty(struct Queue *q) { return q->count == 0; }

void enqueue(struct Queue *q) {
    if (isFull(q)) {
        printf("Queue full. Cannot add ticket.\n");
        return;
    }
    int id;
    printf("Enter ticket id: ");
    scanf("%d", &id);
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear].id = id;
    q->count++;
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("No tickets to process.\n");
        return;
    }
    struct Ticket t = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    printf("Processed ticket id: %d\n", t.id);
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue empty.\n");
        return;
    }
    printf("Current tickets: ");
    int i, idx = q->front;
    for (i = 0; i < q->count; i++) {
        printf("%d ", q->arr[idx].id);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    init(&q);
    int ch;
    do {
        printf("\n1.Submit Ticket 2.Process Ticket 3.Display Queue 4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: enqueue(&q); break;
        case 2: dequeue(&q); break;
        case 3: display(&q); break;
        case 4: printf("Exiting...\n"); break;
        default: printf("Invalid choice.\n");
        }
    } while (ch != 4);
    return 0;
}
