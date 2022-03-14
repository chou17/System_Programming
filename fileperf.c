#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w+");

    char wordBuf[80];
    setvbuf(stdin, wordBuf, _IOFBF, 80);
    setvbuf(stdout, NULL, _IOFBF, 80);

    int bufLen = 0;
    int linePos = 0;

    while (1)
    {
        int inputInt = getc(input);
        if (inputInt == EOF)
            break;
        unsigned char inputChar = (unsigned char)inputInt;

        if (inputChar == '\n')
        {
            if (bufLen + linePos < 80)
            {
                fprintf(output, "%s\n", wordBuf);
            }
            else
            {
                fprintf(output, "\n%s\n", wordBuf);
            }
            bufLen = 0;
            linePos = 0;
        }

        if (inputChar == ' ')
        {
            bufLen++;
            if (linePos + bufLen > 80)
            {
                fprintf(output, "\n");
                bufLen--;
                linePos = 0;
            }
            fprintf(output, " ");
            fprintf(output, wordBuf, bufLen);
            bufLen = 0;
            linePos += bufLen;
            continue;
        }
        wordBuf[bufLen++] = inputChar;
    }
    fclose(input);
    fclose(output);
}
