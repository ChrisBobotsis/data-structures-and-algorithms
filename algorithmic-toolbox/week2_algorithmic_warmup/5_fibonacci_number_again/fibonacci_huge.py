# Uses python3
import sys


def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m


def my_get_fibonacci_huge(n, m):
    # n = 6, m = 3
    f_prev_2 = 0
    f_prev_1 = 1
    f_i = None

    f_prev_1_remainder = 1

    search = True

    count = 0

    while(search):
        # i = 2, 3, 4, 5, 6, 7, 8, 9



        # 0, 1, 2, 3, 4, 5, 6, 7
        count += 1
        # 1, 2, 3, 5, 8, 13, 21, 34
        f_i = f_prev_1 + f_prev_2
        # 1, 2, 0, 2, 2, 1, 0, 1
        f_i_remainder = f_i % m
        # F, F, F, F, F, F, F, T
        check = (
            (f_i_remainder == 1) and
            (f_prev_1_remainder == 0)
        )

        if check is True:
            search = False
        # 1, 1, 2, 3, 5, 8, 13,
        f_prev_2 = f_prev_1
        # 1, 2, 3, 5, 8, 13, 21,
        f_prev_1 = f_i
        # 1, 2, 0, 2, 2, 1, 0, 
        f_prev_1_remainder = f_i_remainder
    
    # n % 8
    i = n % count

    return my_calc_fib(i) % m


def my_calc_fib(n):

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

        fib_array.append(result)

    return fib_array[-1]


if __name__ == '__main__':
    # input = sys.stdin.read()
    n, m = map(int, input().split())
    print(my_get_fibonacci_huge(n, m))
