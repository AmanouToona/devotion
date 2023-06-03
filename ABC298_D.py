import sys
from collections import deque

MOD = 998244353


def main():
    Q = int(sys.stdin.readline().strip())

    digit = [1, 1]
    for _ in range(Q):
        digit.append(digit[-1] * 10 % MOD)

    nums = deque()
    nums.append(1)
    ans = 1
    for _ in range(Q):
        query = sys.stdin.readline().strip()

        if query[0] == "1":
            _, x = query.split()
            x = int(x)
            nums.append(x)

            ans *= 10
            ans += x
            ans %= MOD
        elif query == "2":
            n = nums.popleft()
            ans -= n * digit[len(nums) + 1]
            ans %= MOD
        else:
            print(ans)

    return


if __name__ == "__main__":
    main()
