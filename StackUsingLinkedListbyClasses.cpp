#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class stack
{
private:
    node *top;

public:
    stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    void display();
};

void stack::push(int x)
{
    node *t = new node;
    t->data = x;
    t->next = top;
    top = t;
}

int stack::pop()
{
    int x;
    node *t;
    x = top->data;
    t = top;
    top = top->next;
    delete (t);
    return x;
}

void stack::display()
{
    node *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    stack st;
    // stack();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.display();

    cout << st.pop() << endl;
    cout << st.pop() << endl;

    st.display();

    return 0;
}
