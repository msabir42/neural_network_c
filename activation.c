#include "neural.h"


// ----------------- Sigmoid -----------------
t_matrix *matrix_sigmoid(t_matrix *mat)
{
    int rows = mat->row;
    int cols = mat->col;
    t_matrix *output = create_matrix(rows, cols);
    output->content = sigmoid_op(mat);
    return output;
}

float **sigmoid_op(t_matrix *mat)
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
            new[i][j] = 1.0 / (1.0 + exp(-mat->content[i][j]));
            j++;
        }
        i++;
    }
    return new;
}


t_matrix *matrix_softmax(t_matrix *mat)
{
    t_matrix *out = create_matrix(mat->row, mat->col);
    out->content = softmax_op(mat);
    return out;
}

float **softmax_op(t_matrix *mat)
{
    int rows = mat->row;
    float **new = malloc(sizeof(float*) * rows);
    for (int i = 0; i < rows; i++)
        new[i] = malloc(sizeof(float) * 1);

    // 1. Find max value for numerical stability
    float max_val = mat->content[0][0];
    for (int i = 1; i < rows; i++)
        if (mat->content[i][0] > max_val)
            max_val = mat->content[i][0];

    // 2. Exponentiate and sum
    float sum = 0.0f;
    for (int i = 0; i < rows; i++)
    {
        new[i][0] = expf(mat->content[i][0] - max_val);
        sum += new[i][0];
    }

    // 3. Normalize
    for (int i = 0; i < rows; i++)
        new[i][0] /= sum;

    return new;
}


// ----------------- Tanh -----------------
t_matrix *matrix_tanh(t_matrix *mat)
{
    int rows = mat->row;
    int cols = mat->col;
    t_matrix *output = create_matrix(rows, cols);
    output->content = tanh_op(mat);
    return output;
}

float **tanh_op(t_matrix *mat)
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
            new[i][j] = tanh(mat->content[i][j]);
            j++;
        }
        i++;
    }
    return new;
}


// ----------------- ReLU (Rectified Linear Unit) -----------------
// Element-wise operation: replaces negative values with 0
t_matrix *matrix_relu(t_matrix *mat)
{
    int rows = mat->row;
    int cols = mat->col;
    t_matrix *output = create_matrix(rows, cols);
    output->content = relu_op(mat);
    return output;
}

float **relu_op(t_matrix *mat)
{
    int rows = mat->row;
    int cols = mat->col;
    float **new = malloc(sizeof(float*) * rows);
    int i = 0;

    while (i < rows)
    {
        new[i] = malloc(sizeof(float) * cols);
        int j = 0;
        while (j < cols)
        {
            new[i][j] = fmax(0, mat->content[i][j]);  // ReLU: max(0, x)
            j++;
        }
        i++;
    }
    return new;
}

// ----------------- Leaky ReLU -----------------
// Element-wise operation: replaces negative values with a small slope
t_matrix *matrix_leaky_relu(t_matrix *mat, float alpha)
{
    int rows = mat->row;
    int cols = mat->col;
    t_matrix *output = create_matrix(rows, cols);
    output->content = leaky_relu_op(mat, alpha);
    return output;
}

float **leaky_relu_op(t_matrix *mat, float alpha)
{
    int rows = mat->row;
    int cols = mat->col;
    float **new = malloc(sizeof(float*) * rows);
    int i = 0;

    while (i < rows)
    {
        new[i] = malloc(sizeof(float) * cols);
        int j = 0;
        while (j < cols)
        {
            if(mat->content[i][j] > 0)
                new[i][j] = mat->content[i][j];
            else
                new[i][j] = alpha * mat->content[i][j];  // small slope for negative
            j++;
        }
        i++;
    }
    return new;
}

