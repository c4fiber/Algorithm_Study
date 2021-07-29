num=str(input())
length=len(num)
cnt=0

for i in range(1,int(num)+1):
    val=str(i)
    if len(val) < 3:
        cnt += 1
    elif len({*map( lambda x,y : y-x, map(int,val[:length]), map(int,val[1:]) )}) == 1:
        cnt +=1 
    else:
        continue
print(cnt)
