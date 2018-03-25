from PIL import Image, ImageDraw


def rect(x1, y1, x2, y2, col):
    dib.polygon([(x1, y1), (x2, y1), (x2, y2), (x1, y2)], col)


n = int(input())
m = int(input())
img = Image.new('RGB', (n, 9*m), 'Yellow')
dib = ImageDraw.Draw(img)


for i in range(4):
    y = 2*m*i + m
    rect(0, y, n - 1, y + m - 1, 'Red')


img.save("output.png")
