import sys
from collections import deque
from copy import deepcopy

sys.setrecursionlimit(10**8)


def main():
    H, W = map(int, input().strip().split())

    A = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(H)]
    B = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(H)]

    def to_tupple(s):
        s = [tuple(i) for i in s]
        s = tuple(s)
        return s

    def to_list(s):
        s = [list(i) for i in s]
        return s

    start_state = to_tupple(A)
    end_state = to_tupple(B)

    state = {to_tupple(A): 0}

    q = deque()
    q.append(start_state)

    while q:
        u = q.popleft()
        u_cnt = state[u]
        u = to_list(u)

        for h in range(H - 1):
            v = deepcopy(u)

            v[h], v[h + 1] = v[h + 1], v[h]

            v = to_tupple(v)

            if v in state.keys():
                continue

            state[v] = u_cnt + 1

            q.append(v)

        for w in range(W - 1):
            v = deepcopy(u)

            for h in range(H):
                v[h][w], v[h][w + 1] = v[h][w + 1], v[h][w]

            v = to_tupple(v)

            if v in state.keys():
                continue

            state[v] = u_cnt + 1
            q.append(v)

    if end_state in state.keys():
        print(state[end_state])
        return

    print(-1)

    return


if __name__ == "__main__":
    main()
