#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

bool isOdd(const int count[]) {
    for (int i = 0; i <= 25; i++){
        if (count[i] != 0 && count[i] % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string word;
    cin>>word;

    int** even = new int*[word.size()];
    int** dp = new int*[word.size()];

    for(int i = 0; i < word.size(); ++i)
    {
        even[i] = new int[word.size()];
        dp[i] = new int[word.size()];
    }

    for (int i = 0; i < word.size(); i++)
    {
        even[i][i] = 1;
        dp[i][i] = 0;
    }

    for (int i = 0; i < word.size(); i++) {
        int count2[26] = {0};
        for (int j = i; j < word.size(); j++) {
            count2[word[j] - 'a']++;
            even[i][j] = isOdd(count2);
        }
    }

    for (int L = 2; L < word.size() + 1; L++)
    {
        for (int i = 0; i < word.size() - L + 1; i++)
        {
            int j = i + L - 1;

            if (even[i][j])
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]+1);
            }
        }
    }

    cout<< dp[0][word.size() - 1] + 1;
}
