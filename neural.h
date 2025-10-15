#ifndef NEURAL_H
#define NEURAL_H

#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

typedef struct s_matrix
{
    int col;
    int row;
    float** content;

} t_matrix;

#endif