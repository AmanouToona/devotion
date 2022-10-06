import sys
from collections import deque


def main():
    N = int(input())

    g = [[] for _ in range(N)]
    for _ in range(N - 1):
        a, b = map(int, sys.stdin.readline().strip().split())
        a -= 1
        b -= 1
        g[a].append(b)
        g[b].append(a)

    dist_from_1 = [-1] * N
    dist_from_1[0] = 0

    q = deque([])
    q.append(0)
    while q:
        u = q.popleft()

        for v in g[u]:
            if dist_from_1[v] == -1:
                q.append(v)
                dist_from_1[v] = dist_from_1[u] + 1

    dist_from_n = [-1] * N
    dist_from_n[-1] = 0

    q.append(N - 1)
    while q:
        u = q.popleft()

        for v in g[u]:
            if dist_from_n[v] == -1:
                q.append(v)
                dist_from_n[v] = dist_from_n[u] + 1

    f_cnt = 0
    for n in range(N):
        if dist_from_1[n] <= dist_from_n[n]:
            f_cnt += 1

    if f_cnt > N - f_cnt:
        print("Fennec")
    else:
        print("Snuke")

    return


if __name__ == "__main__":
    main()
