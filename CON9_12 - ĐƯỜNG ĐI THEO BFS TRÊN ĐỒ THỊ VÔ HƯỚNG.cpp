#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n,m,s,t,check[1001];
int par[1001];
vector<int>adj[1001];
void init(){
  cin>>n>>m>>s>>t;
  memset(check,0,sizeof(check));
  for(int i=0;i<1001;i++)adj[i].clear();
  memset(par,0,sizeof(par));
  for(int i=1;i<=m;i++){
    int x,y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
}
void bfs(int u,int p){
  check[u]=true;
  queue<int>q;
  q.push(u);
  while(!q.empty()){
    int v=q.front();
    q.pop();
  for(int x:adj[v]){
    if(!check[x]){
      par[x]=v;
      check[x]=true;
      q.push(x);
    }
  }
  }
}
void solve(){
  bfs(s,0);
  vector<int>path;
  if(!check[t]){
    cout<<"-1\n";
  }
  else{
    while(t!=s){
      path.push_back(t);
      t=par[t];
    }
    path.push_back(s);
    reverse(path.begin(),path.end());
    for(int x:path)cout<<x<<" ";
    cout<<"\n";
  }
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        init();
        solve();
    }
    return 0;
}