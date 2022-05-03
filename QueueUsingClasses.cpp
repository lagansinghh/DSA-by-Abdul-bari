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
        front = rear = -1;
        Q = new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue :: dequeue()
{
    int x;
    if(front==rear)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        
        front++;
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
    Queue q(5);
    // int size;
    // cout<<"Enter size"<<" ";
    // cin>>size;
    // Queue(size);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout<<q.dequeue()<<endl;

    q.display();



    return 0;
}
