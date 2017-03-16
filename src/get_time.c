//
// Created by tom billard on 15/03/2017.
//

#include <ping.h>
#include <memory.h>
#include <stdlib.h>

float get_time(char *buf)
{
    char *tmp = strstr(buf, "time") + 5;
    if (!strncmp(buf, "Request", 7))
    {
       // printf(buf);
        return (-1);
    }
    if (tmp)
        return (float)(atof(tmp));
    return (0);
}

