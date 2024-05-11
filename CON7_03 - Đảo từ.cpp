#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {   vector<string>ans;
        string s;
        getline(cin,s);
        stack<char>st;
        int j;
        for(int i=0;i<s.size();i++){
          if(s[i]!=' '){
            j=i;
            while(j<s.size()&&s[j]!=' '){
                st.push(s[j]);
                j++;
            }
            string tmp="";
            while(!st.empty()){
                 //cout<<st.top();
                 tmp+=st.top();
                 st.pop();
            } 
            ans.push_back(tmp);        
            i=j-1;
             }
        }
        for(string x:ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}