#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int &x:a)cin>>x;
        int cnt=0;
        for(int i=0;i<n-1;i++){
          for(int j=i+1;j<n;j++){
            if(abs(a[j]-a[i])<k){
              cnt++;
            }
          }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}