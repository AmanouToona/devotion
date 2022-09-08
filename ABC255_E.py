import sys
from collections import defaultdict


def main():
    N, M = map(int, sys.stdin.readline().strip().split())
    S = list(map(int, sys.stdin.readline().strip().split()))
    X = list(map(int, sys.stdin.readline().strip().split()))

    A1 = [1]
    A0 = [0]
    for s in S:
        A1.append(s - A1[-1])
        A0.append(s - A0[-1])

    count = defaultdict(int)

    for a0, a1 in zip(A0, A1):
        for x in X:
            diff = x - a0
            count[diff / (a1 - a0)] += 1

    ans = 0
    for _, value in count.items():
        ans = max(ans, value)

    print(ans)

    return


if __name__ == "__main__":
    main()
