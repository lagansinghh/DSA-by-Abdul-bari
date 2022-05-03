#include <iostream> 
using namespace std;

struct node
{
    int data;
    node *l_child;
    node *r_child;
}*root=NULL;

void TreeFromTraversal(int p[], int in[])
{
    for (int j  = 0; j < 8; j++)
    {
        for (int i = 0; i < 8; i++)
    {
        if(p[j]==in[i])
        {
            node *t;
            t = new node;
            t->data=in[i];
        }
    }
    }
    
    
    
}

int main()
{
    int Pre[]={1,2,4,5,7,3,6,8};
    int in[]={4,2,7,5,1,8,6,3};

    return 0;
}
