#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        int n, k;
        cin >>n;
        stack<int> st;
        queue<int> q;
        f(i,1,n){
            int x;
            cin >>x;
            st.push(x);

        }
        while(!st.empty()){
            cout <<st.top() <<' ';
            st.pop();
        }
        cout <<'\n';
    }


   return 0;
}