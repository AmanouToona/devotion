import sys

sys.setrecursionlimit(10**8)


def main():
    N, T, M = map(int, sys.stdin.readline().strip().split())

    incompatible = [set() for _ in range(N)]

    for _ in range(M):
        a, b = map(int, sys.stdin.readline().strip().split())
        a -= 1
        b -= 1

        incompatible[a].add(b)
        incompatible[b].add(a)

    global cnt
    cnt = 0
    state = []

    def dfs(u):
        global cnt
        if u == N:
            if len(state) == T:
                cnt += 1
            return

        for i in range(len(state)):
            flg = False
            for member in state[i]:
                if u in incompatible[member]:
                    flg = True
            if flg:
                continue

            state[i].add(u)

            dfs(u + 1)

            state[i].remove(u)

        if len(state) < T:
            state.append(set([u]))
            dfs(u + 1)
            state.pop()

        return

    dfs(0)
    print(cnt)


if __name__ == "__main__":
    main()
