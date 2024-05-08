#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
   int n;
   cin>>n;
   vector<pair<int,int>>v;
   int x;
   char c;
   for(int i=1;i<=n;i++){
    while(scanf("%d%c",&x,&c)!=EOF){
        if(x>i){
        v.push_back({i,x});
        }
        if(c=='\n'){
            break;
        }
    }
   }
   for(auto it:v){
    cout<<it.first<<" "<<it.second<<endl;
   }
    return 0;
}