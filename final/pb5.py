def prime(n):
  d = 2
  while d*d <= n:
    if n%d == 0: return False
    d += 1
  return True


def fact(n):
  f = 1
  for x in range(2, n + 1):
    f *= x
  return f


for n in range(2, 10000):
  if prime(n):
    f = fact(n - 1) + 1
    if f%(n*n) == 0:
      print(n)
