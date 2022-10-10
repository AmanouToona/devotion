import sys


def solve(G, P):
    _, *V = list(map(int, sys.stdin.readline().strip().split()))
    V = [v - 1 for v in V]
    V = set(V)

    cnt = 0
    for v in V:
        cnt += 1
        cnt += len(G[v])

        if v == 0:
            continue

        p = P[v]
        if p in V:
            cnt -= 2

    print(cnt)

    return


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())
    P = [0]
    P.extend(list(map(int, sys.stdin.readline().strip().split())))
    P = [p - 1 for p in P]

    G = [[] for _ in range(N)]
    for i, p in enumerate(P):
        if p < 0:
            continue
        G[p].append(i)

    for _ in range(Q):
        solve(G, P)

    return


if __name__ == "__main__":
    main()
