# Uses python3
from sys import stdin

def fibonacci_sum_squares_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current * current

    return sum % 10


def my_fibonacci_sum_squares(n):

    remainder = n % 60  

    sum_1 = 0#math.floor(n / 60) % 10

    sum_2 = 1 if remainder != 0 else 0

    f_prev_2 = 0
    f_prev_1 = 1

    for _ in range(remainder - 1):

        f_i = f_prev_1 + f_prev_2

        f_prev_2 = f_prev_1 % 10
        f_prev_1 = f_i % 10

        sum_2 += (f_i**2 % 10)
        sum_2 = sum_2 % 10

    return (sum_1 + sum_2) % 10


if __name__ == '__main__':
    # n = int(stdin.read())
    n = int(input())
    # print(fibonacci_sum_squares_naive(n))
    print(my_fibonacci_sum_squares(n))
