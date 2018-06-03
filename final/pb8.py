from PIL import Image, ImageDraw

f = input()
c1 = input()
c2 = input()
c3 = input()
n = int(input())

t = 25*2**n
img = Image.new('RGB', (t, t), f)
dib = ImageDraw.Draw(img)

for i in range (n):
    s = 25*2**i
    dib.ellipse([t - 2*s, t - s, t - s - 1, t - 1], c1)
    dib.ellipse([t - 2*s, t - 2*s, t - s - 1, t - s - 1], c2)
    dib.ellipse([t - s, t - 2*s, t - 1, t - s - 1], c3)

img.save('output.png')
