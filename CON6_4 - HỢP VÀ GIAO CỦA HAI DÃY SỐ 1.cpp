#include <bits/stdc++.h>
using namespace std;


int main(){

	
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> a(n);
		set<int> st, sm;
		for(int i = 0; i < n; i ++){
			cin >> a[i];
			st.insert(a[i]);
		}
		int k = 0;
		for(int i = 1; i <= m; i ++){
			int x; cin >> x;
			st.insert(x);
			if(n + i - st.size() - k != 0){
				sm.insert(x);
				k++;
			}
		}
		for(auto x: st) cout << x << " ";
		cout << endl;
		for(auto x: sm) cout << x << " ";
		cout << endl;
	}
	return 0;
}