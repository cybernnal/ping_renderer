//
// Created by tom billard on 15/03/2017.
//

#ifndef PING_PING_H
#define PING_PING_H


#define BUFSIZE 128
#define WIDTH 1800
#define HEIGHT 1100
#define MAX (float)1500

#define ORANGE  (Uint32) ((250 << 16) + (164 << 8) + 1)
#define MAGENTA (Uint32) ((255 << 16) + (0 << 8) + 255)
#define CYAN    (Uint32) ((0 << 16) + (255 << 8) + 255)
#define RED     (Uint32) ((255 << 16) + (0 << 8) + 0)
#define PURPUL  (Uint32) ((108 << 16) + (2 << 8) + 119)
#define GREEN   (Uint32) ((0 << 16) + (255 << 8) + 0)

# define L_C(X, x1, x2, y1, y2) ((int)(((X - x1) * (y2 - y1)) / (x2 - x1)) + y1)
# define L_CF(X, x1, x2, y1, y2) ((float)(((float)((X - x1) * (y2 - y1))) / (float)(x2 - x1)) + y1)

#include "SDL2/SDL.h"

typedef struct                  s_window
{
    SDL_Window              *window;
    SDL_Event               event;
    SDL_Renderer            *renderer;
    SDL_Texture             *image;
    Uint32                  *img_ptr;
    int                     is_init;
    int                     col;
    int                     p;
}                           t_window;

typedef struct      s_list
{
    float           t;
    struct s_list   *next;
}                   t_list;

void	*ft_memalloc(size_t size);
int        render(float t);
void        init_window(t_window *window);
float process_list(t_list **lst, t_list **first, float t);
void print_lst(t_list *lst);
float get_time(char *buf);
float get_max(t_list **l);

#endif //PING_PING_H
