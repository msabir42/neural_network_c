#include "neural.h"

t_matrix **fill_matrix(char* file)
{
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return NULL;

    char buffer[4];
    int magic_number = 0;
    int count = 0;
    int rows = 0;
    int columns = 0;

    read(fd, buffer, 4);
    magic_number = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    printf("Magic number: %d\n", magic_number);

    read(fd, buffer, 4);
    count = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    printf("Number of images: %d\n", count);

    read(fd, buffer, 4);
    rows = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];

    read(fd, buffer, 4);
    columns = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];

    if (rows != 28 || columns != 28)
    {
        close(fd);
        return NULL; 
    }


    t_matrix **chain = malloc(sizeof(t_matrix*) * count);
    if (!chain)
    {
        close(fd);
        return NULL;
    }

    unsigned char image_buffer[28*28]; 
    for (int track = 0; track < count; track++)
    {
        chain[track] = create_matrix(rows, columns);
        if (!chain[track])
        {
            break;
        }

       
        read(fd, image_buffer, 28*28);

  
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                chain[track]->content[i][j] = image_buffer[i*columns + j] / 255.f;
            }
        }
    }

    close(fd);
    return chain;
}
