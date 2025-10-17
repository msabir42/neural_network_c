#include "neural.h"

t_matrix *matrix_transpose(t_matrix *mat)
{
    int rows = mat->row;
    int cols = mat->col;
    t_matrix *output = create_matrix(cols, rows);  
    output->content = transpose(mat);              
    return output;
}

float **transpose(t_matrix *matrix)
{
    int rows = matrix->row;
    int cols = matrix->col;
    float **new = malloc(sizeof(float *) * cols);  
    int i = 0;

    while (i < cols)
    {
        new[i] = malloc(sizeof(float) * rows);     
        int j = 0;
        while (j < rows)
        {
            new[i][j] = matrix->content[j][i];    
            j++;
        }
        i++;
    }
    return new;
}
