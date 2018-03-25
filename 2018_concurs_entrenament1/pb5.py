from PIL import Image, ImageDraw


f = input()
c = input()
n = int(input())

h = 0
w = 0
for i in range(n):
    h += 2
    w += 2*h - 1
img = Image.new('RGB', (w, h), f)
dib = ImageDraw.Draw(img)


x = 0
a = 2
for i in range(n):
    dib.polygon([(x, h - 1), (x + 2*a - 2, h - 1), (x + a - 1, h - a)], c)
    x += 2*a - 1
    a += 2


img.save("output.png")
