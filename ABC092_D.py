import sys


def main():
    grid = []
    for _ in range(50):
        grid.append(["."] * 100)  # white
    for _ in range(50):
        grid.append(["#"] * 100)  # black

    A, B = map(int, sys.stdin.readline().strip().split())

    A -= 1  # white
    B -= 1  # black

    for i in range(51, 100, 2):
        if A == 0:
            break
        for j in range(0, 100, 2):
            grid[i][j] = "."
            A -= 1

            if A == 0:
                break

        if A == 0:
            break

    for i in range(0, 50, 2):
        if B == 0:
            break
        for j in range(0, 100, 2):
            grid[i][j] = "#"
            B -= 1

            if B == 0:
                break
        if B == 0:
            break

    print(100, 100)

    for g in grid:
        g = "".join(g)
        print(g)

    return


if __name__ == "__main__":
    main()
