#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateSpecialTriangle(vector<int> A) {
    vector<vector<int>> triangle;
    triangle.push_back(A);

    while (A.size() > 1) {
        vector<int> row;
        for (int i = 0; i < A.size() - 1; i++) {
            row.push_back(A[i] + A[i + 1]);
        }
        triangle.push_back(row);
        A = row;
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

        vector<vector<int>> triangle = generateSpecialTriangle(A);

        for (const auto& row : triangle) {
            cout << "[";
            for (int i = 0; i < row.size(); i++) {
                cout << row[i];
                if (i < row.size() - 1) {
                    cout << " ";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}




// Pham Van Thanh B21DCVT404 //