import sys
import heapq


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    cnt = [0] * N
    for _ in range(M):
        a, b = map(int, sys.stdin.readline().strip().split())
        a -= 1
        b -= 1

        g[a].append(b)
        cnt[b] += 1

    q = []
    for i, c in enumerate(cnt):
        if c == 0:
            heapq.heappush(q, i)

    # トポロジカルソート
    ans = []
    while q:
        u = heapq.heappop(q)
        ans.append(u)

        for v in g[u]:
            cnt[v] -= 1
            if cnt[v] == 0:
                heapq.heappush(q, v)

    if len(ans) != N:
        print(-1)
    else:
        ans = [str(i + 1) for i in ans]

        print(" ".join(ans))
    return


if __name__ == "__main__":
    main()
