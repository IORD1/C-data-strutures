#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){

    string s;
    stack<char> st;
    cin>>s;
    bool ans = false;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
            st.push(s[i]);
        }else if(s[i] == '('){
            st.push(s[i]);
        }else if(s[i] == ')'){
            if(st.top() == '('){
                ans = true;
            }
            while(st.top() == '+' or st.top() == '-' or s[i] == '*' or s[i] == '/'){
                st.pop();
            }
            st.pop();
        }
        
    }
cout<<ans<<endl;
}