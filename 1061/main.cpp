#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// #define LOCAL

using namespace std;

bool are_relatively_prime(long x, long y) {
    long z;
    while (y > 1) {
        z = x % y;
        x = y;
        y = z;
    }
    return y == 1;
}

// a, b保存结果
void dps(long x, long y, long& a, long& b) {
    long p, q, ma, mb;
    p = x / y;
    q = x % y;
    if (y == 1) {
        a = 1;
        b = 1 - x;
    } else {
        dps(y, x % y, ma, mb);
        a = mb;
        b = ma - p * mb;  
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    long x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;

    long S = abs(m - n);
    long distance = abs(x - y);
    if (!are_relatively_prime(S, L)) {
        cout << "Impossible" << endl;
    }
    // 辗转相除法, S * p + L * q = 1
    long p, q;
    dps(S, L, p, q);
    p = p * distance;
    q = q * distance;
    if (m < n) {
        S = -S;
        p = -p;
    }
    long scale = p / L;
    if (p < 0) {
        p += L * (scale + 1);
        q -= S * (scale + 1);
    }
    if (p > L) {
        p = p % L;
        q += S * scale;
    }
    cout << p << endl;
    // printf("%ldX(%ld) + %ld*(%ld) = %ld\n", S, p, L, q, distance);
    return 0;
}
