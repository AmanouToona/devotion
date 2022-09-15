import sys
from collections import deque


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    dist = dict()
    g = [[] for _ in range(N)]
    for _ in range(M):
        l, r, d = map(int, sys.stdin.readline().strip().split())
        l -= 1
        r -= 1
        if (l, r) in dist.keys():
            if dict[(l, r)] != d:
                print("No")
                return
            continue
        if (r, l) in dist.keys():
            print("No")
            return
        dist[(l, r)] = d
        g[l].append(r)
        g[r].append(l)

    used = [False] * N
    for i in range(N):
        if used[i]:
            continue
        pos = [None] * N
        q = deque([])
        q.append(i)
        pos[i] = 0

        minimum = 0
        maximum = 0

        while q:
            u = q.pop()

            for v in g[u]:
                if (u, v) in dist.keys():
                    l = u
                    r = v
                else:
                    l = v
                    r = u

                if pos[l] is None:
                    pos[l] = pos[r] - dist[(l, r)]
                    if used[l]:
                        continue
                    q.append(l)
                    used[l] = True
                    if minimum > pos[l]:
                        minimum = pos[l]
                elif pos[r] is None:
                    pos[r] = pos[l] + dist[(l, r)]
                    if used[r]:
                        continue
                    q.append(r)
                    used[r] = True
                    if maximum < pos[r]:
                        maximum = pos[r]
                elif pos[r] - pos[l] != dist[(l, r)]:
                    print("No")
                    return
        if maximum - minimum > 10 ** 9:
            print("No")
            return
    print("Yes")

    return


if __name__ == "__main__":
    main()
