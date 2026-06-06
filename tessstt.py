MOD = 998244353

def solve(N, K):
    dp = [0] * (N + 1)
    dp[1] = 1
    for i in range(2, N + 1):
        dp[i] = (dp[i - 1] * i) % MOD
    result = dp[N]
    for i in range(1, K):
        result = (result * pow(i, -1, MOD)) % MOD
    return result

T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    print(solve(N, K))