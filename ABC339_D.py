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

    def is_in_grid(c, r):
        if c < 0 or c >= N:
            return False
        if r < 0 or r >= N:
            return False
        return True

    def can_move(c, r):
        if not is_in_grid(c, r):
            return False

        if S[c][r] == "#":
            return False
        return True

    if p[0] == p[1]:
        print(0)
        return

    state = {tuple(p): 0}
    q = deque([tuple(p)])

    while q:
        u = q.popleft()
        p1, p2 = u
        uc_p1, ur_p1 = p1
        uc_p2, ur_p2 = p2

        for dc, dr in zip([1, 0, -1, 0], [0, 1, 0, -1]):
            vc_p1 = uc_p1 + dc
            vc_p2 = uc_p2 + dc

            vr_p1 = ur_p1 + dr
            vr_p2 = ur_p2 + dr

            if not can_move(c=vc_p1, r=vr_p1):
                vc_p1 = uc_p1
                vr_p1 = ur_p1

            if not can_move(c=vc_p2, r=vr_p2):
                vc_p2 = uc_p2
                vr_p2 = ur_p2

            v = ((vc_p1, vr_p1), (vc_p2, vr_p2))

            if v in state.keys():
                continue

            state[v] = state[u] + 1
            q.append(v)

            if v[0] == v[1]:
                print(state[v])
                return

    print(-1)

    return


if __name__ == "__main__":
    main()
