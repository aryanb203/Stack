#include<iostream>

using namespace std;
#define n 5

class stack{
    private:
    int *arr;
    int top;

    public:
    stack(){
        arr= new int[n];
        top=-1;
    }

    void push(int x){
        if(top==n-1)
            cout<<"Stack is full"<<endl;
        else{
            top++;
            arr[top]=x;
        }
    }
    
    void pop(){
        if(top==-1)
            cout<<"Stack is Empty"<<endl;
        else{
            cout<<arr[top]<<" is popped"<<endl;
            top--;
        }
    }

    int topEl(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else
            return arr[top];
    }

    bool empty(){
        return top==-1;
    }

};

int main(){

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.topEl()<<endl;
    st.pop();
    st.pop();
    cout<<st.topEl()<<endl;
    st.pop();
    st.pop();
    cout<<st.topEl()<<endl;
    cout<<st.empty()<<endl;

return 0;
}