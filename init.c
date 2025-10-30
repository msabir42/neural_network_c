#include "neural.h"



void init_layer(t_layer* layer, int input_size, int output_size)
{
    layer->input_size = input_size;
    layer->output_size = output_size;

    layer->weights = create_matrix(output_size, input_size);
    layer->bias = create_matrix(output_size, 1);
    layer->output = create_matrix(output_size, 1);

    // Initialize weights
    for (int i = 0; i < output_size; i++)
    {
        for (int j = 0; j < input_size; j++)
            layer->weights->content[i][j] = ((float)rand() / RAND_MAX) * 0.01;
    }

    // Initialize bias (one column only)
    for (int i = 0; i < output_size; i++)
        layer->bias->content[i][0] = 0;
}
