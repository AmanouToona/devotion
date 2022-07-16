import sys
import heapq
from heapq import heappop, heappush


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    for _ in range(M):
        A, B, C = map(int, sys.stdin.readline().strip().split())
        A -= 1
        B -= 1

        g[A].append((B, C))
        g[B].append((A, C))

    cost_from1 = [float("inf")] * N
    cost_from1[0] = 0
    q = []
    heapq.heapify(q)
    heappush(q, (0, 0))

    while q:
        c, u = heappop(q)

        if cost_from1[u] < c:
            continue

        for v, cost_to in g[u]:
            if cost_to + cost_from1[u] >= cost_from1[v]:
                continue

            cost_from1[v] = cost_to + cost_from1[u]
            heappush(q, (cost_from1[v], v))

    cost_fromN = [float("inf")] * N
    cost_fromN[N - 1] = 0
    q = []
    heapq.heapify(q)
    heappush(q, (0, N - 1))
    while q:
        c, u = heappop(q)

        if cost_fromN[u] < c:
            continue

        for v, cost_to in g[u]:
            if cost_to + cost_fromN[u] >= cost_fromN[v]:
                continue

            cost_fromN[v] = cost_to + cost_fromN[u]
            heappush(q, (cost_fromN[v], v))

    for i in range(N):
        print(cost_from1[i] + cost_fromN[i])


if __name__ == "__main__":
    main()
