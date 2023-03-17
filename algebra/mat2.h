#ifndef MAT2_H
#define MAT2_H

#include <iostream>

template <typename T, size_t rows, size_t cols>
class mat2
{
public:
    // constructor
    mat2() { }

    // get value in position (r, c)
    T get(unsigned int r, unsigned int c) const { return matrix[r][c]; }

    // get number of rows
    size_t get_rows() const { return rows; }

    // get number of columns
    size_t get_cols() const { return cols; }

    // set value in position (r, c) to <value>
    void set(unsigned int r, unsigned int c, T value) { matrix[r][c] = value; }

    // display the matrix
    void show() const
    {
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                std::cout << matrix[i][j] << " " << std::flush;
            }
            std::cout << std::endl;
        }
    }

    // destructor
    ~mat2() { }

private:
    T matrix[rows][cols];
};

#endif
