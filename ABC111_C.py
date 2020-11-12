import sys

n = int(input())
V = list(map(int, sys.stdin.readline().strip().split()))

odd = [0] * (100_000 + 1)
even = [0] * (100_000 + 1)

for i, v in enumerate(V):
    if i % 2 == 0:
        even[v] += 1
    else:
        odd[v] += 1

if odd.index(max(odd)) == even.index(max(even)):  # ここで WA
    even.sort(reverse=True)
    odd.sort(reverse=True)
    ans = min(n - odd[0] - even[1], n - odd[1] - even[0])
else:
    ans = n - max(odd) - max(even)

print(ans)
