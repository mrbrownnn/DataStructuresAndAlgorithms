#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n,m,check[1001],ans;
vector<int>adj[1001];
void init(){
  cin>>n>>m;
  ans=0;
  memset(check,0,sizeof(check));
  for(int i=0;i<1001;i++)adj[i].clear();
  for(int i=1;i<=m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}
void dfs(int u){
  check[u]=true;
  for(int x:adj[u]){
    if(!check[x]){
      dfs(x);
    }
  }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        for(int i=1;i<=n;i++){
          if(!check[i]){
            ans++;
            dfs(i);
          }
        }
        cout<<ans<<"\n";
    }
    return 0;
}