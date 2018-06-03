from PIL import Image, ImageDraw

def rect(x1, y1, x2, y2, col):
    dib.polygon([(x1, y1), (x2, y1), (x2, y2), (x1, y2)], col)

img = Image.new('RGB', (101, 71), 'Green')
dib = ImageDraw.Draw(img)

# guardem els punts de B
n = int(input())
XB = [0]*n
YB = [0]*n
for i in range(n):
  XB[i] = int(input())
  YB[i] = int(input())

# guardem els punts de M
m = int(input())
XM = [0]*m
YM = [0]*m
for i in range(m):
  XM[i] = int(input())
  YM[i] = int(input())

# calculem la x minima de B
xb = XB[0]
for i in range(1, n):
  if XB[i] < xb:
    xb = XB[i]

# calculem la x minima de M
xm = XM[0]
for i in range(1, m):
  if XM[i] < xm:
    xm = XM[i]

# pintem si cal la zona del fora de joc
if xb < 50:
  if xb < xm:
    rect(0, 0, xb, 70, 'Red')
  else:
    rect(0, 0, xm, 70,'Orange')

# circumferencia del centre del camp
dib.arc([40, 25, 60, 45], 0, 360, 'White')

# ratlla del mig del camp
rect(50, 0, 50, 70, 'White')

# area petita de l'esquerra
rect(16, 16, 16, 54, 'White')
rect(0, 16, 16, 16, 'White')
rect(0, 54, 16, 54, 'White')

# area gran de l'esquerra
rect(6, 25, 6, 45, 'White')
rect(0, 25, 6, 25, 'White')
rect(0, 45, 6, 45, 'White')

# area petita de la dreta
rect(84, 16, 84, 54, 'White')
rect(100, 16, 84, 16, 'White')
rect(100, 54, 84, 54, 'White')

# area gran de la dreta
rect(94, 25, 94, 45, 'White')
rect(100, 25, 94, 25, 'White')
rect(100, 45, 94, 45, 'White')

# jugadors de B
for i in range(n):
  dib.ellipse([XB[i] - 3, YB[i] - 3, XB[i] + 3, YB[i] + 3], 'Blue')

# jugadors de M
for i in range(m):
  dib.ellipse([XM[i] - 3, YM[i] - 3, XM[i] + 3, YM[i] + 3], 'Magenta')

img.save("output.png")
