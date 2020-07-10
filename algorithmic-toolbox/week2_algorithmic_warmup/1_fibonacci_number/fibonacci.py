# Uses python3
def calc_fib(n):
    if (n <= 1):
        return n

    return calc_fib(n - 1) + calc_fib(n - 2)

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

n = int(input())
#print(calc_fib(n))
print(my_calc_fib(n))

# --- Tests ----
"""for i in range(30):

    if calc_fib(i) != my_calc_fib(i):
        print(i)
        break
"""
    
