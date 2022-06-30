#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

int prefixEval(string s){

    stack<int> st;

    for(int i=s.length()-1; i>=0; i--){
        if(s[i]>='0' && s[i]<='9' ){  //if the character is an operand
            st.push(s[i]-'0');        //to push as integer value
        }
        else{

            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch (s[i])    //if operator appears
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;

            }
        }
    }
    return st.top();

}

int postfixEval(string s){

    stack<int> st;

    for(int i=0; i<s.length(); i++){
        if(s[i]>='0' && s[i]<='9' ){  //if the character is an operand
            st.push(s[i]-'0');        //to push as integer value
        }
        else{

            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch (s[i])    //if operator appears
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op2-op1);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op2/op1);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;

            }
        }
    }
    return st.top();

}


int main(){
    string in;
    cout<<"Enter the prefix expression: ";
    cin>>in;
    cout<<prefixEval(in)<<endl;
    cout<<"Enter the postfix expression: ";
    cin>>in;
    cout<<postfixEval(in)<<endl;
    return 0;
}