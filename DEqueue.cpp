#include <iostream> 
using namespace std;
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;

};

void create(struct Queue *q, int s)
{
    q->size=s;
    q->front=q->rear=-1;
    q->Q=new int[q->size];
}

void InsertfromRear(struct Queue *q, int x)
{
    if(q->rear==q->size-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

void Insertfromfront(struct Queue *q, int x)
{
    if(q->front==-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        q->Q[q->front]=x;
        q->front--;
    }
}

int DeleteFromFront(struct Queue *q)
{
    int x =-1;
    if(q->front==q->rear)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        q->front++;
        x=q->Q[q->front];
        return x;
    }
    return x;
}

int DeleteFromRear(struct Queue *q)
{
    int x =-1;
    if(q->front==q->rear)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        
        x=q->Q[q->rear];
        q->rear--;
        return x;
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
    create(&a, 7);
    InsertfromRear(&a, 10);
    InsertfromRear(&a, 20);
    InsertfromRear(&a, 30);
    InsertfromRear(&a, 40);
    InsertfromRear(&a, 50);
    InsertfromRear(&a, 60);

    DeleteFromFront(&a);
    DeleteFromFront(&a);
    DeleteFromFront(&a);
    
    Insertfromfront(&a, 100);
    Insertfromfront(&a, 200);
    Insertfromfront(&a, 300);

    display(a);

    return 0;
}
