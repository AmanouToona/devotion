import sys


def main():
    N, K = map(int, sys.stdin.readline().strip().split())
    A = list(map(int, sys.stdin.readline().strip().split()))

    A_sum = sum(A)

    candidate = []
    i = 1
    while True:
        if i * i > A_sum:
            break
        if A_sum % i == 0:
            candidate.append(i)
            candidate.append(A_sum // i)

        i += 1

    candidate.sort()
    candidate.reverse()

    for c in candidate:
        F = [0] * len(A)
        for i, a in enumerate(A):
            F[i] = (a // c) * c

        res = []
        for a, f in zip(A, F):
            res.append(f - a)

        res.sort()

        for i in range(abs(sum(res)) // c):
            res[i] += c

        s = 0
        for r in res:
            s += abs(r)

        if s <= 2 * K:
            print(c)
            return


if __name__ == "__main__":
    main()

