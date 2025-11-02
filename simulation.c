#include "neural.h"


t_matrix *forward_propagation(t_layer *layer, t_matrix *input)
{
    t_matrix* z = matrix_multiplication(layer->weights, input);
    t_matrix* z_bias = matrix_addition(z, layer->bias);
    t_matrix* out = matrix_sigmoid(z_bias);  // hidden layers use sigmoid
    return out;
}

t_matrix *forward_propagation_last(t_layer *layer, t_matrix *input)
{
    t_matrix* z = matrix_multiplication(layer->weights, input);
    t_matrix* z_bias = matrix_addition(z, layer->bias);
    t_matrix* out = matrix_softmax(z_bias);  // output layer uses softmax
    return out;
}