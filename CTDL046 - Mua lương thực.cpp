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
        int n, s, m;
        cin >> n >> s >> m;
        if (s * m > (s - s / 7) * n)
            cout << -1 << endl;
        else
        {
            for (int i = 1; i <= s - s / 7; i++)
            {
                if (n * i >= s * m)
                {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
}