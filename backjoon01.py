list1 = []
result = 0
for i in range(0,5):
    list1.append(int(input()))
    if (list1[i] < 40):
        list1[i] = 40
    result += list1[i]
print (int(result/5))
