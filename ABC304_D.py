import sys
from collections import defaultdict
from bisect import bisect_left


def main():
    W, H = map(int, sys.stdin.readline().strip().split())
    N = int(sys.stdin.readline().strip())
    berry = []
    for _ in range(N):
        p, q = map(int, sys.stdin.readline().strip().split())
        berry.append((p, q))

    _ = int(sys.stdin.readline().strip())
    A = list(map(int, sys.stdin.readline().strip().split()))
    _ = int(sys.stdin.readline().strip())
    B = list(map(int, sys.stdin.readline().strip().split()))

    cnt = defaultdict(int)
    for p, q in berry:
        p = bisect_left(A, p)
        q = bisect_left(B, q)
        cnt[(p, q)] += 1

    ans_max = 0
    ans_min = N + 1
    for v in cnt.values():
        ans_max = max(ans_max, v)
        ans_min = min(ans_min, v)

    if len(cnt) < (len(A) + 1) * (len(B) + 1):
        ans_min = 0

    print(ans_min, ans_max)
    return


if __name__ == "__main__":
    main()
