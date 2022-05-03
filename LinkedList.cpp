#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
} * first, *second, *third, *head;

void create(int a[], int n)
{
    struct node *t, *last;
    first = new struct node;
    first->data = a[0];
    first->next = 0;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new struct node;
        t->data = a[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}

void create2(int a[], int n)
{
    struct node *t, *last;
    second = new struct node;
    second->data = a[0];
    second->next = 0;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = new struct node;
        t->data = a[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int add(struct node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int RAdd(struct node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return RAdd(p->next) + p->data;
    }
}

struct node *Search(struct node *p, int key)
{
    // Here we are searching as well as bringing the found element to first position.
    // It will help to reduce time for searching the same element again.
    struct node *q;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            // cout<<p->data<<endl;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void Insert(struct node *p, int x, int index)
{
    struct node *t;

    if (index == 0)
    {

        t = new node;
        t->data = x;
        t->next = p;
        first = t;
    }
    else
    {

        t = new node;
        t->data = x;
        for (int i = 0; i < index - 1; i++)
        {

            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

void InsertLast(struct node *p, int x)
{
    // This will work only if you start inserting in list with zero node. It wont insert in an existing list on N nodes.
    node *last;
    node *t = new node;

    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {

        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void InsertinSortedList(struct node *p, int x)
{
    node *t, *q;
    t = new node;
    t->data = x;
    t->next = NULL;
    q = p;
    p = p->next;

    while (p != NULL)
    {
        if (p->data > t->data)
        {
            
            t->next=q->next;
            q->next=t;
            break;
        }

        q=p;
        p=p->next;
    }
    q->next=t;
    t->next=NULL;
}

void DeleteNode(struct node *p, int x)
{
    if (x == 1)
    {

        node *q = first;
        first = first->next;
        delete (q);
    }
    else
    {
        node *q, *r;
        q = first->next;
        r = first;
        for (int i = 2; i < x; i++)
        {
            r = q;
            q = q->next;
        }
        r->next = q->next;
        delete (q);
    }
}

int IsSorted(struct node *p)
{
    int x = -62000;
    node *q = first;
    while (q != NULL)
    {
        if (q->data < x)
        {
            return 0;
        }
        x = q->data;
        q = q->next;
    }
    return 1;
}

void RemoveDuplicates(struct node *q)
{

    //You need to if statement while traversing becasue if you dont, pointer will traverse also if they are duplicate nodes
    
    node *p = q->next;

    while (p != NULL)
    {
        if (q->data != p->data)
        {
            q = p;
            p = p->next;
        }

        else
        {
            q->next = p->next;
            delete (p);
            p = q->next;
        }
    }
}

//refer this to reverse list. Always see while revision
void reverse(struct node *p)
{
    node *q = NULL;
    node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }
    first = q;
}

void RecursiveReverse(struct node *q, struct node *p)
{

    if (p != NULL)
    {
        RecursiveReverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void Concatanate(struct node *p, struct node *q)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge(struct node *p, struct node *q)
{
    struct node *last;
    third = new node;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {

            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {

            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
}

int isLoop(struct node *p)
{

    node *q;
    q = first;

    while (q)
    {
        p = p->next;
        q = q->next;
        if (q == NULL)
        {
            q = q->next;
        }
        else
        {
            q = NULL;
        }

        if (q == p)
        {

            return 1;
        }
    }

    return 0;
}

// Circular Linked List(CLL)

void Create_CLL(int a[], int x)
{
    int i = 1;
    node *t, *last;
    head = new node;
    head->data = a[0];
    // head->next=NULL;
    last = head;
    // last->next=t;
    while (i < x)
    {
        t = new node;
        t->data = a[i];
        last->next = t;
        last = t;
        // t->next=NULL;

        i++;
    }
    last->next = head;
}

void Display_CLL(struct node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;

    } while (p != head);
    cout << endl;
}

void InsertinCLL(struct node *p, int x, int index)
{
    node *t;
    t = new node;
    t->data = x;

    if (index == 0)
    {

        while (p->next != head)
        {
            p = p->next;
        }
        p->next = t;
        t->next = head;
        head = t;
    }
    else
    {

        for (int i = 0; i < index - 1; i++)
        {

            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

int DeleteFromCLL(struct node *p, int index)
{
    node *q = NULL;
    for (int i = 0; i < index - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    int x = p->data;
    delete (p);
    return x;
}

// Doubly Linked List

struct D_node
{
    struct D_node *prev;
    int data;
    struct D_node *next;
} * D_first, *D_head;

void Create_DLL(int a[], int x)
{
    D_first = new D_node;
    D_first->data = a[0];
    D_first->next = D_first->prev = NULL;
    D_node *last, *t;
    last = D_first;
    for (int i = 1; i < x; i++)
    {
        t = new D_node;
        t->data = a[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void displayDLL(struct D_node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void InsertinDLL(struct D_node *p, int x, int index)
{
    D_node *t;
    t = new D_node;
    t->data = x;

    if (index == 0)
    {
        t->prev = NULL;
        t->next = D_first;
        D_first->prev = t;
        D_first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
        t->prev = p;
    }
}

int DeleteFromDLL(struct D_node *p, int index)
{
    D_node *q = NULL;
    for (int i = 0; i < index - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    int x = p->data;
    delete (p);
    return x;
}

void ReverseDLL(struct D_node *p)
{
    D_node *temp;
    while (p != NULL)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
        {
            D_first = p;
        }
    }
}

// Circular Doubly Linked List

void Create_CDLL(int a[], int x)
{
    D_node *last, *t;
    D_head = new D_node;
    D_head->data = a[0];
    D_head->prev = D_head;
    D_head->next = D_head;
    last = D_head;
    for (int i = 1; i < x; i++)
    {
        t = new D_node;
        t->data = a[i];
        t->prev = last;
        last->next = t;
        t->next = D_head;
        last = t;
    }
}

void Display_CDLL(struct D_node *p)
{
    int i = 10;
    do
    {
        cout << p->data << " ";
        p = p->next;
        i--;
    } while (p != D_head);
    cout << endl;
}

void Insert_CDLL(struct D_node *p, int index, int x)
{
    // Error

    D_node *t;
    t = new D_node;
    t->data = x;
    t->next = NULL;
    t->prev = NULL;

    if (index == 0)
    {
        t->next = D_head;
        t->prev = D_head->prev;
        D_head->prev = t;
        D_head = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->next = t;
        t->next = p->next;
        t->prev = p;
        // p->next->prev=t;
    }
}

// Student Challenge

void FindingMiddle(struct node *p)
{
    node *q = first;

    while (q->next != NULL)
    {

        q = q->next;
        if (q->next != NULL)
        {
            q = q->next;
        }
        else
        {
            break;
        }
        p = p->next;
    }
    cout << p->data << endl;
}

int main()
{
    int arr[7] = {1, 2, 4, 6, 11, 12, 23};
    int arr2[5] = {1, 2, 4, 10, 15};

    create(arr, 7);
    display(first);
    //    cout<<Search(first, 4);
    InsertinSortedList(first, 13);
    display(first);

    return 0;
}
