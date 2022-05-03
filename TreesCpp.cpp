//Incomplete
#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *l_child;
    node *r_child;
};

class Tree
{
private:
    node *p;

public:
    void create();
    void display();
};

void Tree ::create()
{
    node *t, *r;
    p = new node;
    queue<node *> q;
    q.push(p);

    cout << "Enter the root value"<< " ";
         

    cin >> p->data;
    while (!q.empty())
    {
        int x;
        r=q.front();
        q.pop();
        cout << "Enter the Value of left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            
            t->data = x;
            q.push(t);
            r->l_child = t;
        }
        cout << "Enter the Value of right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            
            t->data = x;
            q.push(t);
            r->r_child = t;
        }
       
    }
}

void Tree :: display()
{
    cout<<"Level order Traversal: ";
    node *t,*p;
    queue<node *> q1;
    q1.push(p);
    t=q1.front();
    q1.pop();
    cout<<t->data<<" ";
    while(t!=NULL || !q1.empty())
    {
        cout<<t->l_child->data<<" ";
        q1.push(t->l_child);
        cout<<t->r_child->data<<" ";
        q1.push(t->r_child);
        t=q1.front();
        q1.pop();

    }
}

int main()
{
    Tree t;
    t.create();
    t.display();
    return 0;
}
