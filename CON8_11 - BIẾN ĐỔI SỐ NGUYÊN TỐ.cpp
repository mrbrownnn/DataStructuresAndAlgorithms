#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int minSteps(int S, int T) {
    if (S == T) {
        return 0;
    }
    vector<bool> visited(10000, false);
    queue<pair<int, int>> q;
    q.push({S, 0});
    visited[S] = true;
    while (!q.empty()) {
        int curr = q.front().first;
        int steps = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int digit = (curr / (int)pow(10, i)) % 10;
            for (int j = 0; j <= 9; j++) {
                int next = curr + (j - digit) * pow(10, i);
                if (next >= 1000 && next <= 9999 && !visited[next] && isPrime(next)) {
                    if (next == T) {
                        return steps + 1;
                    }
                    q.push({next, steps + 1});
                    visited[next] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int S, T;
        cin >> S >> T;
        cout << minSteps(S, T) << endl;
    }
    return 0;
}