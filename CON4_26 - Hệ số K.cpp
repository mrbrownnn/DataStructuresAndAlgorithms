#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string add(string a,string b,int k){
  while(a.size()<b.size())a="0"+a;
  while(b.size()<a.size())b="0"+b;
  int nho=0,l=a.size();
  string ans="";
  for(int i=l-1;i>=0;i--){
    int so=a[i]-'0'+b[i]-'0'+nho;
    nho=so/k;
    ans=(char)(so%k+'0')+ans;
  }
  if(nho>0)ans=(char)(nho+'0')+ans;
  return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a,b;
        int k;
        cin>>k>>a>>b;
        cout<<add(a,b,k)<<"\n";
    }
    return 0;
}