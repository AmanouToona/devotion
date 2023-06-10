import sys
from collections import defaultdict


def main():
    S = sys.stdin.readline().strip()

    g = defaultdict(int)
    now = [0] * 10
    g[tuple(now)] += 1
    for s in S:
        s = int(s)
        now[s] = (now[s] + 1) % 2
        g[tuple(now)] += 1

    ans = 0
    for val in g.values():
        ans += (val - 1) * val // 2
    print(ans)
    return


if __name__ == "__main__":
    main()
