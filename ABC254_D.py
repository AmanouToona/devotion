def main():
    N = int(input())

    count_divisor = [0] * (N + 1)

    for i in range(1, N + 1):
        j = i
        while j <= N:
            count_divisor[j] += 1
            j += i




    print(ans)

    return


if __name__ == "__main__":
    main()
