import sys


def main():
    H, W = map(int, sys.stdin.readline().strip().split())

    S = []

    for _ in range(H):
        S.append(sys.stdin.readline().strip())

    dh = [1, 1, 0]
    dw = [0, 1, 1]

    board = [[None] * W for _ in range(H)]

    def can_win(h, w) -> bool:
        if board[h][w] is not None:
            return board[h][w]

        for i in range(3):
            vh = h + dh[i]
            vw = w + dw[i]

            if vh >= H or vw >= W:
                continue
            if S[vh][vw] == "#":
                continue

            if not can_win(vh, vw):
                board[h][w] = True
                return True

        board[h][w] = False
        return board[h][w]

    if can_win(0, 0):
        print("First")
    else:
        print("Second")

    return


if __name__ == "__main__":
    main()
