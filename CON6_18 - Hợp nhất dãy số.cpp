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
      int n,m;
      cin>>n>>m;
      vector<int>v;
      for(int i=0;i<n+m;i++){
          int x;cin>>x;
          v.push_back(x);
      }
      sort(v.begin(),v.end());
      for(int &x:v)cout<<x<<" ";
      cout<<"\n";
    }
    return 0;
}