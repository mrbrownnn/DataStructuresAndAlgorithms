#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, x, a[10] = {};
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			while (x != 0)
			{
				int k = x % 10;
				a[k]++;
				x /= 10;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			if (a[i] > 0)
				cout << i << " ";
		}
		cout << endl;
	}
}