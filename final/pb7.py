from PIL import Image, ImageDraw

f = input()
c = input()
n = int(input())
img = Image.new('RGB', (n, n), f)
dib = ImageDraw.Draw(img)

for x in range(n):
    for y in range(n):
        if x == 0 or y == 0 or x%y == 0 or y%x == 0:
            dib.point((x, y), c)

img.save("output.png")
