#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

class Queue
{
private:
    int size;
    int *Q;

public:
    Queue(int s)
    {
        size = s;
        Q = new int[size];
    }

    void enqueue(int x)
    {
        node *t;
        t = new node;
        if (t == NULL)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            t->data = x;
            t->next = NULL;
            if (front == NULL)
            {
                front = rear = t;
            }
            else
            {
                rear->next = t;
                rear = t;
            }
        }
    }
    int dequeue()
    {
        int x = -1;
        if (front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            node *p;
            p = front;
            x = front->data;
            front = front->next;
            delete (p);
        }
        return x;
    }
    void display()
    {
        node *p = front;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q(7);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    q.display();

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    
    q.display();

    return 0;
}
