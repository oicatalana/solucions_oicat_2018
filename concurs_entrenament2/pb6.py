from PIL import Image, ImageDraw


def rect(x1, y1, x2, y2, col):
    dib.polygon([(x1, y1), (x2, y1), (x2, y2), (x1, y2)], col)


def explora(i):
    if i == n: return True

    for j in range(n):
        d1 = i + j
        d2 = i - j + n - 1
        if (not colu[j] and not diag1[d1] and not diag2[d2]):
            colu[j] = diag1[d1] = diag2[d2] = True
            solu[i] = j
            if explora(i + 1): return True
            colu[j] = diag1[d1] = diag2[d2] = False
    return False


n = int(input())
img = Image.new('RGB', (50*n, 50*n))
dib = ImageDraw.Draw(img)


solu = [-1]*n
colu = [False]*n
diag1 = [False]*(2*n - 1)
diag2 = [False]*(2*n - 1)
explora(0)


for j in range(n):
    for i in range(n):
        x1 = 50*i
        y1 = 50*j
        x2 = x1 + 49
        y2 = y1 + 49
        rect(x1, y1, x2, y2, 'Brown' if (i + j)%2 else 'Beige')
        if solu[i] == j:
            dib.ellipse([x1 + 5, y1 + 5, x2 - 5, y2 - 5], 'Black')


img.save("output.png")
