import sys

mod = 998244353

N = int(input())
D = list(map(int, sys.stdin.readline().strip().split()))

bucket = [0] * N
for d in D:
    if d >= N:  # 使える辺は N-1 本なので、距離が N より大きくなることはない
        print(0)
        sys.exit()
    bucket[d] += 1

flag = False
for b in bucket:
    if b == 0:
        flag = True
    if flag and b != 0:
        print(0)
        sys.exit()

if bucket[0] != 1:  # ここに気が付かなかった　2WA
    print(0)
    sys.exit()

if D[0] != 0:  # ここ 2WA
    print(0)
    sys.exit()


ans = 1
for n in range(1, N):
    if bucket[n] == 0:
        break
    ans *= pow(bucket[n - 1], bucket[n], mod)
    ans %= mod

print(ans)
