def DayToNumber(day):
    return ['dilluns', 'dimarts', 'dimecres', 'dijous', 'divendres', 'dissabte', 'diumenge'].index(day)

def Distance(x, y):
    return y - x if y > x else y + 7 - x

day1 = DayToNumber(input())
day2 = DayToNumber(input())

if Distance(day1, day2) > 3:
    print('B')
else:
    print('A')
