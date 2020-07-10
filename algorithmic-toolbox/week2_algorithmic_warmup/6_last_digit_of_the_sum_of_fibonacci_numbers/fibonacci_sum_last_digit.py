# Uses python3
import sys
import math

def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current

    return sum % 10


def test():
    # n = 6, m = 3
    f_prev_2 = 0
    f_prev_1 = 1
    f_i = None

    f_prev_1_remainder = 1

    search = True

    i = 0
    sum_ = 1 
    while(search):
        # i = 2, 3, 4, 5, 6, 7, 8, 9



        # 0, 1, 2, 3, 4, 5, 6, 7
        i += 1
        # 1, 2, 3, 5, 8, 13, 21, 34
        f_i = f_prev_1 + f_prev_2
        # 1, 2, 0, 2, 2, 1, 0, 1
        f_i_remainder = f_i % 10
        # F, F, F, F, F, F, F, T
        check = (
            (f_i_remainder == 1) and
            (f_prev_1_remainder == 0)
        )

        if check is True:
            search = False
            break
        # 1, 1, 2, 3, 5, 8, 13,
        f_prev_2 = f_prev_1
        # 1, 2, 3, 5, 8, 13, 21,
        f_prev_1 = f_i
        # 1, 2, 0, 2, 2, 1, 0, 
        f_prev_1_remainder = f_i_remainder

        sum_ += f_i_remainder

    return i, sum_


def my_fibonacci_sum(n):

    remainder = n % 60  

    sum_1 = 0#math.floor(n / 60) % 10

    sum_2 = 1 if remainder != 0 else 0

    f_prev_2 = 0
    f_prev_1 = 1

    for _ in range(remainder - 1):

        f_i = f_prev_1 + f_prev_2

        f_prev_2 = f_prev_1 % 10
        f_prev_1 = f_i % 10

        sum_2 += f_i
        sum_2 = sum_2 % 10

    return (sum_1 + sum_2) % 10


if __name__ == '__main__':
    # input = sys.stdin.read()
    n = int(input())
    print(my_fibonacci_sum(n))
    # print(fibonacci_sum_naive(n))
