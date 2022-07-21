import sys
import math


def main():
    N = int(sys.stdin.readline().strip())

    divisor = set()
    for i in range(1, int(math.sqrt(N)) + 1):
        if N % i == 0:
            divisor.add(i)
            divisor.add(int(N / i))

    ans = 0
    for k in divisor:
        m = N / k - 1
        if k >= m:
            continue
        ans += m

    print(int(ans))

    return


if __name__ == "__main__":
    main()
