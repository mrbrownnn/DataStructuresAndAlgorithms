#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define f(i,a,b) for(int i=a; i<=b; ++i)
#define fn(i,a,b) for(int i=a; i>=b; --i)
const int MOD=1e9+7;
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t--){
        string a,b;
        cin.ignore();
        cin>>a>>b;
        int c1=0,d1=0,c2=0,d2=0;
        for(int i=0;i<a.length();i++){
            if(a[i]=='3') a[i]='5';
            c1=c1*10+a[i]-48;
        }
        for(int i=0;i<b.length();i++){
            if(b[i]=='3') b[i]='5';
            c2=c2*10+b[i]-48;
        }
        c1+=c2;
        for(int i=0;i<a.length();i++){
            if(a[i]=='5') a[i]='3';
            d1=d1*10+a[i]-48;
        }
        for(int i=0;i<b.length();i++){
            if(b[i]=='5') b[i]='3';
            d2=d2*10+b[i]-48;
        }
        d1+=d2;
        cout<<d1<<" "<<c1<<'\n';
    }
    return 0;
}