from PIL import Image, ImageDraw


m = int(input())
n = int(input())
rx = int(input())
ry = int(input())
gx = int(input())
gy = int(input())
bx = int(input())
by = int(input())
img = Image.new('RGB', (m, n))
dib = ImageDraw.Draw(img)


def f(i, j, x, y):
    return (x*i + y*j)%256


for i in range(m):
    for j in range(n):
        r = f(i, j, rx, ry)
        g = f(i, j, gx, gy)
        b = f(i, j, bx, by)
        dib.point((i, j), (r, g, b))


img.save("output.png")
