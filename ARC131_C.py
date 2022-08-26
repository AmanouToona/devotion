import sys
import random

sys.setrecursionlimit(10**8)


def experiment():
    N = 5

    A = []
    for _ in range(N):
        A.append(random.randint(1, 100))

    eaten = [False] * N

    # 先手必勝なら True
    def slow_solve():
        sum_xor = 0

        for i, a in enumerate(A):
            if eaten[i]:
                continue
            sum_xor ^= a

        if sum_xor == 0:
            return False

        for i in range(N):
            if eaten[i]:
                continue

            eaten[i] = True

            if not slow_solve():
                return True

            eaten[i] = False

        return False

    print(f"N: {N}")
    print(f"A: {' '.join([str(a) for a in A])}")

    sum_xor = 0
    for a in A:
        sum_xor ^= a

    print(f"sum_xor {sum_xor}, {bin(sum_xor)}")

    if slow_solve():
        print("Win")
    else:
        print("Lose")


def main():
    N = int(input())
    A = list(map(int, sys.stdin.readline().strip().split()))

    set_A = set(A)

    xor_all = 0
    for a in A:
        xor_all ^= a

    if xor_all in set_A:
        print("Win")
        return

    if N % 2 == 1:
        print("Win")
        return

    print("Lose")


if __name__ == "__main__":
    main()
    # experiment()
