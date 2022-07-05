#include<iostream>
#include "bits/stdc++.h"
using namespace std;

class StackQ{ //Implementing stack data structure using 2 queues while making the "PUSH" operation costly
    int n;
    queue<int> q1;
    queue<int> q2;

    

    public:
    StackQ(){
        n=0;
    }

    void push(int x){
        q1.push(x);
        n++;
        
    }

    void pop(){

        if(q1.empty() || n==0){
            cout<<"Stack is empty"<<endl;
            return;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        cout<<"popped"<<endl;
        n--; 
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        
    }

    int top(){
        if(q1.empty() || n==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int topval=q1.front();
        q2.push(topval);
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        return topval;
        
    }

    int size(){
        return n;
    }

};


int main(){

    StackQ s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    cout<<"Top element: "<<s.top()<<endl;
    cout<<"Size of stack: "<<s.size()<<endl;
    s.pop();
    cout<<"Top element: "<<s.top()<<endl;
    s.pop();
    cout<<"Top element: "<<s.top()<<endl;
    s.pop();
    cout<<"Top element: "<<s.top()<<endl;
    s.pop();
    cout<<"Size of stack: "<<s.size()<<endl;
    s.pop();
    cout<<"Top element: "<<s.top()<<endl;

    s.push(3);
    s.push(2);
    s.push(1);
    cout<<"Top element: "<<s.top()<<endl;

return 0;    
}
