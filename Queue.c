//Aim: Implementation of queue 
/* Algorithm:
queue[MAX] be an array of size MAX.

front and rear be two integer pointers initialized as -1.
front = -1
rear = -1
Algorithm Enqueue(x):
1. If (rear == MAX - 1)
       print "Queue Overflow"
       return
2. If (front == -1)       // Empty queue
       front = 0
3. rear = rear + 1
4. queue[rear] = x
5. print x, "inserted into queue"
Algorithm Dequeue():
1. If (front == -1 OR front > rear)
       print "Queue Underflow"
       return
2. x = queue[front]
3. front = front + 1
4. If (front > rear)
       front = rear = -1    // Reset queue
5. print x, "deleted from queue"
Algorithm Front():
1. If (front == -1)
       print "Queue is empty"
   else
       print "Front element =", queue[front]
Algorithm isEmpty():
1. return (front == -1)
  */
#include <stdio.h>
#define MAX 100
typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Queue;
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue *q) {
    return q->front == -1;
}
int isFull(Queue *q) {
    return (q->rear + 1) % MAX == q->front;
}
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;  // Indicate error
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        // Queue has only one element, reset after dequeue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

int main() {
    Queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Front element is %d\n", peek(&q));
    printf("Dequeued element is %d\n", dequeue(&q));
    printf("Dequeued element is %d\n", dequeue(&q));
    if (isEmpty(&q)) {
        printf("Queue is empty now\n");
    } else {
        printf("Queue is not empty\n");
    }
    return 0;
}
