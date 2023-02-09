#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int num = atoi(argv[1]);
    char * str = argv[2];
    printf("CC: called by Python, get input: %d, \"%s\"\n", num, str);
    char  cmd[1024];
    char result[1024];
    const char * python_path = "/mnt/cache/share_data/wangguoteng.p/uniscale-py39/envs/hetu/bin/python";
    const char * script_path = "/mnt/cache/wangguoteng.p/demo/stdio/main.py";
    sprintf(cmd, "%s %s %d %s", python_path, script_path, num, "CC-1");
    FILE * fp = popen((const char *)cmd, "r");
    if (fp == NULL) {
        printf("CC: Failed to run command\n");
        exit(1);
    }

    while (fgets(result, sizeof(result), fp) != 0)
        printf("CC: get %s", result);
	pclose(fp);
    return 0;
}