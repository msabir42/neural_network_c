#ifndef NEURAL_H
#define NEURAL_H

#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include <fcntl.h>

typedef struct s_matrix
{
    int col;
    int row;
    float** content;

} t_matrix;

typedef struct s_layer
{
    unsigned int input_size;
    unsigned int output_size;
    t_matrix* weights;
    t_matrix* bias;
    t_matrix* output;
} t_layer;


typedef struct s_neural
{
    t_layer* hidden;
    t_layer* output;
} t_neural;

void init_layer(t_layer* layer,int input_size,int output_size);

// Matrix operations
t_matrix *create_matrix(int r, int c);
float allocate_col(float **arr, int row, int col);
void free_matrix(t_matrix *mat);

// Matrix mathematical operations
t_matrix *matrix_transpose(t_matrix *mat);
t_matrix *matrix_multiplication(t_matrix *right, t_matrix *left);
t_matrix *matrix_addition(t_matrix *right, t_matrix *left);
t_matrix *matrix_subtraction(t_matrix *right, t_matrix *left);

// Element-wise operations
t_matrix *element_multi(t_matrix* right, t_matrix* left);
t_matrix *element_div_scalar(t_matrix* right, float scalar);
t_matrix *element_multi_scalar(t_matrix* right, float scalar);
t_matrix *element_add_scalar(t_matrix *mat, float scalar);
t_matrix *element_sub_scalar(t_matrix *mat, float scalar);

// Activation functions
t_matrix *matrix_sigmoid(t_matrix *mat);
t_matrix *matrix_tanh(t_matrix *mat);
t_matrix *matrix_relu(t_matrix *mat);
t_matrix *matrix_leaky_relu(t_matrix *mat, float alpha);

// Helper functions
float* flatten(t_matrix* mat);

// Internal operations (used by the matrix functions)
float **transpose(t_matrix *matrix);
float **mp(t_matrix *right, t_matrix *left);
float **add(t_matrix *right, t_matrix *left);
float **sub(t_matrix *right, t_matrix *left);
float **element_multi_op(t_matrix* right, t_matrix* left);
float **element_scalar_div_op(t_matrix* mat, float scalar);
float **element_scalar_multi_op(t_matrix* mat, float scalar);
float **element_add_scalar_op(t_matrix *mat, float scalar);
float **element_sub_scalar_op(t_matrix *mat, float scalar);
float **sigmoid_op(t_matrix *mat);
float **tanh_op(t_matrix *mat);
float **relu_op(t_matrix *mat);
float **leaky_relu_op(t_matrix *mat, float alpha);

// File parsing
t_matrix **fill_matrix(char* file);

#endif