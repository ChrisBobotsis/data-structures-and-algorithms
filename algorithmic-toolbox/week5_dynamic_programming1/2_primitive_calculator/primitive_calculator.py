# Uses python3
import sys

OPERATIONS = []

def my_optimal_sequence(n):

    num_operations = [0, 0] + [float("inf")]*(n-1)

    sequences = {
        1: [1],
    }

    if n == 1:
        return [1]

    for i in range(2, n + 1):

        # Check dividing by 3
        i_divide_3 =  i / 3

        # Check if it is an integer
        if i_divide_3 % 1 != 0:
            i_divide_3_ops = float("inf")
        else:
            i_divide_3 = int(i_divide_3)
            i_divide_3_ops = num_operations[i_divide_3]

        # Check dividing by 2
        i_divide_2 = i / 2

        # Check if it is an integer
        if i_divide_2 % 1 != 0:
            i_divide_2_ops = float("inf")
        else:
            i_divide_2 = int(i_divide_2)
            i_divide_2_ops = num_operations[i_divide_2]

        # Check subtracting by 1
        i_minus_1 = int(i - 1)
        i_minus_1_ops = num_operations[i_minus_1]


        num_operations[i] = (
            min(
                i_divide_3_ops,
                i_divide_2_ops,
                i_minus_1_ops,
            ) + 1
        )

        if num_operations[i] - 1 == i_divide_3_ops:
            sequences[i] = sequences[i_divide_3] + [i]
        elif num_operations[i] - 1 == i_divide_2_ops:
            sequences[i] = sequences[i_divide_2] + [i]
        else:
            sequences[i] = sequences[i_minus_1] + [i]

    return sequences[n]




"""
For each number up to our given number
we want to know what the optimal number of operations is


at a given number, check for all 3 previous operations:
    i) / 3
    ii) / 2
    iii) - 1

Then see choose the min number of operations from all of those and + 1

You have to also check to make sure that each of those operations is a valid integer
"""

def optimal_sequence(n):
    sequence = []
    while n >= 1:
        sequence.append(n)
        if n % 3 == 0:
            n = n // 3
        elif n % 2 == 0:
            n = n // 2
        else:
            n = n - 1
    return reversed(sequence)

input = sys.stdin.read()
n = int(input)
'''sequence = list(optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
print()'''
my_sequence = list(my_optimal_sequence(n))
print(len(my_sequence) - 1)
for x in my_sequence:
    print(x, end=' ')
