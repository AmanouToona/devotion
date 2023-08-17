import sys


def read():
    H, W = map(int, sys.stdin.readline().strip().split())

    X = []
    for _ in range(H):
        X.append(sys.stdin.readline().strip())

    tlw = 20  # top left
    tlh = 20  # top left
    rbw = -1  # right bottom
    rbh = -1  # right bottom

    for h in range(H):
        for w in range(W):
            if X[h][w] != "#":
                continue

            tlw = min(tlw, w)
            tlh = min(tlh, h)

            rbw = max(rbw, w)
            rbh = max(rbh, h)

    res = []
    for h in range(tlh, rbh + 1):
        res.append(X[h][tlw : rbw + 1])

    return res


def main():
    A = read()
    B = read()
    X = read()

    if len(A) > len(X) or len(B) > len(X):
        print("No")
        return

    if len(A[0]) > len(X[0]) or len(B[0]) > len(X[0]):
        print("No")
        return

    to_black = [[False] * len(X[0]) for _ in range(len(X))]
    to_wight = [[False] * len(X[0]) for _ in range(len(X))]

    for h in range(len(X)):
        for w in range(len(X[0])):
            if X[h][w] == "#":
                continue
            to_black[h][w] = True

    for tlh_a in range(0, len(X) - len(A) + 1):
        for tlw_a in range(0, len(X[0]) - len(A[0]) + 1):
            for tlh_b in range(0, len(X) - len(B) + 1):
                for tlw_b in range(0, len(X[0]) - len(B[0]) + 1):
                    can = True
                    for h in range(len(X)):
                        for w in range(len(X[0])):
                            if X[h][w] == ".":
                                to_black[h][w] = False
                                to_wight[h][w] = True
                            else:
                                to_black[h][w] = True
                                to_wight[h][w] = False

                    for h in range(len(A)):
                        if not can:
                            break

                        for w in range(len(A[0])):
                            if A[h][w] == ".":
                                continue

                            _h = tlh_a + h
                            _w = tlw_a + w

                            if to_wight[_h][_w]:
                                can = False
                                break

                            to_black[_h][_w] = False

                    for h in range(len(B)):
                        if not can:
                            break

                        for w in range(len(B[0])):
                            if B[h][w] == ".":
                                continue

                            _h = tlh_b + h
                            _w = tlw_b + w

                            if to_wight[_h][_w]:
                                can = False
                                break

                            to_black[_h][_w] = False

                    for b in to_black:
                        if any(b):  # まだ塗らないと行けない部分がある
                            can = False
                            break

                    if can:
                        print("Yes")
                        return

    print("No")

    return


if __name__ == "__main__":
    main()
