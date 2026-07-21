typedef struct
{
    const char *path;
    long long size;
} FileStats;

int file_stats(char *path, FileStats *stats);

int get_abs_path(char *rel_path, char *abs_path);