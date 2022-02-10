#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
//brute force methode O(N3)
    // int n = 10; //sixe of array
    // int arr[n];
    // for(int i=0; i<n;i++){
    //     for(int k=i; k<n;k++){
    //         for(int k=j+1; k<n; k++){
    //             if(arr[i] + arr[j]+ arr[k] == traget){
    //                 found = true;
    //             }
    //         }
    //     }
    // }

    //effienct method:

    int n;
    cin>>n;
    int traget; cin>>traget;
    vector<int> a(n);
    for(auto &i : a){
        cin>>i;
    }
    bool found = false;
    sort(a.begin(), a.end());
    for(int i=0; i<n;i++){
        int lo = i+1;
        int hi = n-1;
        while(lo<hi){
            int current = a[i] +a[lo] +a[hi];
            if(current == traget){
                found = true;
            }
            if(current<traget){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    if(found)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}