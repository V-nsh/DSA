def anagram(str1, str2):
    # str1 = str1.lower()
    # str2 = str2.lower()
    hashMap = dict()
    for i in range(len(str1)):
        if(hashMap.get(str1[i]) == None):
            hashMap[str1[i]] = 0
    print(hashMap)
    for i in range(len(str2)):
        if(hashMap.get(str2[i])==None):
            return "no"
    return "yes"

# str1 = "listen"
# str2 = "silent"
str1 = input().lower()
str2 = input().lower()
print(anagram(str1, str2))