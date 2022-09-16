import sys
from collections import defaultdict


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    cusum = A.copy()
    for i in range(len(cusum) - 1):
        cusum[i + 1] += cusum[i]

    count = defaultdict(int)
    count[0] += 1

    ans = 0
    for c in cusum:
        c = c % M
        ans += count[c]
        count[c] += 1

    print(ans)
    return


if __name__ == "__main__":
    main()
