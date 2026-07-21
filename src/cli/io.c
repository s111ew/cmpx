#include <stdio.h>
#include <limits.h>
#include <sys/stat.h>

#include "io.h"

int file_stats(char *path, FileStats *stats)
{
    char abs_path[PATH_MAX];
    if (get_abs_path(path, abs_path) != 0)
    {
        return -1;
    }

    stats->path = abs_path;

    struct stat file_info;
    if (stat(abs_path, &file_info) == -1)
    {
        return -1;
    }

    stats->size = file_info.st_size;

    return 0;
}

int get_abs_path(char *rel_path, char *abs_path)
{
    if (realpath(rel_path, abs_path) == NULL)
    {
        return -1;
    }

    return 0;
}