def put(L, a):
    if len(L) == 0:
        L.append(a)
    else:
        for i in range(len(L)):
            if a < L[i]:
                L.insert(i,a)
    return L
    
n=int(input()) #출력값 : down[-1]
down=[]
up=[]
down.append(int(input()))
for j in range(1, n):
    i = int(input())
    if j%2 == 0: #현재 가진 숫자가 짝수개 일때
        if i <= down[-1]:
            down=put(down,i)
            #down.append(i)
            #down.sort()
        else:
            up = put(up,i)
            #up.append(i)
            #up.sort()
            down.append(up.pop(0))
            
           
    else:
        if i <= down[-1]:
            up.insert(0,down.pop())
            down = put(down,i)
            #down.append(i)
            #down.sort()
        else:
            up = put(up,i)
            #up.append(i)
            #up.sort()

    print(down)
    print(up)
    print(down[-1])

