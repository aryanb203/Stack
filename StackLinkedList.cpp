#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class stack
{
public:
    Node *top;

    stack() { top = NULL; }
    void push(int x);
    void pop();
    void Display();
};

void stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack is Full" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

void stack::pop()
{

    if (top == NULL)
        cout << "Stack is Empty" << endl;
    else
    {
        cout << top->data << " is popped" << endl;
        Node *t = top;
        top = top->next;
        t = NULL;
        delete t;
    }
}

void stack::Display()
{
    Node *t = top;


    while (t != NULL)
    {
        cout << t->data <<" ";
        t=t->next;
    }
    cout << endl;
}

int main()
{
    stack st;
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.Display();
    st.pop();
    st.pop();
    st.Display();

    return 0;
}