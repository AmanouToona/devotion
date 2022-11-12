import sys


def ratio(P, Q):
    return 1 / (1 + 10 ** ((Q - P) / 400))


def main():
    K = int(input())
    R = []
    for _ in range(2 ** K):
        R.append(int(sys.stdin.readline().strip()))

    # dp[i][j] := 人 i が round j 勝ちついている確率
    dp = [[0] * (K + 1) for _ in range(2 ** K)]
    for i in range(2 ** K):
        dp[i][0] = 1

    # 遷移
    for r in range(1, K + 1):
        for i in range(2 ** K):
            g = i // (2 ** (r - 1))

            # 対戦相手としてあり得る人の番号の最小値
            if g % 2 == 0:
                left = 2 ** (r - 1) * (g + 1)
            else:
                left = 2 ** (r - 1) * (g - 1)

            # 対戦車 opp との対戦確立用の計算

            for opp in range(left, left + 2 ** (r - 1)):
                if opp == i:
                    continue
                dp[i][r] += dp[i][r - 1] * dp[opp][r - 1] * ratio(R[i], R[opp])

    for i in range(2 ** K):
        print(f"{dp[i][K]:.7f}")

    return


if __name__ == "__main__":
    main()
