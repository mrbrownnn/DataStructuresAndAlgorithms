#include <bits/stdc++.h>
#define ll long long
#define faster() ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
const int MOD=1e9+7;

using namespace std;

int main()
{
    faster();
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w", stdout);
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i = 0; i < n; ++i) cin >>a[i];
        if(next_permutation(a,a+n)) for(int i = 0; i < n; ++i) cout <<a[i] <<' ';
        else for(int i = 0; i < n; ++i) cout <<i+1 <<' ';
        cout <<'\n';
    }

   return 0;
}

// Pham Van Thanh B21DCVT404 //