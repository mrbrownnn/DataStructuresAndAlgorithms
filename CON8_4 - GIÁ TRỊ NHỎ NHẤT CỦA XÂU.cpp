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
        int k, x, n = 0;
        string s;
        cin >> k >> s;
        map<char, int> m;
        priority_queue<int> q;
        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;
        for (auto i : m)
            q.push(i.second);
        while (k--)
        {
            x = q.top();
            q.pop();
            q.push(x - 1);
        }
        while (q.size())
        {
            n += q.top() * q.top();
            q.pop();
        }
        cout << n << endl;
    }
}