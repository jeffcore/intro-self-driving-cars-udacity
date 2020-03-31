import math
from math import sqrt
import numbers

def zeroes(height, width):
        """
        Creates a matrix of zeroes.
        """
        g = [[0.0 for _ in range(width)] for __ in range(height)]
        return Matrix(g)

def identity(n):
        """
        Creates a n x n identity matrix.
        """
        I = zeroes(n, n)
        for i in range(n):
            I.g[i][i] = 1.0
        return I

class Matrix(object):

    # Constructor
    def __init__(self, grid):
        self.g = grid
        self.h = len(grid)
        self.w = len(grid[0])

    #
    # Primary matrix math methods
    #############################
 
    def determinant(self):
        """
        Calculates the determinant of a 1x1 or 2x2 matrix.
        """
        if not self.is_square():
            raise(ValueError, "Cannot calculate determinant of non-square matrix.")
        if self.h > 2:
            raise(NotImplementedError, "Calculating determinant not implemented for matrices largerer than 2x2.")
        
        # TODO - your code here
        if self.h == 1:
            return self[0][0]
        elif self.h == 2:  
            a = self[0][0]
            b = self[0][1]
            c = self[1][0]
            d = self[1][1]
            return (a * d) - (c * b)
    
    def trace(self):
        """
        Calculates the trace of a matrix (sum of diagonal entries).
        """
        if not self.is_square():
            raise(ValueError, "Cannot calculate the trace of a non-square matrix.")

        # TODO - your code here
        trace_sum = 0
        for i in range(self.h):            
            trace_sum += self[i][i]
           
        return trace_sum
        
    def inverse(self):
        """
        Calculates the inverse of a 1x1 or 2x2 Matrix.
        """
        if not self.is_square():
            raise(ValueError, "Non-square Matrix does not have an inverse.")
        if self.h > 2:
            raise(NotImplementedError, "inversion not implemented for matrices larger than 2x2.")

        # TODO - your code here
        if self.h == 1:           
            return Matrix([[1 / self[0][0]]])
        elif self.h == 2:
            a = self[0][0]
            b = self[0][1]
            c = self[1][0]
            d = self[1][1]
            
            factor = 1 / (a * d - b * c)
            
            inverse = [[d, -b], [-c, a]]
            
            for i in range(len(inverse)):
                for j in range(len(inverse[0])):
                    inverse[i][j] = factor * inverse[i][j]
            return Matrix(inverse)
        
    def T(self):
        """
        Returns a transposed copy of this Matrix.
        """
        # TODO - your code here
        matrix_transpose = []

        for i in range(self.w):
            row = []
            for j in range(self.h):
                row.append(self[j][i])
            matrix_transpose.append(row)
     
        return Matrix(matrix_transpose)
    
    def is_square(self):
        return self.h == self.w

    #
    # Begin Operator Overloading
    ############################
    def __getitem__(self,idx):
        """
        Defines the behavior of using square brackets [] on instances
        of this class.

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > my_matrix[0]
          [1, 2]

        > my_matrix[0][0]
          1
        """
        return self.g[idx]

    def __repr__(self):
        """
        Defines the behavior of calling print on an instance of this class.
        """
        s = ""
        for row in self.g:
            s += " ".join(["{} ".format(x) for x in row])
            s += "\n"
        return s

    def __add__(self,other):
        """
        Defines the behavior of the + operator
        """
        if self.h != other.h or self.w != other.w:
            raise(ValueError, "Matrices can only be added if the dimensions are the same") 
        #   
        # TODO - your code here
        #
        matrix_sum = []

        for i in range(self.h):
            row = []
            for j in range(self.w):
                row.append(self[i][j] + other[i][j])
            matrix_sum.append(row)
            
        return Matrix(matrix_sum)
   
    def __neg__(self):
        """
        Defines the behavior of - operator (NOT subtraction)

        Example:

        > my_matrix = Matrix([ [1, 2], [3, 4] ])
        > negative  = -my_matrix
        > print(negative)
          -1.0  -2.0
          -3.0  -4.0
        """
        #   
        # TODO - your code here
        #
        matrix_neg = []

        for i in range(self.h):
            row = []
            for j in range(self.w):
                row.append(-self[i][j])
            matrix_neg.append(row)
            
        return Matrix(matrix_neg)
    
    
    def __sub__(self, other):
        """
        Defines the behavior of - operator (as subtraction)
        """
        #   
        # TODO - your code here
        #
        
        matrix_sub = []

        for i in range(self.h):
            row = []
            for j in range(self.w):
                row.append(self[i][j] - other[i][j])
            matrix_sub.append(row)
            
        return Matrix(matrix_sub)
    
    
    def __mul__(self, other):
        """
        Defines the behavior of * operator (matrix multiplication)
        """
        #   
        # TODO - your code here
        #
        product = []

        # Take the transpose of matrixB and store the result
        transposeB = other.T()
        
        for r1 in range(self.h):
            new_row = []
            for r2 in range(transposeB.h):
                result = 0
                matrix1_row = self[r1]
                matrix2_row = transposeB[r2]
                for i in range(0,len(matrix1_row)):
                    result += matrix1_row[i] * matrix2_row[i]
              
                new_row.append(result)
            
            product.append(new_row)
        
        return Matrix(product)

        
    def __rmul__(self, other):
        """
        Called when the thing on the left of the * is not a matrix.

        Example:

        > identity = Matrix([ [1,0], [0,1] ])
        > doubled  = 2 * identity
        > print(doubled)
          2.0  0.0
          0.0  2.0
        """
        if isinstance(other, numbers.Number):
            
            #   
            # TODO - your code here
            #
            matrix_rmul = []

            for i in range(self.h):
                row = []
                for j in range(self.w):
                    row.append(other * self[i][j])
                matrix_rmul.append(row)

            return Matrix(matrix_rmul)
   