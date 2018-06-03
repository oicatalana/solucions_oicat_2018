import sys

mod = 10 ** 8 + 7
M = [1 for i in range(100001)]
M[2] = 2

for i in range(3, 100001):
    M[i] = (M[i - 1] + M[i - 2] + 3 * M[i - 3]) % mod

for line in sys.stdin:
    print(M[int(line)])
