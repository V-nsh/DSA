# cooK your dish here
for _ in range(int(input())):
    K, N = map(int, input().split())
    if N==1 and K%4==0 or (N==0 and K%4 != 0):
        print('On')
    elif N==0 and K%4==0:
        print('Off')
    else:
        print('Ambiguous')

# if it starts from 1 then it can be on any level from 1-3, unless it lands on the same level that is %4 is 0 it can ambiguous