import sys

sys.setrecursionlimit = 10**8


def main():
    N, M = map(int, sys.stdin.readline().strip().split())

    num = [-1] * N
    num[0] = 0
    for n in range(1, 2 * N + 1):
        i = sys.stdin.readline().strip()
        if i == "-1" or i == "OK":
            return

        kv = list(map(int, i.split()))
        v = kv[1:]
        v = [i - 1 for i in v]

        nxt = v[0]
        for v_ in v:
            if num[v_] < num[nxt]:
                nxt = v_

        num[nxt] = n

        print(nxt + 1)


if __name__ == "__main__":
    main()
