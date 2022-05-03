#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int front = -1;
    int rear = -1;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[size];
}

void enqueue(struct Queue *q, int x)
{

    if (q->rear == q->size - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {

        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->rear == q->front)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}
void display(struct Queue q)
{
    for (int i = q.front+1; i <= q.rear; i++)
    {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}
int main()
{
    Queue a;

    cout << "Enter the Size of Queue"
         << " ";
    cin >> a.size;
    create(&a, a.size);
    enqueue(&a, 10);
    enqueue(&a, 20);
    enqueue(&a, 30);
    enqueue(&a, 40);
    enqueue(&a, 50);
    display(a);

    

    cout<<dequeue(&a)<<endl;
    cout<<dequeue(&a)<<endl;
    cout<<dequeue(&a)<<endl;

    display(a);

    return 0;
}
