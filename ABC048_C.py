import sys


def main():
    N, x = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    ans = 0
    for i in range(N - 1):
        if A[i] + A[i + 1] <= x:
            continue
        eat = (A[i] + A[i + 1]) - x
        ans += eat
        A[i + 1] = max(0, A[i + 1] - eat)

    print(ans)


if __name__ == "__main__":
    main()
