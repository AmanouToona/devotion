import sys
from collections import deque


def main():
    N = int(input())
    A = []
    for _ in range(N):
        A.append(int(sys.stdin.readline().strip()))

    A.sort()
    A = deque(A)

    count = 0
    _A = A.copy()
    ans1 = deque([])
    ans1.append(_A.popleft())
    while _A:
        if count % 2 == 0:
            ans1.append(_A.pop())
            if _A:
                ans1.appendleft(_A.pop())
        else:
            ans1.append(_A.popleft())
            if _A:
                ans1.appendleft(_A.popleft())
        count += 1

    count = 0
    _A = A.copy()
    ans2 = deque([])
    ans2.append(_A.pop())
    while _A:
        if count % 2 != 0:
            ans2.append(_A.pop())
            if _A:
                ans2.appendleft(_A.pop())
        else:
            ans2.append(_A.popleft())
            if _A:
                ans2.appendleft(_A.popleft())
        count += 1

    sum1 = 0
    for i in range(N - 1):
        sum1 += abs(ans1[i] - ans1[i + 1])

    sum2 = 0
    for i in range(N - 1):
        sum2 += abs(ans2[i] - ans2[i + 1])

    print(max(sum1, sum2))

    return


if __name__ == "__main__":
    main()
