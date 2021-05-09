# Uses python3
import sys
import random

def partition3(a, l, r):
    #write your code here
    x = a[l]
    j = l
    # e stands for equal
    e = l
    for i in range(l + 1, r + 1):
        #import pdb; pdb.set_trace()
        if a[i] < x:
            j += 1
            e += 1
            '''if e <= j:
                e = j + 1'''
            #a[e], a[j], a[i] = a[j], a[i], a[e]
            #a[j], a[i] = a[i], a[j]

            tmp_i = a[i] # 0
            tmp_j = a[j] # 8
            tmp_e = a[e] # 0

            a[e] = tmp_j # 8
            if e != i:
                a[i] = tmp_e # 
            a[j] = tmp_i

            '''if a[e] > x:
                a[i], a[e] = a[e], a[i]'''
        elif a[i] == x:
            e += 1
            a[i], a[e] = a[e], a[i]

    # Puts a[l], which is the pivot, into the middle
    # of the values less and greater than it
    a[l], a[j] = a[j], a[l]
    #import pdb; pdb.set_trace()
    return j, e

def partition2(a, l, r):
    x = a[l]
    j = l
    for i in range(l + 1, r + 1):
        if a[i] <= x:
            j += 1
            a[i], a[j] = a[j], a[i]
    # Puts a[l], which is the pivot, into the middle
    # of the values less and greater than it
    a[l], a[j] = a[j], a[l]
    return j


def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    #print(k)
    #import pdb; pdb.set_trace()
    a[l], a[k] = a[k], a[l]
    #use partition3
    j, e = partition3(a, l, r)
    randomized_quick_sort(a, l, j - 1)
    randomized_quick_sort(a, e + 1, r)


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    randomized_quick_sort(a, 0, n - 1)
    for x in a:
        print(x, end=' ')



"""
TODO List

1. Change partition2 to partition3
2. Remove  the last recursion call and replace
with while loop (tail recursion elimination)
3. Implement partition3
"""