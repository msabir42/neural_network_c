#include "neural.h"


t_matrix *forward_propagation(t_layer *layer, t_matrix *input)
{
    t_matrix* weight = layer->weights;
    t_matrix* bias = layer->bias;
    t_matrix* output = layer->output;
    t_matrix* tmp = matrix_multiplication(weight,input);
    tmp = matrix_addition(tmp,bias);
    output = matrix_sigmoid(tmp);
    return output;
}
