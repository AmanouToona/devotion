import sys


def main():
    _, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    # dp[less flag][bit]
    dp = [[-1] * 61 for _ in range(2)]
    dp[0][0] = 0

    # 配るdp
    for j in range(60):

        k = 1 << (59 - j)
        one = 0
        zero = 0
        for a in A:
            one += (a & k) ^ k
            zero += (a & k) ^ 0

        for flag in range(2):
            if dp[flag][j] < 0:
                continue

            if flag:
                dp[flag][j + 1] = max(dp[flag][j] + zero, dp[flag][j + 1])
                dp[flag][j + 1] = max(dp[flag][j] + one, dp[flag][j + 1])
            else:
                dp[flag][j + 1] = max(dp[flag][j] + zero, dp[flag][j + 1])

            if (k & K) > 0:
                dp[1][j + 1] = max(dp[flag][j] + zero, dp[1][j + 1])
                dp[0][j + 1] = max(dp[0][j] + one, dp[0][j + 1])

    print(max(dp[0][60], dp[1][60]))

    return


if __name__ == "__main__":
    main()
