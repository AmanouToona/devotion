import sys


def main():
    N, D = map(int, sys.stdin.readline().strip().split())

    div = [0] * 3  # D の素因数分解 [2, 3, 5] の個数
    for i, j in enumerate([2, 3, 5]):
        while D % j == 0 and D != 0:
            D //= j
            div[i] += 1

    if D != 1:
        print(0)
        return

    # dp[n][i][j][k] := n 回さいころを振り 2^i, 3^j, 5^k **以上**である確率
    dp = [[[[0] * (div[2] + 1) for _ in range(div[1] + 1)] for _ in range(div[0] + 1)] for _ in range(N + 1)]
    dp[0][0][0][0] = 1

    # 配るdp
    for n in range(N):
        for i in range(div[0] + 1):
            for j in range(div[1] + 1):
                for k in range(div[2] + 1):
                    # 1
                    dp[n + 1][i][j][k] += dp[n][i][j][k] / 6

                    # 2
                    dp[n + 1][min(i + 1, div[0])][j][k] += dp[n][i][j][k] / 6

                    # 3
                    dp[n + 1][i][min(j + 1, div[1])][k] += dp[n][i][j][k] / 6

                    # 4
                    dp[n + 1][min(i + 2, div[0])][j][k] += dp[n][i][j][k] / 6

                    # 5
                    dp[n + 1][i][j][min(k + 1, div[2])] += dp[n][i][j][k] / 6

                    # 6
                    dp[n + 1][min(i + 1, div[0])][min(j + 1, div[1])][k] += dp[n][i][j][k] / 6

    print(dp[N][-1][-1][-1])

    return


if __name__ == "__main__":
    main()
