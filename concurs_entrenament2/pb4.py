from PIL import Image, ImageDraw


n = int(input())
img = Image.new('RGB', (8*n, 8*n), 'White')
dib = ImageDraw.Draw(img)


t = ['Blue', 'Yellow', 'Red', 'Green']
for i in range(4):
    e = i*n
    d = 8*n - 1 - e
    dib.ellipse([e, e, d, d], t[i])


img.save("output.png")
