#!/usr/bin/env python
from math import *

k = log(3) / log(2)
minv = 100.

for i in range(1, 1001):
    v = k * i
    minv = min(minv, fabs(v - floor(v)))

print minv
