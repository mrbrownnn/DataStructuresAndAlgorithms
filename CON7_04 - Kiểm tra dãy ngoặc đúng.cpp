#include <bits/stdc++.h>

using namespace std;
void FileIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int t; cin >> t; 
	cin.ignore();
	while(t--){
		string str; getline(cin, str);
		stack <char> stk;
		bool ok = true;
		for(int i = 0; i < str.size(); i ++){
			if(str[i] == '{' || str[i] == '[' || str[i]=='(') 
				stk.push(str[i]);
			else if(str[i]=='}'){
				if(stk.empty()) ok = false;
				else if(stk.top()=='{') stk.pop();
				
			}
			else if(str[i]==']'){
				if(stk.empty()) ok = false;
				else if(stk.top()=='[') stk.pop();
			}
			else if(str[i]==')'){
				if(stk.empty()) ok = false;
				else if(stk.top()=='(') stk.pop();
			}
		}
		if(stk.size() > 0) 
			ok = false;
		if(ok) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}