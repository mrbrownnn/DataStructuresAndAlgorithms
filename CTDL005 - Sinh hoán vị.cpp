#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(vector<int>& current, vector<bool>& used, int n) {
    if (current.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << current[i];
        }
        cout << " ";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            current.push_back(i);
            used[i] = true;
            generatePermutations(current, used, n);
            current.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> current;
        vector<bool> used(n + 1, false);

        generatePermutations(current, used, n);
        cout << endl;
    }

    return 0;
}