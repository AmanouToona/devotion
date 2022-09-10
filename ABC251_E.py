import sys


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    # dp[n][i] := 動物 n まで見た, i: bool ={0: エサやってない, 1: エサやった} の最初コスト
    dp = [[float("inf")] * 2 for _ in range(N)]

    # A0 を選択した場合
    dp[1][1] = A[0]
    for n in range(2, N):
        dp[n][0] = dp[n - 1][1]
        dp[n][1] = min(dp[n - 1][1] + A[n - 1], dp[n - 1][0] + A[n - 1])

    ans = dp[N - 1][1]

    # A0 を選択しない場合
    dp = [[float("inf")] * 2 for _ in range(N)]
    dp[1][0] = 0
    for n in range(2, N):
        dp[n][0] = dp[n - 1][1]
        dp[n][1] = min(dp[n - 1][1] + A[n - 1], dp[n - 1][0] + A[n - 1])

    ans = min(ans, dp[N - 1][0] + A[-1])
    ans = min(ans, dp[N - 1][1] + A[-1])
    print(ans)

    return


if __name__ == "__main__":
    main()
