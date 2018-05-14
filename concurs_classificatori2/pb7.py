from PIL import Image, ImageDraw


f = input()
r = int(input())
g = int(input())
b = int(input())
n = int(input())
a = int(input())
m = a*n*(n + 1)//2
h = a*n

img = Image.new('RGB', (m, h), f)
dib = ImageDraw.Draw(img)


x = 0
for i in range(1, n + 1):
    d = a*i
    x2 = x + d - 1
    dib.ellipse([x, h - d, x2, h - 1], (r*i, g*i, b*i))
    x = x2 + 1


img.save("output.png")
