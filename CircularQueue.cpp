#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int s)
    {
        size = s;
        front = rear = 0;
        Q =new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue :: enqueue(int x)
{
    if((rear+1)%size==front)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

int Queue :: dequeue()
{
    int x;
    if(rear== front)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        front=(front+1)%size;
        x=Q[front];
    }
    return x;
}

void Queue :: display()
{
    for (int i = front +1; i <= rear; i++)
    {
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Queue q(7);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    

    q.display();

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    q.display();
    

    

    return 0;
}
