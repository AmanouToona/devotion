# B - Robot Arms 
import sys

N = int(input())

robots = []
for n in range(N):
    x, l = map(int, sys.stdin.readline().strip().split())
    
    robots.append((max(0, x - l), x + l - 1))

robots.sort(key=lambda x: x[1])

ans = 0
max_right = -1
for left, right in robots:
    # print(f'left:{left} right:{right} max_right: {max_right} ans:{ans}')
    if left > max_right:
        ans += 1
        max_right = right

print(ans)

