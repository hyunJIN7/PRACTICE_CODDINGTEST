#include <string>
#include <vector>

#define MOD  1000000007
#define PUDDLE -1
#define MAX 100

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int dp[MAX+1][MAX+1] = {0,};
    // vector<vector<int>> dp(m+1,vector<int>(n+1, 0));
    for(auto p : puddles) dp[p[0]][p[1]] = PUDDLE;
    dp[1][1] = 1; //시작위치 
    
    for(int y = 1 ; y <= m ; y++){
        for(int x = 1; x <= n ;x++){
            if(dp[y][x] == PUDDLE) dp[y][x] = 0;
            else dp[y][x] += (dp[y-1][x] + dp[y][x-1]) % MOD;
        }
    }
    
    return dp[m][n];
}
