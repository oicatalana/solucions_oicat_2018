from PIL import Image, ImageDraw

col = ['Brown', 'White', 'Gold', 'Blue']

def rect(x1, y1, x2, y2, col):
    dib.polygon([(x1, y1), (x2, y1), (x2, y2), (x1, y2)], col)

# explorem les caselles que es poden trobar a partir de (x, y)
# vist es una matriu que recorda les caselles ja visitades
def explora(x, y, vist):
    # tirem enrera si ja haviem visitat aquesta casella
    if vist[y][x]: return

    # marquem la casella actual per no visitar-la mes
    vist[y][x] = True
    # si te un mur tambe tirem enrera
    if mat[y][x] == 0: return

    # provem les 8 caselles adjacents
    # no podem sortir fora perque el mapa esta rodejat de murs
    explora(x + 1, y, vist)
    explora(x - 1, y, vist)
    explora(x, y + 1, vist)
    explora(x, y - 1, vist)
    explora(x + 1, y + 1, vist)
    explora(x + 1, y - 1, vist)
    explora(x - 1, y + 1, vist)
    explora(x - 1, y - 1, vist)

n = int(input())
m = int(input())

# llegim i codifiquem el mapa amb una matriu de nombres:
# 0 -> mur, 1 -> lliure, 2 -> tresor, 3 -> pou
mat = []
for j in range(m):
    fila = [0]*n
    s = input()
    for i in range(n):
        if s[i] == 'P':
            fila[i] = 3
            x = i
            y = j
        elif s[i] != 'X':
            fila[i] = (2 if s[i] == 'T' else 1)
    mat += [fila]

img = Image.new('RGB', (50*n, 50*m), 'Black')
dib = ImageDraw.Draw(img)

# inicialment no hem visitat encara res
vist = [[False]*n for j in range(m)]
# comencem a explorar pel pou
explora(x, y, vist)

# per pintar tambe les voreres
for j in range(m): vist[j][0] = vist[j][n-1] = True
for i in range(n): vist[0][i] = vist[m-1][i] = True

# pintem cada casella visitada, amb marro si es mur, i amb blanc altrament
for j in range(m):
    for i in range(n):
        if vist[j][i]:
            xesq = 50*i
            ydalt = 50*j
            xdre = xesq + 49
            ybaix = ydalt + 49
            k = mat[j][i]
            rect(xesq, ydalt, xdre, ybaix, col[k >= 1])
            # si es un tresor o un pou, pintem el cercle
            if k >= 2:
                dib.ellipse([xesq + 5, ydalt + 5, xdre - 5, ybaix - 5], col[k])

img.save("output.png")
