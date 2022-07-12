import sys


MOD = 1000000007


def main():
    N, Q = map(int, sys.stdin.readline().strip().split())

    cond = []
    for _ in range(Q):
        x, y, z, w = map(int, sys.stdin.readline().strip().split())
        cond.append((x - 1, y - 1, z - 1, w))

    ans = 1
    for bit in range(60):
        bit_ans = 0
        for n in range(1 << N):
            can_bit = True
            for q in range(Q):
                x, y, z, w = cond[q]
                if ((n >> x) & 1) | ((n >> y) & 1) | ((n >> z) & 1) != (w >> bit) & 1:
                    can_bit = False
                    break

            if can_bit:
                bit_ans += 1
        ans *= bit_ans
        ans %= MOD

    print(ans)

    return


if __name__ == "__main__":
    main()
