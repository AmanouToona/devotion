import sys
from collections import defaultdict


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]  # 順辺
    gr = [[] for _ in range(N)]  # 逆辺
    for _ in range(M):
        A, B = map(int, sys.stdin.readline().strip().split())
        A -= 1
        B -= 1

        g[A].append(B)
        gr[B].append(A)

    postorder_no = [-1] * N  # 帰りがけ順 -1: 探索前
    used = [False] * N

    def dfs(u, num):
        used[u] = True
        for v in g[u]:
            if used[v]:
                continue
            num = dfs(v, num)

        postorder_no[u] = num
        return num + 1

    num = 0
    for i in range(N):
        if used[i]:
            continue
        num = dfs(i, num)

    group_no = [-1] * N

    def rdfs(u, group):
        if group_no[u] != -1:
            return
        group_no[u] = group

        for v in gr[u]:
            rdfs(v, group)
        return

    reverse_start = [-1] * N
    for u, num in enumerate(postorder_no):
        reverse_start[num] = u
    reverse_start.reverse()

    group = 0
    for u in reverse_start:
        if group_no[u] != -1:
            continue
        rdfs(u, group)
        group += 1

    group_size = defaultdict(int)
    for group in group_no:
        group_size[group] += 1

    ans = 0
    for _, i in group_size.items():
        ans += i * (i - 1) / 2

    print(int(ans))

    return


if __name__ == "__main__":
    main()
