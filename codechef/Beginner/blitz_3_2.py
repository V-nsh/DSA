# cook your dish here
for _ in range(int(input())):
    T, A, B =  map(int, input().split())
    total, left = 0, 0
    total = 2*(180+T)
    left = A+B
    print(total-left)

# for a 3 min match there's 2*180 sec, plus 2 for each move so if there are are 10 moves then 2*10
# therefore total time that should ideally be given must be 2*(180+T)
# A and B is the amount of time left, therefore A+B time is left, subtract both to get the remainig unutilized time