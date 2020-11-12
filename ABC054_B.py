import sys

N, M = map(int, sys.stdin.readline().strip().split())

A = []
for n in range(N):
    a = list(str(sys.stdin.readline().strip()))
    A.append(a)

B = []
for m in range(M):
    b = list(str(sys.stdin.readline().strip()))
    B.append(b)

ans = "No"

for top in range(N - M + 1):
    for left in range(N - M + 1):
        for i in range(M):
            flag_break = False
            for j in range(M):
                # print(f'top: {top} lef: {left} i: {i} j: {j}')
                if A[top + i][left + j] != B[i][j]:
                    flag_break = True
                    break
                
                if i == M - 1 and j == M - 1:
                    ans = "Yes"
            if flag_break:
                break

        if ans == "Yes":
            break    
    if ans == "Yes":
        break

print(ans)
