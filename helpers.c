#include "neural.h"

float* flatten(t_matrix* mat)
{
    int size = mat->row * mat->col;
    int count = 0;
    float* image = malloc(sizeof(float) * size );
     int  i = 0;
    while (i < mat->row)
    {
        int j = 0;
        while(j < mat->col)
        {
            image[count++] = mat->content[i][j];
            j++;
        }
        i++;
    }
    return image;
}