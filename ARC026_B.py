import math


def main():

    N = int(input())

    if N == 1:
        print("Deficient")
        return

    sum_divisor = 1
    for i in range(2, int(math.sqrt(N)) + 2):
        if N % i != 0:
            continue

        if N / i < i:
            break

        sum_divisor += i

        if i * i != N:
            sum_divisor += N / i

    if sum_divisor == N:
        print("Perfect")
    elif sum_divisor < N:
        print("Deficient")
    else:
        print("Abundant")


if __name__ == "__main__":
    main()
