def trailing_zero(x):
    if x==0:
        return 1
    count = 0
    while x&1==0:
        x = x>>1
        count += 1
    return count

def hash(x):
    return (3*x+1)%5

def FlajoletMartin(stream):
    max_zero = 0
    # for i in range(len(stream)):
    #     stream[i] = hash(stream[i])
    for i in range(len(stream)):
        max_zero = max(max_zero, trailing_zero(stream[i]))
    return 2**max_zero

df = input("Enter the data stream: ")
df = list(map(int, df.split(" ")))
print("The estimated number of distinct elements in the stream is: ", FlajoletMartin(df))