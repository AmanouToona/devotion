import sys


def eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False

    primes = []
    for i in range(n):
        if not is_prime[i]:
            continue
        primes.append(i)

        j = i * i
        while j <= n:
            is_prime[j] = False
            j += i
    return primes


def main():
    N = int(sys.stdin.readline().strip())

    ps = eratosthenes(1000000)

    cnt = 0
    for a in ps:
        for b in ps:
            if a**2 * b**3 >= N:
                break
            if b <= a:
                continue

            for c in ps:
                if a**2 * b * c**2 > N:
                    break

                if c <= b:
                    continue

                cnt += 1
    print(cnt)

    return


if __name__ == "__main__":
    main()
