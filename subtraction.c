#include "neural.h"

t_matrix *matrix_subtraction(t_matrix *right, t_matrix *left)
{
    if (right->row == left->row && right->col == left->col)
    {
        int rows = right->row;
        int cols = right->col;
        t_matrix *output = create_matrix(rows, cols);
        output->content = sub(right, left);
        return output;
    }
    return NULL;
}

float **sub(t_matrix *right, t_matrix *left)
{
    int rows = right->row;
    int cols = right->col;
    float **new = malloc(sizeof(float *) * rows);
    int i = 0;
    while (i < rows)
    {
        new[i] = malloc(sizeof(float) * cols);
        int j = 0;
        while (j < cols)
        {
            new[i][j] = right->content[i][j] - left->content[i][j];
            j++;
        }
        i++;
    }
    return new;
}
