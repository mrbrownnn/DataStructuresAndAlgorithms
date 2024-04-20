#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateSumTriangle(const vector<int>& A) {
    int n = A.size();
    vector<vector<int>> triangle(n);
    triangle[0] = A;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            triangle[i].push_back(triangle[i - 1][j] + triangle[i - 1][j + 1]);
        }
    }

    return triangle;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        vector<vector<int>> triangle = generateSumTriangle(A);

        for (const auto& row : triangle) {
            cout << "[";
            for (int i = 0; i < row.size(); i++) {
                cout << row[i];
                if (i != row.size() - 1) {
                    cout << " ";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}




// Pham Van Thanh B21DCVT404 //