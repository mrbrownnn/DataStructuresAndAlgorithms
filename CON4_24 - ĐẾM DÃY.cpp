#include <iostream>
using namespace std;

long long countSequences(int n) {
    long long dp[n+1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] = (dp[i] + dp[i-j]) % 123456789;
        }
    }
    return dp[n];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << countSequences(n) << endl;
    }
    return 0;
}