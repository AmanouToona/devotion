# C - Tsundoku
import sys

N, M, K = map(int, sys.stdin.readline().strip().split())
A = list(map(int, sys.stdin.readline().strip().split()))
B = list(map(int, sys.stdin.readline().strip().split()))

tot_book = 0
tot_a_time = 0
tot_a_book = 0
for a in A:
    if tot_a_time + a <= K:
        tot_a_time += a
        tot_a_book += 1
    else:
        break
tot_book = tot_a_book


tot_b_time = 0
tot_b_book = 0
for i in range(len(B)):
    tot_b_time += B[i]
    tot_b_book += 1
    while (tot_b_time + tot_a_time > K) and (tot_a_book > 0):
        tot_a_time -= A[tot_a_book - 1]
        tot_a_book -= 1
    
    if tot_b_time + tot_a_time <= K:
        tot_book = max(tot_book, tot_b_book + tot_a_book)
    else:
        break

print(tot_book)
