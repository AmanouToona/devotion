import sys
from collections import deque


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1
        g[u].append(v)
        g[v].append(u)

    K = int(sys.stdin.readline().strip())

    c = [-1] * N  # color: -1: 未決定, 1: 黒, 0: 白

    def bfs(s, d):
        q = deque()
        q.append(s)
        fp = [-1] * N
        fp[s] = 0

        while q:
            u = q.popleft()
            if fp[u] >= d:
                continue
            c[u] = 0

            for v in g[u]:
                if fp[v] != -1:
                    continue
                q.append(v)
                fp[v] = fp[u] + 1
        return

    P = []
    D = []
    for _ in range(K):
        p, d = map(int, sys.stdin.readline().strip().split())
        p -= 1
        bfs(p, d)

        P.append(p)
        D.append(d)

    c = [i if i == 0 else 1 for i in c]

    # 構築した答えが解の条件を満たすか確認する
    def dist(s):
        # s から最も近い黒点の距離を返す
        q = deque()
        q.append(s)
        fp = [-1] * N
        fp[s] = 0

        while q:
            u = q.popleft()

            if c[u] == 1:
                return fp[u]

            for v in g[u]:
                if fp[v] != -1:
                    continue
                q.append(v)
                fp[v] = fp[u] + 1

    for p, d in zip(P, D):
        if dist(p) != d:
            print("No")
            return

    print("Yes")
    print("".join([str(i) for i in c]))

    return


if __name__ == "__main__":
    main()
