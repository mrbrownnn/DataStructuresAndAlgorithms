#include <iostream>
#include <string>
using namespace std;
void generate_AB_strings(string current, int n) {
    if (current.length() == n) {
        cout << current << " ";
    } else {
        generate_AB_strings(current + "A", n);
        generate_AB_strings(current + "B", n);
    }
}
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        string current = "";
        generate_AB_strings(current, n);
        cout << endl;
    }
    return 0;}