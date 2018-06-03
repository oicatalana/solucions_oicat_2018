from PIL import Image, ImageDraw

f = input()
c = input()
n = int(input())
s = input()
img = Image.new('RGB', (n, n), f)
dib = ImageDraw.Draw(img)

if s == "dreta":
    dib.polygon([(n - 1, 0), (0, n - 1), (n - 1, n - 1)], c)
else:
    dib.polygon([(0, 0), (0, n - 1), (n - 1, n - 1)], c)

img.save("output.png")
