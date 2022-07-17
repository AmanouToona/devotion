import sys

MOD = 998244353


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())

    dp = [[0] * (M + 1) for _ in range(N + 1)]

    for i in range(1, M + 1):
        dp[1][i] = 1

    for i in range(2, N + 1):
        # 累積和を取る
        cusum = [0] * (M + 1)
        for j in range(1, M + 1):
            cusum[j] = dp[i - 1][j]
            cusum[j] += cusum[j - 1]

        for j in range(1, M + 1):
            tran = 0
            tran += cusum[max(0, j - K)]
            tran += cusum[M] - cusum[max(min(M, j + K - 1), j - K)]
            dp[i][j] = tran % MOD

    ans = 0
    for j in range(1, M + 1):
        ans += dp[N][j]
        ans %= MOD

    print(ans)

    return


if __name__ == "__main__":
    main()
