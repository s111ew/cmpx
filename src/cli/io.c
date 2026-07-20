#include <stdio.h>
#include <sys/stat.h>

#include "io.h"

int get_file_stats(char *abs_path, FileStats *stats)
{
    stats->path = abs_path;

    struct stat file_info;
    if (stat(abs_path, &file_info) == -1) {
        return -1;
    }

    stats->size = file_info.st_size;
    
    return 0;
}