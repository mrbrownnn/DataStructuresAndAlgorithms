#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n < 4) cout << -1 ;
        else {
            for(int i = 0 ; i < (1 << n) ; i ++){
                string s = bitset<32>(i).to_string();
                s = s.substr(32-n);
                size_t first = s.find("01");
                size_t second = s.find("01",first + 2);
                if(first != string::npos && second != string::npos && s.find("01",second + 2) == string :: npos) cout << s << " ";
			}
            cout << endl;
        }
    }
    return 0;
}