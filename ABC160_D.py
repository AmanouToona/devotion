# D - Line++
import sys

N, X, Y = map(int, sys.stdin.readline().strip().split())

for k in range(1, N):
    if k > N - (Y - X):
        print('if', 0)
    elif k < Y - X:
        print('elif', N - k + 1 + min(X, N - Y, k))
    else:
        if X >= k:
            ans = X - k + 1 + (N - Y + 1) - k + 1
        else:
            ans = N - (Y - X) - k + 1
        print('else', ans)