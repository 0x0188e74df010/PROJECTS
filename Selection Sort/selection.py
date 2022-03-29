import random
import time

def sort(arr):
    for i in range(len(arr)):
        # print(arr)
        min = i
        for j in range(i, len(arr)):
            if arr[j] < arr[min]:
                min = j
        arr[min], arr[i] = arr[i], arr[min]
    

arr = [i for i in range(5000)]
random.shuffle(arr)

t = time.time()
sort(arr)
print(time.time() - t)