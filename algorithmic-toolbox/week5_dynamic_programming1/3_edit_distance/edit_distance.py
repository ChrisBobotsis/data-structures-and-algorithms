# Uses python3

def edit_distance(s, t):
    #write your code here

    # s is rows
    # t is columns
    D = [[0]*(len(t) + 1)]*(len(s) + 1)
    D = D.copy()

    rows, cols = (len(s) + 1, len(t) + 1) 
    D = [[0 for i in range(cols)] for j in range(rows)]

    # Set all columns in first row
    for i in range(len(t) + 1):
        D[0][i] = i

    # Set all rows in first column
    for i in range(len(s) + 1):
        D[i][0] = i

    for j in range(1, len(t) + 1):
        for i in range(1, len(s) + 1):
            insertion = D[i][j-1] + 1
            deletion = D[i-1][j] + 1
            match = D[i-1][j-1]
            mismatch = D[i-1][j-1] + 1
            if s[i-1] == t[j-1]:
                D[i][j] = min(
                    insertion,
                    deletion,
                    match,
                )
            else:
                D[i][j] = min(
                    insertion,
                    deletion,
                    mismatch,
                )
    
    return D[-1][-1]


if __name__ == "__main__":
    print(edit_distance(input(), input()))
