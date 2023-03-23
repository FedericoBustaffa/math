#ifndef MAT2_H
#define MAT2_H

#include <iostream>

class mat2
{
public:
    // constructor
    mat2(size_t rows, size_t cols)
        : rows(rows), cols(cols)
    {
        matrix = new double *[rows];
        for (size_t i = 0; i < rows; i++)
        {
            matrix[i] = new double[cols];
            for (size_t j = 0; j < cols; j++)
                matrix[i][j] = 0;
        }
    }

    // get value in position (r, c)
    double get(size_t r, size_t c) const { return matrix[r][c]; }

    // get number of rows
    size_t get_rows() const { return rows; }

    // get number of columns
    size_t get_cols() const { return cols; }

    // set value in position (r, c) to <value>
    void set(size_t r, size_t c, double value) { matrix[r][c] = value; }

    mat2 rc_product(const mat2 &m)
    {
        size_t m_cols = m.get_cols();
        mat2 r(m_cols, rows);
        double s = 0;
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                s = 0;
                for (size_t k = 0; k < rows; k++)
                {
                    s += matrix[i][k] * m.get(k, j);
                }
                r.set(i, j, s);
            }
        }

        return r;
    }

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
    ~mat2()
    {
        for (size_t i = 0; i < cols; i++)
            delete[] matrix[i];

        delete[] matrix;
    }

private:
    size_t rows, cols;
    double **matrix;
};

#endif
