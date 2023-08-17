import sys

sys.setrecursionlimit(10**8)


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))
    A = [a - 1 for a in A]

    used = [False] * N
    used[0] = True

    def dfs(u):
        v = A[u]
        if used[v]:
            return v
        used[v] = True
        return dfs(v)

    start = dfs(0)

    res = [start]
    while True:
        u = res[-1]
        v = A[u]

        if v == start:
            break
        res.append(v)

    res = [r + 1 for r in res]
    print(len(res))
    print(*res)

    return


if __name__ == "__main__":
    main()
