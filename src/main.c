#include <ping.h>

int main(int argc, char **argv)
{
    char *cmd;
    int i = 42;
    char buf[BUFSIZE];
    FILE *fp;

    if (argc == 1)
        cmd = strdup("ping -i 0.1 8.8.8.8");
    else
    {
        cmd = (char*)ft_memalloc(sizeof(char) * (strlen(argv[1]) + 41));
        bzero(cmd, strlen(argv[1]) + 41);
      //  cmd =  strdup("echo 'qwerasdf'");
        sprintf(cmd, "echo '%s' | sudo -S ping -i 0.001 8.8.8.8", argv[1]);
        printf(cmd);
    }
    if ((fp = popen(cmd, "r")) == NULL) {
        printf("Error opening pipe!\n");
        return -1;
    }
    while (fgets(buf, BUFSIZE, fp) != NULL)
    {
        if (i == 0)
            render(get_time(buf));
        i = 0;
    }
    if(pclose(fp))  {
        printf("Command not found or exited with error status\n");
        return -1;
    }
    return 0;
}