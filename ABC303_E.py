import sys
from collections import defaultdict, deque

sys.setrecursionlimit(10**8)


def main():
    N = int(input())
    g = [[] for _ in range(N)]
    for _ in range(N - 1):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1

        g[u].append(v)
        g[v].append(u)

    used = [False] * N

    def dfs(u):
        res = u
        for v in g[u]:
            if used[v]:
                continue
            used[v] = True
            res = dfs(v)
            break
        return res

    used[0] = True
    end = dfs(0)

    num = [-1] * N
    q = deque()
    q.append(end)
    num[end] = 1

    while q:
        u = q.popleft()

        for v in g[u]:
            if num[v] != -1:
                continue
            num[v] = num[u] + 1
            num[v] %= 3
            q.append(v)

    ans = defaultdict(int)
    for i in range(N):
        if num[i] != 2:
            continue
        ans[len(g[i])] += 1

    out = []
    for key, val in ans.items():
        for _ in range(val):
            out.append(key)

    out.sort()
    print(*out)

    return


if __name__ == "__main__":
    main()
