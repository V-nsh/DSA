'''
https://www.codingninjas.com/studio/library/30-most-common-accenture-coding-questions
'''
def differenceofSum(n, m):
    total = n*(n+1)/2
    nonDiv = 0
    for i in range(n+1):
        if i%m==0:
            continue
        nonDiv += i
    div = total-nonDiv
    return int(abs(nonDiv-div))

'''
accenture format ig
'''
m = int(input())
n = int(input())
print(differenceofSum(n, m))