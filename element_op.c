#include "neural.h"
#include <math.h>

// ----------------- Element-wise matrix multiplication (Hadamard product) -----------------
t_matrix *element_multi(t_matrix* right, t_matrix* left)
{
    if(right->row == left->row && right->col == left->col)
    {
        int rows = right->row;
        int columns = left->col;
        t_matrix* output = create_matrix(rows,columns);
        output->content = element_multi_op(right,left);
        return output;
    }
    return NULL;
}

float** element_multi_op(t_matrix* right, t_matrix* left)
{
    int rows = right->row;
    int columns = right->col;
    int i = 0;
    float** new = malloc(sizeof(float*) * rows);
    while (i < rows)
    {
        new[i] = malloc(sizeof(float) * columns);
        int j = 0;
        while (j < columns)
        {
            new[i][j] = right->content[i][j] * left->content[i][j];
            j++;
        }
        i++;
    }
    return new;
}

// ----------------- Element-wise matrix division by scalar -----------------
t_matrix *element_div_scalar(t_matrix* right, float scalar)
{
    int rows = right->row;
    int columns = right->col;
    t_matrix* output = create_matrix(rows,columns);
    output->content = element_scalar_div_op(right,scalar);
    return output;
}

float** element_scalar_div_op(t_matrix* mat, float scalar)
{
    int rows = mat->row;
    int columns = mat->col;
    int i = 0;
    float** new = malloc(sizeof(float*) * rows);
    while (i < rows)
    {
        new[i] = malloc(sizeof(float) * columns);
        int j = 0;
        while (j < columns)
        {
            new[i][j] = mat->content[i][j] / scalar;
            j++;
        }
        i++;
    }
    return new;
}

// ----------------- Element-wise matrix multiplication by scalar -----------------
t_matrix *element_multi_scalar(t_matrix* right, float scalar)
{
    int rows = right->row;
    int columns = right->col;
    t_matrix* output = create_matrix(rows,columns);
    output->content = element_scalar_multi_op(right,scalar);
    return output;
}

float** element_scalar_multi_op(t_matrix* mat, float scalar)
{
    int rows = mat->row;
    int columns = mat->col;
    int i = 0;
    float** new = malloc(sizeof(float*) * rows);
    while (i < rows)
    {
        new[i] = malloc(sizeof(float) * columns);
        int j = 0;
        while (j < columns)
        {
            new[i][j] = mat->content[i][j] * scalar;
            j++;
        }
        i++;
    }
    return new;
}

// ----------------- Element-wise matrix addition with scalar -----------------
t_matrix *element_add_scalar(t_matrix *mat, float scalar)
{
    int rows = mat->row;
    int cols = mat->col;
    t_matrix *output = create_matrix(rows, cols);
    output->content = element_add_scalar_op(mat, scalar);
    return output;
}

float **element_add_scalar_op(t_matrix *mat, float scalar)
{
    int rows = mat->row;
    int cols = mat->col;
    float **new = malloc(sizeof(float *) * rows);
    int i = 0;
    while (i < rows)
    {
        new[i] = malloc(sizeof(float) * cols);
        int j = 0;
        while (j < cols)
        {
            new[i][j] = mat->content[i][j] + scalar;  
            j++;
        }
        i++;
    }
    return new;
}

// ----------------- Element-wise matrix subtraction with scalar -----------------
t_matrix *element_sub_scalar(t_matrix *mat, float scalar)
{
    int rows = mat->row;
    int cols = mat->col;
    t_matrix *output = create_matrix(rows, cols);
    output->content = element_sub_scalar_op(mat, scalar);
    return output;
}

float **element_sub_scalar_op(t_matrix *mat, float scalar)
{
    int rows = mat->row;
    int cols = mat->col;
    float **new = malloc(sizeof(float *) * rows);
    int i = 0;
    while (i < rows)
    {
        new[i] = malloc(sizeof(float) * cols);
        int j = 0;
        while (j < cols)
        {
            new[i][j] = mat->content[i][j] - scalar;  
            j++;
        }
        i++;
    }
    return new;
}
