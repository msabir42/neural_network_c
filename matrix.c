#include "neural.h"

t_matrix *create_matrix(int r, int c)
{
    t_matrix *new;
    new = malloc(sizeof(t_matrix));
    if (!new)
        return NULL;
    new->row = r;
    new->col = c;
    new->content = malloc(sizeof(float *) * r);
    if (!new->content)
    {
        free(new);
        return NULL;
    }
    if ( fill_array(new->content, r, c) == -1)
    {
        free(new->content);
        free(new);
        return NULL;
    }
    return new;
}
float fill_array(float **arr, int row, int col)
{
    int i = 0;

    for (i = 0; i < row; i++)
    {
        arr[i] = malloc(sizeof(float) * col);
        if (!arr[i])
        {
            int j = 0;
            for (j; j < i; j++)
                free(arr[j]);
            return -1;
        }
    }
    return 1;
}

void free_matrix(t_matrix *mat) 
{
    int i;
    i = 0;
    for (i; i < mat->row; i++)
    {
        free(mat->content[i]);
    }
    free(mat->content);
    free(mat);
    return;
}