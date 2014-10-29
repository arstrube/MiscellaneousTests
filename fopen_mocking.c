#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

static int mock_file_contents = 0xdeadbeef;

static FILE *mock_fopen(const char *path, const char *mode)
{
    return strcmp(path, "/dev/urandom") == 0
        ? fmemopen(&mock_file_contents, sizeof mock_file_contents, mode)
        : NULL;
}

static int use_mock_fopen = 0;

FILE *fopen(const char *path, const char *mode)
{
    FILE *(*real_fopen)(const char *path, const char *mode);
    *(void **) (&real_fopen) = dlsym(RTLD_NEXT, "fopen");
    return use_mock_fopen ? mock_fopen(path, mode) : real_fopen(path, mode);
}

static void read_random_value()
{
    FILE * f = fopen("/dev/urandom", "r");
    int value;
    fread(&value, sizeof value, 1, f);
    printf("Read value 0x%x.\n", value);
    fclose(f);
}

int main(void)
{
    read_random_value();
    use_mock_fopen = 1;
    read_random_value();
    return 0;
}
