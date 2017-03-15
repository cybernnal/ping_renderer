#include <ping.h>

static void init_texture_renderer(t_window *win, int w, int h)
{
    if (!(win->img_ptr = (Uint32 *)ft_memalloc(sizeof(Uint32) * w * h)))
        exit(EXIT_FAILURE);
    win->image = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
}

void        init_window(t_window *window)
{
    SDL_Init(SDL_INIT_VIDEO);
    if (!(window->window = SDL_CreateWindow("fdf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                            WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
        exit(EXIT_FAILURE);
    if (!(window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED)))
        exit(EXIT_FAILURE);
    SDL_SetRenderDrawColor(window->renderer, 0, 255, 0, 0);
    init_texture_renderer(window, WIDTH, HEIGHT);
}