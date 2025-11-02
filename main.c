#include "neural.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <mnist-images-file>\n", argv[0]);
        return 1;
    }

    char *file = argv[1];

    int fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    unsigned char header[16];
    if (read(fd, header, 16) != 16)
    {
        printf("Error reading header\n");
        close(fd);
        return 1;
    }

    int magic = (header[0] << 24) | (header[1] << 16) |
                (header[2] << 8) | header[3];
    int num_images = (header[4] << 24) | (header[5] << 16) |
                     (header[6] << 8) | header[7];
    int rows = (header[8] << 24) | (header[9] << 16) |
               (header[10] << 8) | header[11];
    int cols = (header[12] << 24) | (header[13] << 16) |
               (header[14] << 8) | header[15];

    printf("Magic: %d\n", magic);
    printf("Images: %d\n", num_images);
    printf("Rows: %d  Cols: %d\n", rows, cols);

    // Initialize layers
    t_layer hidden, output;
    init_layer(&hidden, 784, 128);
    init_layer(&output, 128, 10);

    // Matrix for image input
    t_matrix *input_matrix = create_matrix(784, 1);

    // Read 10 images
    for (int i = 0; i < 10; i++)
    {
        t_matrix *image = read_one_image(fd, rows, cols);
        if (!image)
        {
            printf("Reached end of file at image %d\n", i);
            break;
        }

        float *flat = flatten(image);

        // Copy flattened data into input vector
        for (int p = 0; p < 784; p++)
            input_matrix->content[p][0] = flat[p];

        t_matrix *hidden_out = forward_propagation(&hidden, input_matrix);
        t_matrix *output_out = forward_propagation_last(&output, hidden_out);

        // Print NN outputs
        for (int k = 0; k < 10; k++)
            printf("%f ", output_out->content[k][0]);
        printf("\n");

        // Find predicted digit
        int best = 0;
        float best_val = output_out->content[0][0];
        for (int k = 1; k < 10; k++)
        {
            if (output_out->content[k][0] > best_val)
            {
                best_val = output_out->content[k][0];
                best = k;
            }
        }

        printf("Image %d predicted: %d\n", i, best);

        free(flat);
        free_matrix(image);
    }

    close(fd);
    return 0;
}
