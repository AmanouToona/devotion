import sys
from collections import deque

sys.setrecursionlimit(10**8)


def main():
    N = int(input())

    S = [input().strip() for _ in range(N)]

    p = []
    for i in range(N):
        for j in range(N):
            if S[i][j] != "P":
                continue
            p.append((i, j))

    def is_in_grid(r, c):
        if c < 0 or c >= N:
            return False
        if r < 0 or r >= N:
            return False
        return True

    def can_move(r, c):
        if not is_in_grid(r, c):
            return False

        if S[r][c] == "#":
            return False
        return True

    if p[0] == p[1]:
        print(0)
        return

    # r1, c1, r2, c2 の移動コスト
    init = 10**9
    cost = [[[[init for _ in range(N)] for _ in range(N)] for _ in range(N)] for _ in range(N)]
    cost[p[0][0]][p[0][1]][p[1][0]][p[1][1]] = 0

    q = deque([tuple([p[0][0], p[0][1], p[1][0], p[1][1]])])

    while q:
        r1, c1, r2, c2 = q.popleft()

        for dr, dc in zip([1, 0, -1, 0], [0, 1, 0, -1]):
            nxt_r1 = r1 + dr
            nxt_c1 = c1 + dc

            nxt_r2 = r2 + dr
            nxt_c2 = c2 + dc

            if not can_move(r=nxt_r1, c=nxt_c1):
                nxt_r1 = r1
                nxt_c1 = c1

            if not can_move(r=nxt_r2, c=nxt_c2):
                nxt_r2 = r2
                nxt_c2 = c2

            if cost[nxt_r1][nxt_c1][nxt_r2][nxt_c2] != init:
                continue

            cost[nxt_r1][nxt_c1][nxt_r2][nxt_c2] = cost[r1][c1][r2][c2] + 1
            q.append((nxt_r1, nxt_c1, nxt_r2, nxt_c2))

            if nxt_r1 == nxt_r2 and nxt_c1 == nxt_c2:
                print(cost[nxt_r1][nxt_c1][nxt_r2][nxt_c2])
                return

    print(-1)

    return


if __name__ == "__main__":
    main()
