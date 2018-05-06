from PIL import Image, ImageDraw


def rect(x1, y1, x2, y2, col):
    dib.polygon([(x1, y1), (x2, y1), (x2, y2), (x1, y2)], col)


# diu que te la posicio (i, j), o -1 si esta a fora
def te(i, j):
    if i < 0 or i >= n or j < 0 or j >= m: return -1
    return mat[j][i]


# diu si es pot posar una k a (i, j) horitzontalment
def ok_hor(i, j, k):
    if te(i - 2, j) == k and te(i - 1, j) == k: return False
    if te(i - 1, j) == k and te(i + 1, j) == k: return False
    if te(i + 1, j) == k and te(i + 2, j) == k: return False
    return True


# diu si es pot posar una k a (i, j) verticalment
def ok_ver(i, j, k):
    if te(i, j - 2) == k and te(i, j - 1) == k: return False
    if te(i, j - 1) == k and te(i, j + 1) == k: return False
    if te(i, j + 1) == k and te(i, j + 2) == k: return False
    return True

# procediment principal, backtracking
def prova(i, j):
    # si ho hem omplert tot, ja estem
    if i == n: return True

    # si hem omplert una columna, ens posem a l'inici de la seguent
    if j == m: return prova(i + 1, 0)

    # si una posicio ja esta fixada, la saltem
    if mat[j][i] != -1: return prova(i, j + 1)

    # provem tots els colors en ordre, parant si trobem solucio
    for k in range(5):
        if ok_hor(i, j, k) and ok_ver(i, j, k):
            mat[j][i] = k
            if prova(i, j + 1): return True
            mat[j][i] = 0

    # si arribem aqui no hi ha solucio amb les decisions preses fins ara,
    # caldra desfer alguna decisio previa
    return False


# llegeix l'entrada i la guarda en una matriu de numeros per comoditat
n = int(input())
m = int(input())
mat = []
for j in range(m):
    fila = [-1]*n
    s = input()
    for i in range(n):
        c = s[i]
        if c == 'D': fila[i] = 0
        elif c == 'L': fila[i] = 1
        elif c == 'M': fila[i] = 2
        elif c == 'R': fila[i] = 3
        elif c == 'W': fila[i] = 4
    mat += [fila]


img = Image.new('RGB', (50*n, 50*m), 'Black')
dib = ImageDraw.Draw(img)


# busca la solucio
prova(0, 0)


# dibuixa la solucio trobada
col = ['DodgerBlue', 'Lime', 'Magenta', 'Red', 'White']
for j in range(m):
    for i in range(n):
        x2 = 50*i
        y2 = 50*j
        x3 = x2 + 49
        y3 = y2 + 49
        k = mat[j][i]
        dib.ellipse([x2 + 5, y2 + 5, x3 - 5, y3 - 5], col[k])


img.save("output.png")
