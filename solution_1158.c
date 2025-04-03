#include <stdio.h>
#include <stdlib.h>

#define QUE_LEN 1000
typedef int Data;

typedef struct _cQueue {
    int front;
    int rear;
    Data queArr[QUE_LEN];
} Queue;

void QueueInit(Queue *pq) {
    pq->front = 0;
    pq->rear = 0;
}

int NextPosIdx(int pos) {
    return (pos + 1) % QUE_LEN;
}

int IsEmpty(Queue *pq) {
    return pq->front == pq->rear;
}

int IsFull(Queue *pq) {
    return NextPosIdx(pq->rear) == pq->front;
}

void Enqueue(Queue *pq, Data data) {
    if (IsFull(pq)) return; // 큐가 꽉 찼을 경우
    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue *pq) {
    if (IsEmpty(pq)) return -1; // 큐가 비었을 경우
    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    Queue q;
    QueueInit(&q);

    for (int i = 1; i <= N; i++) {
        Enqueue(&q, i);
    }

    printf("<");
    while (!IsEmpty(&q)) {
        for (int i = 1; i < K; i++) {
            Enqueue(&q, Dequeue(&q));
        }
        printf("%d", Dequeue(&q));
        if (!IsEmpty(&q)) printf(", ");
    }
    printf(">\n");

    return 0;
}
