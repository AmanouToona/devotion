import sys

sys.setrecursionlimit(10**8)


def main1():
    # 規則性を用いる解き方
    N, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A = [a - 1 for a in A]

    ord = [-1] * N
    path = []

    nxt = 0
    while ord[nxt] == -1:
        ord[nxt] = len(path)
        path.append(nxt)
        nxt = A[nxt]

    loop_size = len(path) - ord[nxt]
    non_loop_size = len(path) - loop_size

    ans = None
    if K < non_loop_size:
        ans = path[K]
    else:
        ans = path[(K - non_loop_size) % loop_size + non_loop_size]

    print(ans + 1)

    return


def main2():
    # ダブリング
    N, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A = [a - 1 for a in A]

    bit_count = 0
    while 2**bit_count < K:
        bit_count += 1

    to = [[-1] * N for _ in range(bit_count + 1)]

    for i, a in enumerate(A):
        to[0][i] = a

    for i in range(bit_count):
        for n in range(N):
            to[i + 1][n] = to[i][to[i][n]]

    now = 0

    for i in range(bit_count + 1):
        if K >> i & 1:
            now = to[i][now]

    print(now + 1)

    return


if __name__ == "__main__":
    main2()
