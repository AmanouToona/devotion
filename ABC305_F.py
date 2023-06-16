import sys

sys.setrecursionlimit = 10**8


def main():
    N, _ = map(int, sys.stdin.readline().strip().split())

    num = [-1] * N
    num[0] = 0
    for n in range(1, 2 * N + 1):
        i = input().strip()
        if i == "-1" or i == "OK":
            return

        v = list(map(int, i.split()))[1:]
        v = [i - 1 for i in v]

        nxt = v[0]
        for v_ in v:
            if num[v_] < num[nxt]:
                nxt = v_

        num[nxt] = n

        print(nxt + 1)
    return


if __name__ == "__main__":
    main()
