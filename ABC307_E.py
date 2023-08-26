import sys

MOD = 998244353


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    # dp[0: ngあり, 1: ngなし][0: 最後の要素が1番目とことなる, 1: 最後の要素が1番目と同じ][i 文字目まで見た]
    dp = [[[0] * N for _ in range(2)] for _ in range(2)]

    dp[0][0][0] = 0
    dp[0][1][0] = M

    for i in range(1, N):
        dp[0][0][i] += dp[0][1][i - 1] * (M - 1) + dp[0][0][i - 1] * (M - 2)
        dp[0][1][i] += dp[0][0][i - 1]
        dp[1][0][i] += dp[0][0][i - 1] + dp[1][1][i - 1] * (M - 1) + dp[1][0][i - 1] * (M - 1)
        dp[1][1][i] += dp[0][1][i - 1] + dp[1][0][i - 1] + dp[1][1][i - 1]

        dp[0][0][i] %= MOD
        dp[0][1][i] %= MOD
        dp[1][0][i] %= MOD
        dp[1][1][i] %= MOD

    print(dp[0][0][-1])


if __name__ == "__main__":
    main()
