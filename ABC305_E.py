import sys
import heapq

sys.setrecursionlimit = 10**8


def main():
    N, M, K = map(int, sys.stdin.readline().strip().split())
    g = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, sys.stdin.readline().strip().split())
        a -= 1
        b -= 1
        g[a].append(b)
        g[b].append(a)

    q = []
    num = [-1] * N
    for _ in range(K):
        p, h = map(int, sys.stdin.readline().strip().split())
        p -= 1

        heapq.heappush(q, (-h, p))

    while q:
        h, u = heapq.heappop(q)

        if num[u] >= -h:
            continue
        num[u] = -h

        for v in g[u]:
            if num[v] >= num[u]:
                continue
            heapq.heappush(q, (-(num[u] - 1), v))

    ans = []
    for i, n in enumerate(num):
        if n < 0:
            continue
        ans.append(i + 1)

    print(len(ans))
    print(*ans)

    return


if __name__ == "__main__":
    main()
