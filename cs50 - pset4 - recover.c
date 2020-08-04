#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    // open the memory card file
    FILE* file = fopen(argv[1], "r");
    // if file does not exist throw an error
    if (file == NULL)
    {
        printf("Could not open the file\n");
        return 2;
    }

    // create memory buffer to read data from card into
    unsigned char buffer[512];
    // file name counter
    int filecount = 0;
    // check if we foung a jpeg yet or not
    bool jpgfound = false;
    // create outfile for picture
    FILE* img = NULL;

    // read data from the card file into a buffer until there arent any blocks left
    while(fread(buffer, 512, 1, file) == 1)
    {
        // check first 4 bytes of buffer for a jpeg signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpgfound == true)
            {
                // weve already found the start of a new picture
                fclose(img);
            }

            else
            {
                // jpg found so we start to write
                jpgfound = true;
            }

            // create array for new file name
            char filename[8];
            // create the actual name of new file starting with 000.jpg
            sprintf(filename, "%03i.jpg", filecount);
            // open new file to write to
            img = fopen(filename, "w");
            // increment file name counter
            filecount++;
        }

        if (jpgfound == true)
        {
            // write data to a new file
            fwrite(&buffer, 512, 1, img);
        }
    }
    // when reach the end of memory card file close any remaining files
    fclose(file);
    fclose(img);

    return 0;
}
