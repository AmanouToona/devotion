import sys
from collections import deque


def main():
    N, u, v = map(int, sys.stdin.readline().strip().split())
    u -= 1
    v -= 1

    g = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = map(int, sys.stdin.readline().strip().split())
        a -= 1
        b -= 1

        g[a].append(b)
        g[b].append(a)

    def bfs(u, dist):
        q = deque([])
        q.append(u)
        dist[u] = 0

        while q:
            u = q.pop()

            for v in g[u]:
                if dist[v] >= 0:
                    continue
                dist[v] = dist[u] + 1
                q.append(v)

    # 青木君の移動回数
    d_ao = [-1] * N
    bfs(v, d_ao)

    # 高橋の移動回数
    d_taka = [-1] * N

    q = deque([])
    q.append(u)
    d_taka[u] = 0
    while q:
        u = q.pop()

        for v in g[u]:
            if d_taka[v] > 0:
                continue
            dist = d_taka[u] + 1
            if dist > d_ao[v]:
                continue
            if dist == d_ao[v]:
                d_taka[v] = dist
                continue

            d_taka[v] = dist
            q.append(v)

    # 答え
    ans = 0
    for i in range(N):
        if d_taka[i] > d_ao[i]:
            continue

        ans = max(ans, d_ao[i] - 1)

    print(ans)

    return


if __name__ == "__main__":
    main()
