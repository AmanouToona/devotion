import sys


def main():
    N = int(input())

    xyh = []
    for _ in range(N):
        xyh.append(tuple(map(int, sys.stdin.readline().strip().split())))

    xyh.sort(key=lambda x: -x[-1])

    for cx in range(101):
        for cy in range(101):
            H = None
            is_ans = True
            for x, y, h in xyh:
                if H is None:
                    H = h + abs(x - cx) + abs(y - cy)
                    continue

                if h != max(H - abs(x - cx) - abs(y - cy), 0):
                    is_ans = False
                    break

            if is_ans:
                print(cx, cy, H)
                return

    return


if __name__ == "__main__":
    main()
