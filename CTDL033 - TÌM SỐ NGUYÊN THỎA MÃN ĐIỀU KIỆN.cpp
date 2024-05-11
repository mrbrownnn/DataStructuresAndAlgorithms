#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int bezout(int a, int b) {
    int xa = 1, xb = 0;
    while (b) {
        int q = a / b;
        int r = a - q * b, xr = xa - q * xb;
        a = b; xa = xb;
        b = r; xb = xr;
    }
    return xa;
}
 
int solve(int a, int b, int c) {
    int g = __gcd(a, b);
    int x = bezout(a, b) * (c / g);
    int p = abs(b / g), q = abs(a / g);
    x = (x % p + p) % p;
    int y = (c - a * x) / b;
    int cur = x + y;
    if (x < 0 || y < 0) cur = -1;
    int yy = (y % q + q) % q;
    int xx = (c - b * yy) / a;
    if (cur == -1 || (min(xx, yy) >= 0 && cur > xx + yy))
        cout << xx << ' ' << yy << endl;
    else
        cout << x << ' ' << y << endl;
}
 
main() {
    int t;
    cin>>t;
    while(t--){
    int a1, a2, b1, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    solve(a1, -a2, b2 - b1);
    }
}