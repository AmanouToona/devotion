def main():
    N, M = map(int, input().strip().split())

    for x in range(10**5 + 1):
        y = 4 * N - 2 * x - M
        if y < 0:
            continue

        if x + y > N:
            continue

        z = N - (x + y)
        print(x, y, z)
        return

    print(-1, -1, -1)
    return


if __name__ == "__main__":
    main()
