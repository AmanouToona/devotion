import sys


def main():
    _, _ = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    B = list(map(int, sys.stdin.readline().strip().split()))

    # A, B は先頭から消費できる
    # dp の遷移を考える時は後端からの方が都合がいいので逆転する
    A.reverse()
    B.reverse()

    cusuma = A.copy()
    cusumb = B.copy()

    for i in range(len(cusuma) - 1):
        cusuma[i + 1] += cusuma[i]
    for i in range(len(cusumb) - 1):
        cusumb[i + 1] += cusumb[i]

    # dp[a][b] := len(A) = a, len(B) = b の時に先手が取得できる最大値
    dp = [[0] * (len(B) + 1) for _ in range(len(A) + 1)]

    for i, a in enumerate(A):
        dp[i + 1][0] = cusuma[i] - dp[i][0]
    for i, b in enumerate(B):
        dp[0][i + 1] = cusumb[i] - dp[0][i]

    # dp 遷移
    for a in range(1, len(A) + 1):
        for b in range(1, len(B) + 1):
            dp[a][b] = cusuma[a - 1] + cusumb[b - 1] - min(dp[a - 1][b], dp[a][b - 1])

    print(dp[len(A)][len(B)])

    return


if __name__ == "__main__":
    main()
