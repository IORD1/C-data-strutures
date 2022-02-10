#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int get_max_area(vector<int> a){
    int n = a.size()  , ans = 0, i =0;
    a.push_back(0);
    stack<int> st;
    while(i<n){
        while(!st.empty() and a[st.top()] > a[i]){      //if the stack is empty or 
            int t = st.top();                           //stroing stack's top in t
            int h = a[t];                               //storing a[stack's top part]
            st.pop();                                   //pop the only top
            if(st.empty()){                             //check whether stack is empty  
                ans = max(ans, h*i);                    //if yes, then markd ans as max of past ans or lenght(1)*h
            }else{                                      //else
                int len = i - st.top() -1;              //store len with neww length
                ans = max(ans, h*len); 
            }
        }
        st.push(i); 
        i++;
    }
    return ans;
}

int main(){
    vector<int> a = {2,1,5,6,2,3};
    cout<<get_max_area(a)<<endl;
    return 0;
}