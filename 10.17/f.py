#!/usr/bin/env python3

T = int(input())

for _ in range(T):
	n = int(input())
	k = 1
	while (k<<1) <= n:
		k <<= 1
	print(k)

