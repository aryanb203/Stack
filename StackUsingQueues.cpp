#include<iostream>
#include "bits/stdc++.h"
using namespace std;

class StackQ{ //Implementing stack data structure using 2 queues while making the "POP" operation costly
    int n;
    queue<int> q1;
    queue<int> q2;

    

    public:
    StackQ(){
        n=0;
    }
    void push(int x){
        q2.push(x);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
            queue<int> temp=q1;
            q1=q2;
            q2=temp;
        
    }

    int pop(){

        if(!q1.empty()){
        int popped=q1.front();
        q1.pop(); 
        n--;
        return popped;
        }

        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        } 
        
    }

    int top(){
        return q1.front();
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
    cout<<"popped: "<<s.pop()<<endl;
    cout<<"popped: "<<s.pop()<<endl;
    cout<<"popped: "<<s.pop()<<endl;
    cout<<"Top element: "<<s.top()<<endl;
    cout<<"popped: "<<s.pop()<<endl;
    cout<<"Size of stack: "<<s.size()<<endl;
    cout<<"popped: "<<s.pop()<<endl;

return 0;    
}