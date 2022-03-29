import random
import time

def sort(arr):
    for i in range(1, len(arr)):
        # print(arr)
        j = i
        while j > 0 and arr[j] < arr[j-1]:
            arr[j], arr[j-1] = arr[j-1], arr[j]
            j -= 1
    # print(arr)

arr = [i for i in range(5000)]
random.shuffle(arr)

t = time.time()
sort(arr)
print(time.time() - t)