# python3
import random

def max_pairwise_product(numbers):
    n = len(numbers)
    #     max_product = 0 

    index1 = 0
    max1 = 0
    for i  in range(n):
       
        if numbers[i] > max1:

            max1 = numbers[i]
            index1 = i
            
    index2 = 0
    max2 = 0

    for i in range(n):

        # Don't want to be the same index, must be higher than max2,
        if i != index1:
            if numbers[i] > max2:
                max2 = numbers[i]
                index2 = i


    max_product = max1 * max2

    return max_product

def max_base_case(numbers):
    n = len(numbers)
    max_product = 0
    for first in range(n):
        for second in range(first + 1, n):
            max_product = max(max_product, numbers[first] * numbers[second])

    return max_product

if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product(input_numbers))

