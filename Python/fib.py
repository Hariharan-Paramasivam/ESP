def fibnonic(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibnonic(n-1) + fibnonic(n-2)


def matrix_multiplication(x,y):
    result = [[0,0,0],
              [0,0,0],
              [0,0,0]]
    for i in range(len(x)):
        for j in range(len(y[0])):
            for k in range(len(y)):
                result[i][j] += x[i][k] * y[k][j]
    return result   

