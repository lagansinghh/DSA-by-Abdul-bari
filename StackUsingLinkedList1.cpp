#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    char data;
    struct node *next;
} *top = NULL;

void display(struct node *st)
{
    node *p;
    p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void push(struct node *st, char x)
{
    node *t;
    t = new node;
    t->data = x;
    t->next = top;
    top = t;
}

int pop(struct node *st)
{
    node *t;
    int x;
    t = top;
    top = top->next;
    x = t->data;
    delete (t);
    return x;
}

int peek(struct node *st, int index)
{
    node *p;
    p = top;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    return p->data;
}

int isEmpty(struct node *st)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node *st)
{
    node *t;
    t = new node;
    if (t == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int parenthensisMatching(char *exp)
{
    int i = 0;
    // node *st;
    top = new node;
    top = NULL;

    while (exp[i] != NULL)
    {
        if (exp[i] == '(')
        {

            push(top, exp[i]);
        }

        else if (exp[i] == ')')
        {

            if (isEmpty(top))
            {
                return 0;
            }

            pop(top);
        }
        i++;
    }
    if (isEmpty(top))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int priority(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }

    return 0;
}

char *infixTopostfix(char *exp)
{
    // error
    int i = 0, j = 0;
    char *postfix;
    postfix = new char[strlen(exp)+1];
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isOperand(exp[i]))
        {
            postfix[i++] = exp[j++];
        }
        else
        {
            if (priority(exp[j]) > priority(top->data))
            {
                push(top, exp[j++]);
            }
            else
            {
                postfix[i++] = pop(top);
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop(top);
    }
    postfix[j] = '\0';

    return postfix;
}
int main()
{
    char *exp = "a+b*c";
    push(top,'#');
    cout<<exp<<endl;
    cout << infixTopostfix(exp) << endl;
    

    // cout << priority('+') << endl;
    // cout << priority('*') << endl;

    display(top);

    return 0;
}
