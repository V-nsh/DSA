def findCarries(num1, num2):
    tot = 0
    carry = 0
    totalCarries = 0
    while num1>0:
        tot = num1%10+num2%10 + carry
        carry = tot//10
        if tot>=10:
            totalCarries += carry
        num1 = num1//10
        num2 = num2//10
    return totalCarries

def findCarriesHelper(num1, num2):
    if num1>num2:
        return findCarries(num1, num2)
    else:
        return findCarries(num2, num1)

num1 = int(input())
num2 = int(input())
print(findCarriesHelper(num1, num2))
