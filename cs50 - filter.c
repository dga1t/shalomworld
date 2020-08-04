#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j =0; j < width; j++)
        {
            float avrg = (round(image[i][j].rgbtRed) + round(image[i][j].rgbtGreen) + round(image[i][j].rgbtBlue)) / 3;

            int ravrg = round(avrg);

            image[i][j].rgbtRed = ravrg;
            image[i][j].rgbtGreen = ravrg;
            image[i][j].rgbtBlue = ravrg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int spRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int spGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int spBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            if (spRed > 255)
            {
                spRed = 255;
            }
            if (spGreen > 255)
            {
                spGreen = 255;
            }
            if (spBlue > 255)
            {
                spBlue = 255;
            }

            image[i][j].rgbtRed = spRed;
            image[i][j].rgbtGreen = spGreen;
            image[i][j].rgbtBlue = spBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
// Working version
{
  int sumBlue;
  int sumGreen;
  int sumRed;
  float counter;
  //create a temporary table of colors to not alter the calculations
  RGBTRIPLE temp[height][width];

  for (int i = 0; i < width; i++)
  {
    for (int j = 0; j < height; j++)
    {
      sumBlue = 0;
      sumGreen = 0;
      sumRed = 0;
      counter = 0.00;

      // sums values of the pixel and 8 neighboring ones, skips iteration if it goes outside the pic
      for (int k = -1; k < 2; k++)
      {
        if (j + k < 0 || j + k > height - 1)
        {
            continue;
        }

        for (int h = -1; h < 2; h++)
        {
          if (i + h < 0 || i + h > width - 1)
          {
            continue;
          }

          sumBlue += image[j + k][i + h].rgbtBlue;
          sumGreen += image[j + k][i + h].rgbtGreen;
          sumRed += image[j + k][i + h].rgbtRed;
          counter++;
        }
      }

    // averages the sum to make picture look blurrier
    temp[j][i].rgbtBlue = round(sumBlue / counter);
    temp[j][i].rgbtGreen = round(sumGreen / counter);
    temp[j][i].rgbtRed = round(sumRed / counter);
    }
  }

  //copies values from temporary table
  for (int i = 0; i < width; i++)
  {
      for (int j = 0; j < height; j++)
      {
          image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
          image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
          image[j][i].rgbtRed = temp[j][i].rgbtRed;
      }
  }
}

// Compiles but doesnt pass the check 
/* void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE ogimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ogimage[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // top left corner case
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round((ogimage[i][j+1].rgbtRed + ogimage[i+1][j].rgbtRed + ogimage[i+1][j+1].rgbtRed + ogimage[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((ogimage[i][j+1].rgbtGreen + ogimage[i+1][j].rgbtGreen + ogimage[i+1][j+1].rgbtGreen + ogimage[i][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((ogimage[i][j+1].rgbtBlue + ogimage[i+1][j].rgbtBlue + ogimage[i+1][j+1].rgbtBlue + ogimage[i][j].rgbtBlue) / 4.0);
            }

            // top right corner case
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((ogimage[i][j-1].rgbtRed + ogimage[i+1][j-1].rgbtRed + ogimage[i+1][j].rgbtRed + ogimage[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((ogimage[i][j-1].rgbtGreen + ogimage[i+1][j-1].rgbtGreen + ogimage[i+1][j].rgbtGreen + ogimage[i][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((ogimage[i][j-1].rgbtBlue + ogimage[i+1][j-1].rgbtBlue + ogimage[i+1][j].rgbtBlue + ogimage[i][j].rgbtBlue) / 4.0);
            }

            // top edge case
            else if (i == 0)
            {
                image[i][j].rgbtRed = round((ogimage[i][j-1].rgbtRed + ogimage[i][j+1].rgbtRed + ogimage[i+1][j-1].rgbtRed + ogimage[i+1][j].rgbtRed + ogimage[i+1][j+1].rgbtRed + ogimage[i][j].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((ogimage[i][j-1].rgbtGreen + ogimage[i][j+1].rgbtGreen + ogimage[i+1][j-1].rgbtGreen + ogimage[i+1][j].rgbtGreen + ogimage[i+1][j+1].rgbtGreen + ogimage[i][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((ogimage[i][j-1].rgbtBlue + ogimage[i][j+1].rgbtBlue + ogimage[i+1][j-1].rgbtBlue + ogimage[i+1][j].rgbtBlue + ogimage[i+1][j+1].rgbtBlue + ogimage[i][j].rgbtBlue) / 6.0);
            }

            // bottom left corner case
            if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((ogimage[i-1][j].rgbtRed + ogimage[i-1][j+1].rgbtRed + ogimage[i][j+1].rgbtRed + ogimage[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((ogimage[i-1][j].rgbtGreen + ogimage[i-1][j+1].rgbtGreen + ogimage[i][j+1].rgbtGreen + ogimage[i][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((ogimage[i-1][j].rgbtBlue + ogimage[i-1][j+1].rgbtBlue + ogimage[i][j+1].rgbtBlue + ogimage[i][j].rgbtBlue) / 4.0);
            }

            // left edge case
            else if (j == 0)
            {
                image[i][j].rgbtRed = round((ogimage[i-1][j].rgbtRed + ogimage[i-1][j+1].rgbtRed + ogimage[i][j+1].rgbtRed + ogimage[i+1][j+1].rgbtRed + ogimage[i+1][j].rgbtRed + ogimage[i][j].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((ogimage[i-1][j].rgbtGreen + ogimage[i-1][j+1].rgbtGreen + ogimage[i][j+1].rgbtGreen + ogimage[i+1][j+1].rgbtGreen + ogimage[i+1][j].rgbtGreen + ogimage[i][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((ogimage[i-1][j].rgbtBlue + ogimage[i-1][j+1].rgbtBlue + ogimage[i][j+1].rgbtBlue + ogimage[i+1][j+1].rgbtBlue + ogimage[i+1][j].rgbtBlue + ogimage[i][j].rgbtBlue) / 6.0);
            }

            // bottom right corner case
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((ogimage[i-1][j-1].rgbtRed + ogimage[i-1][j].rgbtRed + ogimage[i][j-1].rgbtRed + ogimage[i][j].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((ogimage[i-1][j-1].rgbtGreen + ogimage[i-1][j].rgbtGreen + ogimage[i][j-1].rgbtGreen + ogimage[i][j].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((ogimage[i-1][j-1].rgbtBlue + ogimage[i-1][j].rgbtBlue + ogimage[i][j-1].rgbtBlue + ogimage[i][j].rgbtBlue) / 4.0);
            }

            // bottom edge case
            else if (i == height - 1)
            {
                image[i][j].rgbtRed = round((ogimage[i][j-1].rgbtRed + ogimage[i][j+1].rgbtRed + ogimage[i-1][j-1].rgbtRed + ogimage[i-1][j].rgbtRed + ogimage[i-1][j+1].rgbtRed + ogimage[i][j].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((ogimage[i][j-1].rgbtGreen + ogimage[i][j+1].rgbtGreen + ogimage[i-1][j-1].rgbtGreen + ogimage[i-1][j].rgbtGreen + ogimage[i-1][j+1].rgbtGreen + ogimage[i][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((ogimage[i][j-1].rgbtBlue + ogimage[i][j+1].rgbtBlue + ogimage[i-1][j-1].rgbtBlue + ogimage[i-1][j].rgbtBlue + ogimage[i-1][j+1].rgbtBlue + ogimage[i][j].rgbtBlue) / 6.0);
            }

            // right edge case
            else if (j == width - 1)
            {
                image[i][j].rgbtRed = round((ogimage[i-1][j].rgbtRed + ogimage[i-1][j-1].rgbtRed + ogimage[i][j-1].rgbtRed + ogimage[i+1][j-1].rgbtRed + ogimage[i+1][j].rgbtRed + ogimage[i][j].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((ogimage[i-1][j].rgbtGreen + ogimage[i-1][j-1].rgbtGreen + ogimage[i][j-1].rgbtGreen + ogimage[i+1][j-1].rgbtGreen + ogimage[i+1][j].rgbtGreen + ogimage[i][j].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((ogimage[i-1][j].rgbtBlue + ogimage[i-1][j-1].rgbtBlue + ogimage[i][j-1].rgbtBlue + ogimage[i+1][j-1].rgbtBlue + ogimage[i+1][j].rgbtBlue + ogimage[i][j].rgbtBlue) / 6.0);
            }

            // infield normal case
            else
            {
                image[i][j].rgbtRed = round((ogimage[i][j-1].rgbtRed + ogimage[i][j+1].rgbtRed + ogimage[i-1][j-1].rgbtRed + ogimage[i-1][j].rgbtRed + ogimage[i-1][j+1].rgbtRed + ogimage[i+1][j-1].rgbtRed + ogimage[i+1][j].rgbtRed + ogimage[i+1][j+1].rgbtRed + ogimage[i][j].rgbtRed) / 9.0);
                image[i][j].rgbtGreen = round((ogimage[i][j-1].rgbtGreen + ogimage[i][j+1].rgbtGreen + ogimage[i-1][j-1].rgbtGreen + ogimage[i-1][j].rgbtGreen + ogimage[i-1][j+1].rgbtGreen + ogimage[i+1][j-1].rgbtGreen + ogimage[i+1][j].rgbtGreen + ogimage[i+1][j+1].rgbtGreen + ogimage[i][j].rgbtGreen) / 9.0);
                image[i][j].rgbtBlue = round((ogimage[i][j-1].rgbtBlue + ogimage[i][j+1].rgbtBlue + ogimage[i-1][j-1].rgbtBlue + ogimage[i-1][j].rgbtBlue + ogimage[i-1][j+1].rgbtBlue + ogimage[i+1][j-1].rgbtBlue + ogimage[i+1][j].rgbtBlue + ogimage[i+1][j+1].rgbtBlue + ogimage[i][j].rgbtBlue) / 9.0);
            }
        }
    }
    return;
} */
