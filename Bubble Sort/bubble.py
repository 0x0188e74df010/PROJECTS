import random
import time

def sort(arr):
    for i in range(len(arr) - 1):
        # print(f"i: {i}")
        for j in range(len(arr) - 1 - i):
            # print(f"j: {j}")
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
            # print(arr)

arr = [i for i in range(5000)]
random.shuffle(arr)

t = time.time()
sort(arr)
print(time.time() - t)
