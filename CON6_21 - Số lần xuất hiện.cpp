#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool cmp(pair<int,int>a,pair<int,int>b){
  if(a.second==b.second) return a.first<b.first;
  return a.second>b.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
      int n;
      cin>>n;
      int a[n];
      map<int,int>mp;
      for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
      }
      int l=mp.size();
      pair<int,int>p[l];
     int i=0;
     for(auto it:mp){
      p[i++]=make_pair(it.first,it.second);
     }
     sort(p,p+l,cmp);
     for(int i=0;i<l;i++){
      for(int j=0;j<p[i].second;j++){
        cout<<p[i].first<<" ";
      }
     }
     cout<<"\n";
    }
    return 0;
}