from functools import reduce

data = [
    "this is a hello world",
    "this is a test",
]

def mapper(text):
    words = text.split()
    word_count = [(word, 1) for word in words]
    return word_count

def reducer(word_count1, word_count2):
    merged_word_count = {}

    for word, count in word_count1:
        merged_word_count[word] = merged_word_count.get(word, 0) + count

    for word, count in word_count2:
        merged_word_count[word] = merged_word_count.get(word, 0) + count

    return [(word, count) for word, count in merged_word_count.items()]

mapped_data = list(map(mapper, data))
reduced_data = reduce(reducer, mapped_data)

for word, count in reduced_data:
    print(f"{word}:{count}")