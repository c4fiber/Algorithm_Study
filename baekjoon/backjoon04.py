num = int(input())
for i in range(0,num):
    for j in range(0,i):
        print (' ',end='')
    for k in range(0,(num-i)*2-1):
        print('*',end='')
    print(' ')
for i in range(0,num-1):
    for j in range(0,num-i-2):
        print (' ',end='')
    for k in range(0,i*2+3):
        print('*', end='')
    print(' ')

    
