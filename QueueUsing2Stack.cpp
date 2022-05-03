#include <iostream> 
#include <stack>
using namespace std;



void enqueue( stack <int> *s1, int x)
{
    s1->push(x);
}

int dequeue(stack <int> *s1,stack <int> *s2)
{
    int x=-1;
    if(s2->empty())
    {
        if(s1->empty())
        {
            cout<<"Queue is empty"<<endl;
            return x;
        }
        else
        {
            while(!s1->empty())
            {
            x=s1->top();
            s1->pop();
            s2->push(x);
            }

        }
    }
    x=s2->top();
    s2->pop();
    return x;
}

void display(stack <int> s)
{
   //it displays the element in given stack
   while (!s.empty())
   {
       cout<<s.top()<<" ";
       s.pop();
       
   }
   cout<<endl;
   
    
}


int main()
{
    stack <int> st1, st2;

    enqueue(&st1,10);
    enqueue(&st1,20);
    enqueue(&st1,30);
    enqueue(&st1,40);
    enqueue(&st1,50);
    enqueue(&st1,60);
    enqueue(&st1,70);
    enqueue(&st1,80);

    display(st1);

    cout<<dequeue(&st1,&st2)<<endl;
    cout<<dequeue(&st1,&st2)<<endl;
    cout<<dequeue(&st1,&st2)<<endl;

    display(st2);
    


    return 0;
}
