# D - Grid Coloring
import sys

H, W = map(int, sys.stdin.readline().strip().split())
N = int(input())
a = list(map(int, sys.stdin.readline().strip().split()))

A = a
for i in range(1, N):
    A[i] += A[i - 1]

ans = [[0] * W for _ in range(H)]

trout = 0
color_a = 0
for h in range(H):
    for w in range(W):
        trout += 1
        if trout > A[color_a]:  # 使用可能な回数を超えていたら色を変える
            color_a += 1
        
        if h % 2 == 0:
            ans[h][w] = color_a
        else:
            ans[h][W - 1 - w] = color_a

for row in ans:
    row = [str(i + 1) for i in row]
    print(" ".join(row))
