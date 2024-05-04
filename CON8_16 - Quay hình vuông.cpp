#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int moves[6][2] = {{3, 0}, {0, 4}, {2, 1}, {4, 3}, {1, 5}, {5, 2}};

string rleft(string a)
{
    string b = "";
    for (int i = 0; i < 6; i++)
        b += a[moves[i][0]];
    return b;
}

string rright(string a)
{
    string b = "";
    for (int i = 0; i < 6; i++)
        b += a[moves[i][1]];
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        string a, b;
        int x;

        for (int i = 0; i < 6; i++)
        {
            cin >> x;
            a += to_string(x);
        }

        for (int i = 0; i < 6; i++)
        {
            cin >> x;
            b += to_string(x);
        }

        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({a, 0});

        while (!q.empty())
        {
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (curr == b)
            {
                cout << steps << endl;
                break;
            }

            string next = rleft(curr);
            if (visited.find(next) == visited.end())
            {
                visited.insert(next);
                q.push({next, steps + 1});
            }

            next = rright(curr);
            if (visited.find(next) == visited.end())
            {
                visited.insert(next);
                q.push({next, steps + 1});
            }
        }
    }

    return 0;
}