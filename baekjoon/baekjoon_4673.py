def makeSelfNum(num):
    split = map(int,str(num))
    for i in split:
        num += i
    return num

notSelfNum = set()
for i in range(1,10000):
    if i not in notSelfNum:
        print(i)
    while(i < 10000):
        i = makeSelfNum(i)
        notSelfNum.add(i)
