#include "neural.h"

t_matrix *matrix_multiplication(t_matrix *right, t_matrix *left)
{
    if (right->col == left->row)
    {
        int rows = right->row;
        int cols = left->col;
        t_matrix *output = create_matrix(rows, cols);
        output->content = mp(right, left);
        return output;
    }
    return NULL;
}

float **mp(t_matrix *right, t_matrix *left)
{
    int rows = right->row;
    int cols = left->col;
    int shared = right->col;
    float **new = malloc(sizeof(float *) * rows);
    int i = 0;

    while (i < rows)
    {
        new[i] = malloc(sizeof(float) * cols);
        int j = 0;
        while (j < cols)
        {
            float sum = 0;
            int k = 0;
            while (k < shared)
            {
                sum += right->content[i][k] * left->content[k][j];
                k++;
            }
            new[i][j] = sum;
            j++;
        }
        i++;
    }
    return new;
}
