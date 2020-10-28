# D - Enough Array
import sys

N, K = map(int, sys.stdin.readline().strip().split())
A = list(map(int, sys.stdin.readline().strip().split()))

left = 0
right = 0
total = A[0]
count = 0

while right < len(A):
    # print('total', total)
    if total >= K:
        count += len(A) - right
        total -= A[left]
        left += 1
    else:
        right += 1
        if right >= len(A):
            break
        total += A[right]
    # print('right', right)

print(count)