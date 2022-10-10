import sys


def solve(G):
    _, *V = list(map(int, sys.stdin.readline().strip().split()))
    V = [v - 1 for v in V]
    V = set(V)

    cnt = 0
    for v in V:
        cnt += 1
        cnt += len(G[v])

        for nxt in G[v]:
            if nxt not in V:
                continue
            cnt -= 2

    print(cnt)

    return


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())
    P = list(map(int, sys.stdin.readline().strip().split()))

    P = [p - 1 for p in P]
    G = [[] for _ in range(N)]
    for i, p in enumerate(P):
        i += 1
        G[p].append(i)

    for _ in range(Q):
        solve(G)

    return


if __name__ == "__main__":
    main()
