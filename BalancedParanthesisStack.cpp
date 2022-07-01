#include<iostream>
#include<stack>
#include<string>
using namespace std;

int IsValid(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){

    if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
    else if(s[i]==')' && st.top()=='(')
        st.pop();
    else if(s[i]=='}' && st.top()=='{')
        st.pop();
    else if(s[i]==']' && st.top()=='[')
        st.pop();

    }

    if(st.empty())
        return 1;
    else
        return 0;
}

int main(){
    cout<<IsValid("{(})");

return 0;
}