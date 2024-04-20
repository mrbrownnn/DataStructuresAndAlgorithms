#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> A(n);
        std::vector<int> B(m);

        for (int i = 0; i < n; i++) {
            std::cin >> A[i];
        }

        for (int i = 0; i < m; i++) {
            std::cin >> B[i];
        }

        int maxA = *std::max_element(A.begin(), A.end());
        int minB = *std::min_element(B.begin(), B.end());

        int result = maxA * minB;
        std::cout << result << std::endl;
    }

    return 0;
}