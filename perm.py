import math

def fun(arr):
    print(" ".join(map(str, arr)))

def swap(arr, a, b):
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp

def rec(arr, p, a):
    if p == a-2:
        fun(arr)
        swap(arr, p, a-1)
        fun(arr)

    else:
        for i in range(p, a):
            swap(arr, i, p)
            tarr = arr.copy()   
            rec(tarr, p+1, a)

        

a = int(input("Enter no: "))
array = list(range(1, a + 1))

print(math.factorial(a))
rec(array, 0, a)
