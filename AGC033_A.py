import sys
from collections import deque


def main():
    H, W = map(int, input().strip().split())

    A = []
    for _ in range(H):
        A.append(list(sys.stdin.readline().strip()))

    q = deque([])
    count = [[float("inf")] * W for _ in range(H)]
    for h in range(H):
        for w in range(W):
            if A[h][w] == ".":
                continue
            q.append((h, w))
            count[h][w] = 0

    dh = [0, -1, 0, 1]
    dw = [1, 0, -1, 0]

    while q:
        uh, uw = q.popleft()

        c = count[uh][uw]
        for i in range(4):
            vh = uh + dh[i]
            vw = uw + dw[i]

            if vh < 0 or vh >= H:
                continue
            if vw < 0 or vw >= W:
                continue

            if count[vh][vw] <= c + 1:
                continue

            q.append((vh, vw))
            count[vh][vw] = c + 1

    ans = 0
    for h in range(H):
        for w in range(W):
            ans = max(ans, count[h][w])

    print(ans)

    return


if __name__ == "__main__":
    main()
