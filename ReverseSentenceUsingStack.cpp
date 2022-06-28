#include<iostream>
#include<stack>
using namespace std;

void ReverseString(string s){
                                                            //Stack:
    stack<string> st;                                       //you?
    for(int i=0; i<s.length(); i++){                        //are
        string w="";                                        //how 
        while(s[i]!=' ' && i<s.length()){                   //Hey,
            w+=s[i];
            i++;
        }
        st.push(w);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;
}


int main(){

string s="Hey, how are you?";
ReverseString(s);
return 0;
}