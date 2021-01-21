/*Stack in c++ code*/
#include<bits/stdc++.h>
#define MAX 5
using namespace std;

class Stack
{
public:
    int arr[MAX],top;
    Stack()
    {
        top=-1;
    }
    int isFull();
    int isEmpty();
    void push(int x);
    void pop();
};

int Stack::isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

int Stack::isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void Stack::push(int x)
{
    if(isFull())
        cout<<"The Stack is Full\n";
    else
    {
        top++;
        arr[top]=x;
    }
}

void Stack::pop()
{
    if(isEmpty())
        cout<<"The Stack is Empty\n";
    else
    {
        cout<<arr[top]<<endl;
        top--;
    }
}

int main()
{
    cout<<"Stack"<<endl<<endl;

    Stack ob;

    ob.push(10);
    ob.push(20);
    ob.push(30);
    ob.push(40);
    ob.push(50);
    ob.push(60);
    ob.push(70);

    ob.pop();
    ob.pop();

    cout<<endl;
    return 0;
}
