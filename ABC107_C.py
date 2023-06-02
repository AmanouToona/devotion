import sys


def movingDistance(left, right):
    if right <= 0:
        return abs(left)
    if left >= 0:
        return right

    return min(abs(left) * 2 + right, abs(left) + right * 2)


def main():
    N, K = map(int, sys.stdin.readline().strip().split())
    X = list(map(int, sys.stdin.readline().strip().split()))

    if N == K:
        print(movingDistance(left=X[0], right=X[-1]))
        return

    r = K - 1
    ans = 1001001001
    while r < N:
        ans = min(ans, movingDistance(left=X[r - K + 1], right=X[r]))
        r += 1

    print(ans)
    return


if __name__ == "__main__":
    main()
