import numpy as np
arreglo1 = [
    [5, 3, 4, 6, 7, 8, 9, 1, 2],
    [6, 7, 2, 1, 9, 0, 3, 4, 8],
    [1, 0, 0, 3, 4, 2, 5, 6, 0],
    [8, 5, 9, 7, 6, 1, 0, 2, 0],
    [4, 2, 6, 8, 5, 3, 7, 9, 1],
    [7, 1, 3, 9, 2, 4, 8, 5, 6],
    [9, 0, 1, 5, 3, 7, 2, 1, 4],
    [2, 8, 7, 4, 1, 9, 6, 3, 5],
    [3, 0, 0, 4, 8, 1, 1, 7, 9]
   ]

arreglo2 = [
    [5, 3, 4, 6, 7, 8, 9, 1, 2],
    [6, 7, 2, 1, 9, 5, 3, 4, 8],
    [1, 9, 8, 3, 4, 2, 5, 6, 7],
    [8, 5, 9, 7, 6, 1, 4, 2, 3],
    [4, 2, 6, 8, 5, 3, 7, 9, 1],
    [7, 1, 3, 9, 2, 4, 8, 5, 6],
    [9, 6, 1, 5, 3, 7, 2, 8, 4],
    [2, 8, 7, 4, 1, 9, 6, 3, 5],
    [3, 4, 5, 2, 8, 6, 1, 7, 9]
   ]

class SudokuValidator():

    def __init__(self, sudoku):
        self.sudoku = np.array(sudoku)

    def __str__(self):
        return "Validator for sudoku:\n" + str(self.sudoku) + '\n' + str(self.checkSolution())

    def checkSolution(self):
        if(self.__test_squares(self.sudoku) and
            self.__test_cols(self.sudoku) and
            self.__test_rows(self.sudoku)):
            return True
        return False

    def __test_squares(self, arreglo):
        for i in range(0, len(arreglo)-2, 3):
            for j in range(0, len(arreglo)-2, 3):
                paquetito = arreglo[i:i+3, j:j+3]
                if len(paquetito.flatten()) > len(set(paquetito.flatten())):
                    return False
        return True

    def __test_rows(self, arreglo):
        for i in range(0, len(arreglo)):
            fila = arreglo[i]
            if len(fila) > len(set(fila)):
                return False
        return True

    def __test_cols(self, arreglo):
        for i in range(0, len(arreglo)):
            col = arreglo[:,i]
            if len(col) > len(set(col)):
                return False
        return True

print(SudokuValidator([
    [5, 3, 4, 6, 7, 8, 9, 1, 2],
    [6, 7, 2, 1, 9, 5, 3, 4, 8],
    [1, 9, 8, 3, 4, 2, 5, 6, 7],
    [8, 5, 9, 7, 6, 1, 4, 2, 3],
    [4, 2, 6, 8, 5, 3, 7, 9, 1],
    [7, 1, 3, 9, 2, 4, 8, 5, 6],
    [9, 6, 1, 5, 3, 7, 2, 8, 4],
    [2, 8, 7, 4, 1, 9, 6, 3, 5],
    [3, 4, 5, 2, 8, 6, 1, 7, 9]
   ]))
