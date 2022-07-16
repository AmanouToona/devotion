import sys


def main():
    N, K = map(int, sys.stdin.readline().strip().split())

    cusum = [[0] * 5001 for _ in range(5001)]
    for _ in range(N):
        A, B = map(int, sys.stdin.readline().strip().split())
        cusum[A][B] += 1

    # 累積和
    for i in range(5001):
        for j in range(5000):
            cusum[i][j + 1] += cusum[i][j]

    for i in range(5001):
        for j in range(5000):
            cusum[j + 1][i] += cusum[j][i]

    ans = 0
    # 左下
    for i in range(1, 5001 - K):
        for j in range(1, 5001 - K):
            pop = cusum[i + K][j + K] - cusum[i + K][j - 1] - cusum[i - 1][j + K] + cusum[i - 1][j - 1]
            ans = max(ans, pop)

    print(ans)

    return


if __name__ == "__main__":
    main()
