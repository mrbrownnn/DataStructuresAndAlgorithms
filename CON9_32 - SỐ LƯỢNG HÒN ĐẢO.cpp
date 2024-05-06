#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int n,m,ans,a[505][505];
int dx[8]= {1,0,-1,0,-1,-1,1,1};
int dy[8]= {0,1,0,-1,-1,1,-1,1};
void init(){
  cin>>n>>m;
  ans=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>a[i][j];
    }
  }
}
void dfs(int i,int j){
    a[i][j]=0;
    for(int k=0;k<8;k++){
      int i1=i+dx[k];
      int j1=j+dy[k];
      if(i1>=1&&i1<=n&&j1>=1&&j1<=m&&a[i1][j1]){
        dfs(i1,j1);
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
          for(int j=1;j<=m;j++){
            if(a[i][j]){
              ans++;
              dfs(i,j);
            }
          }
        }
        cout<<ans<<"\n";
    }
    return 0;
}