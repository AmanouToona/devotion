import sys

N = int(input())
B = list(map(int, sys.stdin.readline().strip().split()))

table = []
for i, b in enumerate(B):
    table.append([i + 1 - b, b])
    if i + 1 - b < 0:
        print(-1)
        sys.exit()

ans = []
while True:
    flag = True

    for i in range(N - 1, -1, -1):
        if table[i][0] == 0:
            ans.append(table[i][1])
            flag = False

            for j in range(i, N):
                table[j][0] -= 1

            break

    if flag:
        break

ans.reverse()

for a in ans:
    print(a)
