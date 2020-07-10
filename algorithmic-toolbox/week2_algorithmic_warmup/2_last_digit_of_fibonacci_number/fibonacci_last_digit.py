# Uses python3
import sys


def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % 10


def my_get_fibonacci_last_digit(n):

    if n == 0:
        return 0
    if n == 1:
        return 1

    fib_array = []

    # f_0 = 0
    fib_array.append(0)
    # f_1 = 1
    fib_array.append(1)

    for i in range(2,n+1):

        result = fib_array[i-1] + fib_array[i-2]

        result = result%10

        fib_array.append(result)

    return fib_array[-1]


if __name__ == '__main__':
    # input = sys.stdin.read()
    n = int(input())
    print(my_get_fibonacci_last_digit(n))
