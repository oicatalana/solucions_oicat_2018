s = input()
qtt = [s.count(str(i)) for i in range(10)]

first = next(i for i, x in enumerate(qtt) if x != 0 and i > 0)
qtt[first] = qtt[first] - 1

print(str(first) + ''.join(str(i) * x for i,x in enumerate(qtt)))
