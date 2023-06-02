import sys


def main():
    S = sys.stdin.readline().strip()
    N = int(sys.stdin.readline().strip())

    tot = 0
    for i, s in enumerate(S[::-1]):
        if s != "1":
            continue
        tot += 2**i

    if tot > N:
        print(-1)
        return

    for i, s in enumerate(S):
        if s != "?":
            continue

        i = len(S) - i - 1

        if tot + 2**i <= N:
            tot += 2**i

    print(tot)

    return


if __name__ == "__main__":
    main()
