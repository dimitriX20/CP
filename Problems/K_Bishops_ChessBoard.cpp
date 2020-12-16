#include <bits/stdc++.h>
using namespace std;

int squares(int i) {
    return i & 1 ? i / 4 * 2 + 1: (i - 1) / 4 * 2 + 2; 
}

int bishopPlacements(int n, int k) {
    if (k > 2 * n - 1) return 0; 
    vector<vector<int>> dp(2 * n, vector<int>(k + 1));
    int ans = 0; 
    
    for(int i = 0; i < 2 * n; i++) {
        dp[i][0] = 1; 
    }
    dp[1][1] = 1; 
    for (int i = 2; i < 2 * n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 2][j] + dp[i - 2][j - 1] * (squares(i) - j + 1); 
        }    
    }
    for (int i = 0; i <= k; i++) {
            ans += dp[2 * n - 1][i] * dp[2 * n - 2][k - i]; 
        }
    
    return ans; 
}

int main() {
    std::cout << bishopPlacements(12, 2);
}
