#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int sum = 10080;

unsigned long long calculate(int n, unsigned long long **dp, vector<unsigned long long> &nums) {
    unsigned long long counter = 0;
    dp[0][0] = 1;

    for (int i = 1; i <= sum; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (nums[i - 1] <= j) {
                dp[i][j] = (dp[i - 1][j - nums[i - 1]] + dp[i - 1][j]) % 1000000007;
            }
        }
    }

    for (int i = 0; i < sum + 1; ++i) {
        counter += dp[n][i];
        counter %= 1000000007;
    }
    return counter;
}

int main() {
    int N;
    cin >> N;
    vector<unsigned long long> nums;
    unsigned long long **dp = new unsigned long long *[N + 1];

    for (int i = 0; i < N + 1; ++i) {
        dp[i] = new unsigned long long[sum + 1];
    }

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << calculate(N, dp, nums);
}