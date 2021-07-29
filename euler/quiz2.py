import re

cost = input()
cost = cost[:-1].replace(",", "")

first = cost[:-4]
last = cost[-4:]

print(first)
print(last)

values = ["원", "천", "만", "억", "조"]
numbers = {"1": "일", "2": "이", "3": "삼", "4": "사", "5": "오",
           "6": "육", "7": "칠", "8": "팔", "9": "구", "0": ""}
answer = ""


print(answer)
