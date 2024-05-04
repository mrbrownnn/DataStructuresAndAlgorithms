#include <iostream>
#include <bitset>
using namespace std;

int grayCode(int n) {
    return n ^ (n >> 1);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int gray = grayCode(N);
        cout << gray << endl;
    }
    
    return 0;
}