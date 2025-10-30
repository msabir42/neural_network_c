#include "neural.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <t10k-images.idx3-ubyte>\n", argv[0]);
        return 1;
    }

    char *file = argv[1];

    // 1. Load MNIST images
    t_matrix **images = fill_matrix(file);
    if (!images)
    {
        printf("Error loading MNIST file.\n");
        return 1;
    }

    int total_data = 10000; // t10k = 10k images

    // 2. Create layers
    t_layer hidden;
    t_layer output;
    init_layer(&hidden, 784, 128);
    init_layer(&output, 128, 10);

    // 3. Flatten all images (allocate on heap)
    float **flatted = malloc(sizeof(float*) * total_data);
    if (!flatted)
    {
        printf("Malloc error\n");
        return 1;
    }

    for (int i = 0; i < total_data; i++)
    {
        if (images[i] != NULL)
            flatted[i] = flatten(images[i]);
        else
            flatted[i] = NULL;
    }

    // 4. Create a reusable input matrix
    t_matrix *input_matrix = create_matrix(784, 1);

    //int correct_count = 0; // optional, for accuracy if labels available

    // 5. Process all images
    for (int img_idx = 0; img_idx < total_data; img_idx++)
    {
        if (!flatted[img_idx])
            continue;

        // Copy flattened image into input matrix
        for (int j = 0; j < 784; j++)
            input_matrix->content[j][0] = flatted[img_idx][j];

        // Forward propagation
        t_matrix *hidden_out  = forward_propagation(&hidden, input_matrix);
        t_matrix *output_out = forward_propagation(&output, hidden_out);

        // Determine predicted digit (argmax)
        int predicted = 0;
        float max_val = output_out->content[0][0];
        for (int k = 1; k < 10; k++)
        {
            if (output_out->content[k][0] > max_val)
            {
                max_val = output_out->content[k][0];
                predicted = k;
            }
        }

        // Print first 5 predictions as example
        if (img_idx < 100)
            printf("Image %d predicted: %d\n", img_idx, predicted);

        // Free temporary matrices
        free_matrix(hidden_out);
        free_matrix(output_out);
    }

    // 6. Cleanup
    free_matrix(input_matrix);

    for (int i = 0; i < total_data; i++)
    {
        if (images[i])
            free_matrix(images[i]);
        if (flatted[i])
            free(flatted[i]);
    }
    free(images);
    free(flatted);

    return 0;
}
