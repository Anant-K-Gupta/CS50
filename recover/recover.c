#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check user input
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 1;
    }

    FILE *img = NULL;
    BYTE buffer[512];
    int count = 0;
    int found = 0;
    char name[8];

    while (fread(buffer, 512, 1, file) == 1)
    {
        //check header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (found == 1)
            {
                fclose(img);
            }
            else
            {
                found = 1;
            }
            char filename[8];
            sprintf(name, "%03d.jpg", count);
            img = fopen(name, "a");
            count++;
        }
        if (found == 1)
        {
            // continue writing to image
            fwrite(&buffer, 512, 1, img);
        }
    }
    //free up memory
    fclose(file);
    fclose(img);
}
