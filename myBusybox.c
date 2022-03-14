#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *filename = basename(argv[0]);
    char command[1024];
    int j, i;
    if (!strcmp(filename, "ls"))
    {
        j = sprintf(command, "%s", filename);
        for (i = 1; i < argc; i++)
        {
            j += sprintf(command + j, " %s", argv[i]);
        }
        system(command);
    }
    else if (!strcmp(filename, "cat"))
    {

        j = sprintf(command, "%s", filename);
        for (i = 1; i < argc; i++)
        {
            j += sprintf(command + j, " %s", argv[i]);
        }
        system(command);
    }
    else if (!strcmp(filename, "cp"))
    {

        j = sprintf(command, "%s", filename);
        for (i = 1; i < argc; i++)
        {
            j += sprintf(command + j, " %s", argv[i]);
        }
        system(command);
    }
    else if (!strcmp(filename, "chown"))
    {

        j = sprintf(command, "%s", filename);
        for (i = 1; i < argc; i++)
        {
            j += sprintf(command + j, " %s", argv[i]);
        }
        system(command);
    }
    return 0;
}
