#include "neural.h"



void init_layer(t_layer* layer,int input_size,int output_size)
{
    layer->input_size = input_size;
    layer->output_size = output_size;
    layer->weights = create_matrix(output_size,input_size);
    layer->bias = create_matrix(output_size,1);
    layer->output = create_matrix(output_size,1);
    int i = 0;
    int j;
    while (i < output_size)
    {
        j = 0;
        while (j < input_size)
        {
            layer->weights->content[i][j] = ((float)rand() / RAND_MAX) * 0.01;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < output_size)
    {
        j = 0;
        while (j < input_size)
        {
            layer->bias->content[i][j] = 0;
            j++;
        }
        i++;
    }
}