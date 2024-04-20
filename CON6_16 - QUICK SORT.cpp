#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void Quicksort(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int test;
    cin>>test;
    while(test--){
    Quicksort();
    }
}