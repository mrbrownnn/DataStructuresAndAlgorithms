#include <bits/stdc++.h>
#define pb push_back
const int MOD=1e9+7;

using namespace std;

int main()
{
    iosbase::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while (t--){
        string s;
        cin >>s;
        int n = s.size();
        for(int i = 0; i < n; ++i) if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' -'A';
        int dp[404]={}, mx=-1e9;
        for(int i = 0; i < n; ++i){
            dp[s[i]] = max(dp[s[i]], 1);
            for(int j = 'a'; j < s[i]; ++j){
                dp[s[i]] = max(dp[s[i]], dp[j]+1);
            }
            mx = max(mx, dp[s[i]]);
        }
        cout <<mx <<'\n';

	}
	return 0;
}