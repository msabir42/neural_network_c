#include "neural.h"

float* flatten(t_matrix* mat)
{
    if (!mat)
        return NULL;

    int size = mat->row * mat->col;
    float *image = malloc(sizeof(float) * size);
    if (!image)
        return NULL;

    int index = 0;
    for (int i = 0; i < mat->row; i++)
    {
        for (int j = 0; j < mat->col; j++)
        {
            image[index++] = mat->content[i][j];
        }
    }
    return image;
}