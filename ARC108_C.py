import sys
from collections import defaultdict, deque


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    g = [[] for _ in range(N)]
    labels = defaultdict(set)
    for _ in range(M):
        u, v, c = map(int, sys.stdin.readline().strip().split())
        u -= 1
        v -= 1
        labels[(u, v)].add(c)
        labels[(v, u)].add(c)

        g[u].append(v)
        g[v].append(u)

    ans = [-1] * N
    q = deque([])
    q.append(0)

    v = g[0][0]
    ans[0] = list(labels[(0, v)])[0]

    while q:
        u = q.popleft()

        for v in g[u]:
            if ans[v] > 0:
                continue

            num = -1
            for label in labels[(u, v)]:
                if label == ans[u]:
                    continue
                num = label
                break

            if num == -1:
                for i in range(1, N + 1):
                    if i not in labels[(u, v)]:
                        num = i
                        break
            ans[v] = num
            q.append(v)

    for a in ans:
        print(a)

    return


if __name__ == "__main__":
    main()
