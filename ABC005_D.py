import sys


def main():
    N = int(input())
    D = []
    for _ in range(N):
        D.append(list(map(int, sys.stdin.readline().strip().split())))

    # 2次元累積和
    cusum = [[0] * (N + 1)]
    for d in D:
        _d = [0]
        _d.extend(d)
        cusum.append(_d)

    for h in range(1, N + 1):
        for w in range(N):
            cusum[h][w + 1] += cusum[h][w]
    for w in range(1, N + 1):
        for h in range(N):
            cusum[h + 1][w] += cusum[h][w]

    # 与えられた長方形の形状について、美味しさの合計値の最大値を回答する
    def solve(H, W):
        # 長方形の左上について探索する
        res = 0
        for h in range(0, N - H + 1):
            for w in range(0, N - W + 1):
                _res = cusum[h + H][w + W] - cusum[h][w + W] - cusum[h + H][w] + cusum[h][w]
                res = max(res, _res)

        return res

    answers = [0] * (N ** 2 + 1)
    for h in range(1, N + 1):
        for w in range(1, N + 1):
            answers[h * w] = max(answers[h * w], solve(h, w))

    for i in range(len(answers) - 1):
        answers[i + 1] = max(answers[i + 1], answers[i])

    Q = int(input())
    for _ in range(Q):
        P = int(sys.stdin.readline().strip())

        ans = answers[P]
        print(ans)
    return


if __name__ == "__main__":
    main()
