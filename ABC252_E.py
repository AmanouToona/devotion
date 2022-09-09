import sys
import heapq


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    G = [[] for _ in range(N)]
    edge_num = {}
    edge_cost = {}

    for m in range(M):
        A, B, C = map(int, sys.stdin.readline().strip().split())
        A -= 1
        B -= 1

        G[A].append(B)
        G[B].append(A)

        edge_num[(A, B)] = f"{m + 1}"
        edge_num[(B, A)] = f"{m + 1}"

        edge_cost[(A, B)] = C
        edge_cost[(B, A)] = C

    q = []
    heapq.heapify(q)
    used = [False] * N

    heapq.heappush(q, (0, -1, 0))  # d, parent, u

    ans = []
    while q:
        d, parent, u = heapq.heappop(q)
        if used[u]:
            continue
        used[u] = True

        if parent != -1:
            ans.append(edge_num[(parent, u)])

        for v in G[u]:
            if used[v]:
                continue

            heapq.heappush(q, (d + edge_cost[(u, v)], u, v))

    ans = " ".join(ans)
    print(ans)

    return


if __name__ == "__main__":
    main()
