MOD = 1000000007


def main():
    D = int(input())
    N = input().strip()
    N = [int(n) for n in N]

    # dp[digit][is small][mod d]
    # := 上からdigit 桁目まで確認
    # := issmall N 以下であるか？
    # について桁の数の和が mod d である物の個数
    dp = [[[0] * D for _ in range(2)] for _ in range(len(N) + 1)]
    dp[0][0][0] = 1

    # 配るdp
    for i, n in enumerate(N):
        for j in range(10):
            for d in range(D):
                if j < n:
                    dp[i + 1][1][(d + j) % D] += dp[i][0][d] + dp[i][1][d]
                else:
                    dp[i + 1][1][(d + j) % D] += dp[i][1][d]

                if j == n:
                    dp[i + 1][0][(d + j) % D] += dp[i][0][d]

                dp[i + 1][0][(d + j) % D] %= MOD
                dp[i + 1][1][(d + j) % D] %= MOD

    print(dp[-1][1][0] - 1)

    return


if __name__ == "__main__":
    main()
