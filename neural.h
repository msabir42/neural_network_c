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

t_matrix *create_matrix(int r, int c);
float fallocate_col(float **arr, int row, int col);
void free_matrix(t_matrix *mat);


#endif