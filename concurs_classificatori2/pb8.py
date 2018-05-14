from PIL import Image, ImageDraw


def rect(x1, y1, x2, y2, col):
    dib.polygon([(x1, y1), (x2, y1), (x2, y2), (x1, y2)], col)


f = input()
c = input()
n = int(input())
a = int(input())
img = Image.new('RGB', (a*(2*n + 1), a*(n + 1)), f)
dib = ImageDraw.Draw(img)


mat = [[0]*(2*n + 3) for j in range(n + 1)]

mat[0][n+1] = 1
for j in range(1, n + 1):
    for i in range(1, 2*n + 2):
        x = 4*mat[j-1][i-1] + 2*mat[j-1][i] + mat[j-1][i+1]
        if x >= 1 and x <= 4:
            mat[j][i] = 1

for j in range(n + 1):
    for i in range(1, 2*n + 2):
        if mat[j][i] == 1:
            x = a*(i - 1)
            y = a*j
            rect(x, y, x + a - 1, y + a - 1, c)


img.save("output.png")
