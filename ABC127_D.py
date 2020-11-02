# D - Integer Cards
import sys
import heapq

N, M = map(int, sys.stdin.readline().strip().split())
A = list(map(int, sys.stdin.readline().strip().split()))
heapq.heapify(A)

operation = []
for m in range(M):
    b, c = map(int, sys.stdin.readline().strip().split())
    operation.append((b, c))

operation.sort(key=lambda x: x[1], reverse=True)

for B, C in operation:
    for b in range(B):
        minimum = heapq.heappop(A)
        if minimum < C:
            heapq.heappush(A, C)
        else:
            heapq.heappush(A, minimum)
            break
    else:
        continue
    break

print(sum(A))
