# Uses python3
import sys
import numpy as np

def optimal_weight(W, w):
    # write your code here
    result = 0
    for x in w:
        if result + x <= W:
            result = result + x
    return result

def my_optimal_weight(W, w):

    # Array for optimal value of each weight
    weight_values = np.zeros(W+1) # [0]*(W + 1)

    rows, cols = (len(w), W + 1)
    # Array of num items by W; all binary
    items_array = np.zeros((rows, cols)) # items_array = [[0 for i in range(cols)] for j in range(rows)]

    for weight in range(1, cols):
        prev_val = -1
        val = -1

        for j in range(rows):
            weight_j = w[j]
            # Ensure weight_j can fit into this weight
            bit1 = weight_j <= weight
            # Check to see if item j was used at this weight
            bit2 = False
            if bit1 == True:
                bit2 = items_array[j, weight - weight_j] == 0
            if bit2 == True:
                val = weight_values[weight - weight_j] + weight_j

            if prev_val >= val:
                # Set the bit back to 0 for this weight
                '''items_array[][]
                items_array[j][weight] == 0'''
            else:
                # We are setting it to what the previous action space was
                # plus the new addition
                items_array[:, weight] = items_array[:, weight - weight_j]
                # We are now adding it
                items_array[j, weight] = 1

                prev_val = val

        if val == -1:
            weight_values[weight] = weight_values[weight - 1]
            items_array[:, weight] = items_array[:, weight - 1]
        else:
            weight_values[weight] = max(prev_val, val)

    return int(weight_values[W])


if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(my_optimal_weight(W, w))
