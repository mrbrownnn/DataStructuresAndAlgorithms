#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	set<pair<int, int>> m;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		s += ' ';
		int k = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] >= '0' && s[j] <= '9')
			{
				k = k * 10 + s[j] - '0';
			}
			else
			{
				int a = i + 1, b = k;
				if (a > b)
					swap(a, b);
				m.insert(make_pair(a, b));
				k = 0;
			}
		}
	}
	for (auto i : m)
	{
		cout << i.fi << " " << i.se << endl;
	}
}