#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *l_child;
    node *r_child;
} *root = NULL;

void create()
{
    node *p, *t;
    queue<node *> q;

    root = new node;
    cout << "Enter the Root value" << endl;
    cin >> root->data;
    root->l_child = root->r_child = NULL;

    q.push(root);
    while (!q.empty())
    {
        int x;
        p = q.front();
        q.pop();
        cout << "Enter the Value of left child of " << p->data << " ";

        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->l_child = t->r_child = NULL;
            p->l_child = t;
            q.push(t);
        }
        cout << "Enter the Value of right child of " << p->data << " ";
        cin >> x;
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->r_child = t->l_child = NULL;
            p->r_child = t;
            q.push(t);
        }
    }
}

void Preorder(struct node *p)
{

    if (p)
    {
        cout << p->data << " ";
        Preorder(p->l_child);
        Preorder(p->r_child);
    }
}

void Inorder(struct node *p)
{
    if (p)
    {
        Inorder(p->l_child);
        cout << p->data << " ";
        Inorder(p->r_child);
    }
}

void IterativePreorder(struct node *p)
{
    stack<node *> s;
    cout << "Preorder Traversal of given Tree is: ";
    while (!s.empty() || p != NULL)
    {
        if (p)
        {
            s.push(p);
            cout << p->data << " ";
            p = p->l_child;
            // s.push(p);
            // cout<<p->data<<endl;
        }
        else
        {

            p = s.top();
            s.pop();
            p = p->r_child;
        }
    }
    cout << endl;
}

void IterativeInorder(struct node *p)
{
    cout << "Inorder Traversal is given Tree: ";
    stack<node *> s;
    while (!s.empty() || p != NULL)
    {
        if (p)
        {
            s.push(p);
            p = p->l_child;
        }
        else
        {

            p = s.top();
            s.pop();
            cout << p->data << " ";
            p = p->r_child;
        }
    }
    cout << endl;
}

void LevelOrder(struct node *p)
{
    cout << "Level order Traversal: ";
    node *t;
    queue<node *> q;
    q.push(p);

    cout << p->data << " ";
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        if (t->l_child)
        {
            cout << t->l_child->data << " ";
            q.push(t->l_child);
        }
        if (t->r_child)
        {
            cout << t->r_child->data << " ";
            q.push(t->r_child);
        }
    }
}

int CountNode(node *p)
{
    if (p)
    {
        return CountNode(p->l_child) + CountNode(p->r_child) + 1;
    }
    return 0;
}

int Height(node *p)
{
    //incomplete
    if(p)
    {
        int x=0,y=0;

        if(root==0)
        {
            return 0;
        }
        
        x=Height(p->l_child);
        y=Height(p->r_child);
        
        if(x>y)
        return x+1;
        else
        return y+1;
        
    }
}

int main()
{
    create();
    cout << "Preorder Traversal of given Tree is: ";
    Preorder(root);
    cout << endl;
    IterativePreorder(root);
    IterativeInorder(root);
    cout << "Inorder Traversal of given Tree is: ";
    Inorder(root);
    cout << endl;
    LevelOrder(root);
    cout << endl;
    cout << "The number of node in this Tree is: " << CountNode(root) << endl;
    cout << "The height of this Tree is: " << Height(root) << endl;
    return 0;
}
