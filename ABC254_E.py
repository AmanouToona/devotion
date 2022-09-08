import sys
from collections import deque


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    G = [[] for _ in range(N + 1)]
    for _ in range(M):
        a, b = map(int, sys.stdin.readline().strip().split())

        G[a].append(b)
        G[b].append(a)

    def bfs(x, k):
        used = set()
        q = deque([])
        ans = 0

        q.append((x, 0))
        used.add(x)
        ans += x

        while q:
            u, u_k = q.popleft()

            if u_k >= k:
                continue

            for v in G[u]:
                if v in used:
                    continue
                ans += v
                used.add(v)
                q.append((v, u_k + 1))

        return ans

    Q = int(input())
    for _ in range(Q):
        x, k = map(int, sys.stdin.readline().strip().split())

        ans = bfs(x, k)
        print(ans)

    return


if __name__ == "__main__":
    main()
