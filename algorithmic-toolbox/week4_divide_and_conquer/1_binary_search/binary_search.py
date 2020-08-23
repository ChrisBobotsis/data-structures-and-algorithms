# Uses python3
import sys
import random
import math

def binary_search(a, x):
    left, right = 0, len(a)
    # write your code here
    if right == 0:
        return -1
    pivot = len(a)/2

    # If pivot is even, then we can choose either the upper
    # or lower value
    if pivot % 1 == 0:
        p = random.uniform(0, 1)
        if p > 0.5:
            # Use the lower index for the pivot
            pivot -= 1 
        # Otherwise leave pivot where it is
    else:
        # len(a) is odd so we want the floor
        # of what pivot is
        pivot = int(math.floor(pivot))

    if x > a[pivot]:
        binary_search(a[pivot + 1:], x)
    elif x < a[pivot]:
        binary_search(a[:pivot], x)
    else:
        # This means a[pivot] is equal to x
        # so we return pivot
        return pivot

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

if __name__ == '__main__':
    input = input() 
    data = list(map(int, input.split()))
    n = data[0]
    m = data[n + 1]
    a = data[1 : n + 1]
    for x in data[n + 2:]:
        # replace with the call to binary_search when implemented
        print(linear_search(a, x), end = ' ')
