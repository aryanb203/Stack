#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char c){ //to check precedence of the operator
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else if(c=='^')
        return 3;
    else 
        return -1;

}

string InfixToPostfix(string s){

    stack<char> st;
    string res=""; //resultant string

    for(int i=0; i<s.length(); i++){
        if(s[i]>='a'&& s[i]<='z' || s[i]>='A'&& s[i]<='Z' ){   //if the character is operand
            res+=s[i];
        }
        else if(s[i]=='(') //if the char is opening brackets
            st.push(s[i]);
        else if(s[i]==')'){ //if the char is closing brackets
            while(!st.empty() && st.top()!='('){  //while the stack is not empty and we dont find opening brackets in the stack
                res+=st.top();
                st.pop();
            }
            if(!st.empty()) //poppint the opening brackets without including them into resultant
                st.pop();
        }
        else{ //is the char is an operator
            while(!st.empty() && precedence(st.top())>precedence(s[i])){ //adding to the resultant string until we find an operator with higher precedence
                res+=st.top();
                st.pop();
            }
            st.push(s[i]); //pushing the operator with higher precedence
        }
    }

    while(!st.empty()){ //adding the rest of the remaining characters in the stack to the resultant string 
        res+=st.top();
        st.pop();
    }
    return res;
}


int main(){

    cout<<InfixToPostfix("(a-b/c)*(a/k-l)")<<endl;
}