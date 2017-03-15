#include <ping.h>

int main(void) {
    char *cmd = "echo 'qwerasdf' | sudo -S ping -i 0.01 8.8.8.8";
    int i = 42;
    char buf[BUFSIZE];
    FILE *fp;

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