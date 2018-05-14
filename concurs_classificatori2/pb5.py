from PIL import Image, ImageDraw


n = int(input())
m = 3*n
img = Image.new('RGB', (m, m), 'Red')
dib = ImageDraw.Draw(img)


dib.polygon([(0, 0), (0, n - 1), (n - 1, 0)], 'Beige')
dib.polygon([(0, m - 1), (n - 1, m - 1), (0, m - n)], 'Beige')
dib.polygon([(m - 1, 0), (m - 1, n - 1), (m - n, 0)], 'Beige')
dib.polygon([(m - 1, m - 1), (m - n, m - 1), (m - 1, m - n)], 'Beige')


img.save("output.png")
