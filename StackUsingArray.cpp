#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *s; // we declare variable dynamically into the heap
};

void create(struct Stack *st)
{
    cout << "Enter size of Stack"
         << " ";
    cin >> st->size;
    st->top = -1;
    st->s = new int[st->size];
}

void Display(struct Stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << " ";
    }
    cout << endl;
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x;
    x = st->s[st->top--];
    return x;
}

int peek(struct Stack st, int index)
{
    //returns the value without deleting it.
    int x = -1;
    if (index + 1 > st.top)
    {
        cout << "Invalid Index" << endl;
    }
    else
    {
        x = st.s[index];
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int StackTop(struct Stack st)
{
    if (!isEmpty(st))
    {
        return st.s[st.top];
    }
    else
    {
        return -1;
    }
}

int main()
{
    struct Stack a;
    create(&a);

    push(&a, 10);
    push(&a, 20);
    push(&a, 30);
    push(&a, 40);
    push(&a, 50);

    // pop(&a);
    cout<<StackTop(a)<<endl;
    

    // pop(&a);
    // Display(a);

    return 0;
}
