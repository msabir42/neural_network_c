#include "neural.h"

t_matrix **fill_matrix(char *file)
{
    int fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return NULL;
    }

    unsigned char header[16];
    if (read(fd, header, 16) != 16)
    {
        printf("Error: cannot read header\n");
        close(fd);
        return NULL;
    }

    int magic = (header[0] << 24) | (header[1] << 16) | (header[2] << 8) | header[3];
    int num_images = (header[4] << 24) | (header[5] << 16) | (header[6] << 8) | header[7];
    int rows = (header[8] << 24) | (header[9] << 16) | (header[10] << 8) | header[11];
    int cols = (header[12] << 24) | (header[13] << 16) | (header[14] << 8) | header[15];

    printf("Magic: %d\n", magic);
    printf("Images: %d\n", num_images);
    printf("Rows: %d  Cols: %d\n", rows, cols);

    int img_size = rows * cols;
    unsigned char *buffer = malloc(img_size);
    if (!buffer)
    {
        printf("malloc failed\n");
        close(fd);
        return NULL;
    }

    t_matrix **images = malloc(sizeof(t_matrix*) * num_images);
    if (!images)
    {
        printf("malloc failed\n");
        free(buffer);
        close(fd);
        return NULL;
    }

    for (int i = 0; i < num_images; i++)
    {
        int bytes = read(fd, buffer, img_size);
        if (bytes != img_size)
        {
            printf("Warning: file ended early at image %d\n", i);
            images[i] = NULL;
            break;
        }

        images[i] = create_matrix(rows, cols);
        if (!images[i])
        {
            printf("matrix malloc failed at %d\n", i);
            break;
        }

        int idx = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                images[i]->content[r][c] = buffer[idx++] / 255.0f;
            }
        }
    }

    free(buffer);
    close(fd);
    return images;
}
