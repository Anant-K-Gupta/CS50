#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            RGBTRIPLE temp = image[i][j];
            int avg = round((temp.rgbtRed + temp.rgbtGreen + temp.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
//calculating sepia values

            int sred = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sgreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sblue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            image[i][j].rgbtRed = (sred > 255) ? (255) : sred;
            image[i][j].rgbtGreen = (sgreen > 255) ? (255) : sgreen;
            image[i][j].rgbtBlue = (sblue > 255) ? (255) : sblue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0 ; i < height; i++)
    {
        if (width % 2 == 0)
        {
//swapping columns
            for (int j = 0; j < width / 2; j++)
            {
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
        else
        {
//swapping all except middle column
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            int count = 0;
            int xs[] = {i - 1, i, i + 1};
            int ys[] = {j - 1, j, j + 1};
            float finalR = 0, finalB = 0, finalG = 0;

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int currx = xs[x];
                    int curry = ys[y];

                    if (currx >= 0 && currx < height && curry >= 0 && curry < width)
                    {
                        RGBTRIPLE pixel = image[currx][curry];
//calculating values
                        finalR += pixel.rgbtRed;
                        finalB += pixel.rgbtBlue;
                        finalG += pixel.rgbtGreen;
                        count ++;
                    }
                }
            }
//updating values
            temp[i][j].rgbtRed = round(finalR / count);
            temp[i][j].rgbtBlue = round(finalB / count);
            temp[i][j].rgbtGreen = round(finalG / count);
        }
//copying temp to image
    }
    for (int i = 0 ; i < height; i++)
    {
        for (int j = 0 ; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }



    return;
}
