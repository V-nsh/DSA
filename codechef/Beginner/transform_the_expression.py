class TransformRPN(object):
    def postfix(self, str):
        stack = []
        for i in str:
            if i=='(':
                pass
            elif i.isalpha():
                print(i, end='')
            elif i in '+-*/^':
                stack.append(i)
            elif i==')':
                print(stack.pop(), end='')

if __name__=='__main__':
    t = int(input())
    s = TransformRPN()
    for i in range(t):
        str = input()
        s.postfix(str)
        print()