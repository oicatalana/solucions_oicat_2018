n = int(input())
matrix = [input() for i in range(n)]

m = int(input())
for i in range(m):
    p = int(input())
    c = input()

    nx = 0
    ny = 0
    for j in range(n):
        if matrix[j][p - 1] == matrix[0][p - 1]:
            nx = nx + 1
        if matrix[j][p - 1] == c:
            ny = ny + 1

    if 2 * ny >= nx:
        print('neutral')
    else:
        print('patologica')
