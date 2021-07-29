def printStar(cnt, isOdd):
    if isOdd == True: #홀수 줄은 홀짝에 따라 다르다
        for i in range(0, cnt//2): print('* ', end='')
    else:
        for i in range(0, cnt//2-1): print ('* ', end='') 
    print('*')
    
    for i in range(0, cnt//2):   print(' *', end='') #두 번째 줄은 같음
    print('')
    
num = int(input())
isOdd = True if num%2==1 else False

for i in range(0,num):
    printStar(num, isOdd)
