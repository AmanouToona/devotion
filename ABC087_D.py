import sys
from collections import deque


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    for _ in range(M):
        l, r, d = map(int, sys.stdin.readline().strip().split())

        l -= 1
        r -= 1

        g[l].append((d, r))
        g[r].append((-d, l))

    pos = [None] * N
    for i in range(N):
        if pos[i] is not None:
            continue

        q = deque([])
        q.append(i)
        pos[i] = 0

        while q:
            u = q.pop()

            for d, v in g[u]:
                if pos[v] is not None:
                    if pos[v] - pos[u] != d:
                        print("No")
                        return
                    continue
                pos[v] = pos[u] + d
                q.append(v)

    print("Yes")

    return


if __name__ == "__main__":
    main()
