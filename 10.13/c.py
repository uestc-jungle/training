#!/usr/bin/env python3

maxn, maxk = 333, 333

C = [[0 for x in range(maxn)] for y in range(maxk)]

C[0][0] = 1
for i in range(1, maxn):
    C[i][0] = C[i][i] = 1
    for j in range(1, i):
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j]

T = int(input())

for cas in range(T):
    [n, k, d] = [int(x) for x in input().split()]
    num = C[n][k]
    inbased = []
    while num > 0:
        inbased.append(num % d)
        num = int(num // d)
    inbased.reverse()
    print(''.join([chr(x + ord('0')) for x in inbased]))
    # print(n, k, d, inbased)
