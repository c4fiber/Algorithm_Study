menu = []
temp = 2000
total = 0
for i in range(0,3):
    menu.append(int(input()))
    if temp > menu[i]: temp = menu[i]
total += temp

temp=2000
for i in range(3,5):
    menu.append(int(input()))
    if temp > menu[i]: temp = menu[i]

total += temp
print (total-50)
