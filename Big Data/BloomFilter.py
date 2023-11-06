import hashlib

class BloomFilter():
    def __init__(self, size, iterations):
        self.size = size
        self.iterations = iterations
        self.bit_array = [0] * size

    def add(self, item):
        for i in range(self.iterations):
            index = hash(item+str(i)) % self.size
            self.bit_array[index] = 1

    def test(self, item):
        for i in range(self.iterations):
            index = hash(item+str(i)) % self.size
            if self.bit_array[index]==0:
                return False
        return True
    
bloom = BloomFilter(100, 3)
bloom.add("apple")
bloom.add("orange")
bloom.add("peach")

print(bloom.test("apple"))