# ABC296 E 強連結成分を使う別解

import sys

sys.setrecursionlimit(10**8)


def scc(N, G):
    used = [False] * N
    order = []

    def dfs(u):
        for v in G[u]:
            if used[v]:
                continue
            used[v] = True
            dfs(v)

        order.append(u)

    for u in range(N):
        if used[u]:
            continue
        used[u] = True
        dfs(u)

    RG = [[] for _ in range(len(G))]

    for i, g in enumerate(G):
        for u in g:
            RG[u].append(i)

    groups = []
    used = [False] * N

    def rdfs(u):
        groups[-1].append(u)

        for v in RG[u]:
            if used[v]:
                continue
            used[v] = True
            rdfs(v)
        return

    while order:
        u = order.pop()

        if used[u]:
            continue
        groups.append(list())

        used[u] = True
        rdfs(u)

    return groups


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A = [a - 1 for a in A]

    G = [[] for _ in range(N)]

    for i, a in enumerate(A):
        G[i].append(a)

    groups = scc(N, G)

    ans = 0
    for group in groups:
        if len(group) != 1:
            ans += len(group)
            continue

        u = group[0]
        if A[u] == u:
            ans += 1

    print(ans)

    return


if __name__ == "__main__":
    main()
