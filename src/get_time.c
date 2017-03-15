//
// Created by tom billard on 15/03/2017.
//

float get_time(char *buf)
{
    char *tmp = strstr(buf, "time") + 5;
    if (tmp)
        return (float)(atof(tmp));
    return (0);
}

