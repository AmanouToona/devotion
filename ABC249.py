import sys
from collections import defaultdict


def main():
    _ = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    max_a = max(A)
    map_a = defaultdict(int)
    for a in A:
        map_a[a] += 1

    A = list(set(A))
    A.sort()

    ans = 0
    for i in range(len(A)):
        for j in range(len(A)):
            if A[i] * A[j] > max_a:
                break

            if A[i] * A[j] in map_a.keys():
                ans += map_a[A[i] * A[j]] * map_a[A[i]] * map_a[A[j]]

    print(ans)
    return


if __name__ == "__main__":
    main()
