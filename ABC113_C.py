# C - ID
import sys

N, M = map(int, sys.stdin.readline().strip().split())

towns = []
for m in range(M):
    P, Y = map(int, sys.stdin.readline().strip().split())
    towns.append([m, P, Y, 0])

towns.sort(key=lambda x: x[2])
towns.sort(key=lambda x: x[1])

count = 0
u_P = 0
for town in towns:
    if town[1] != u_P:
        count =0
    u_P = town[1]
    count += 1
    town[3] = count

towns.sort(key=lambda x: x[0])

for town in towns:
    print(f'{town[1]:06}{town[3]:06}')
    # print(f'{town[1]: 06}')
