#include <iostream>
using namespace std;
unsigned long long fibNums[5000000+1];

unsigned long long fibonacci(int n) {
    fibNums[0] = 0;
    fibNums[1] = 1;

    for (int i = 2; i <= n; i++) {
        fibNums[i] = fibNums[i-1] + fibNums[i-2];
        fibNums[i] %= 1000000007;
    }

    return fibNums[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    cout << (fibonacci(N) * 2) % 1000000007;
}