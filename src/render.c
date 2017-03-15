#include <stdio.h>

#include <ping.h>

static void key_handler(SDL_Event event, t_window *w) {

    if (event.type == SDL_KEYDOWN) {

        if (event.key.keysym.sym == SDLK_ESCAPE) {
            exit(EXIT_SUCCESS);
        }
        if (event.key.keysym.sym == SDLK_c)
            w->col = !w->col;
        if (event.key.keysym.sym == SDLK_v)
            w->p = !w->p;
    }
}

static void draw_pixel(int x, int y, Uint32 color, t_window *w)
{
    if (y > HEIGHT || x > WIDTH || x < 0 || y < 0)
    {
//        printf("x: %d, y: %d, pixel over/under flow", x, y);
        return ;
    }
    w->img_ptr[WIDTH * y + x] = color;
}

static void line(int x0, int y0, int x1, int y1, t_window *w, Uint32 color)
{

    int dx;
    int sx;
    int dy;
    int sy;
    int err;
    int e2;

    dx = abs(x1-x0);
    sx = x0 < x1 ? 1 : -1;
    dy = abs(y1-y0);
    sy = y0 <y1 ? 1 : -1;
    err = (dx > dy ? dx : -dy) / 2;
    while (1)
    {
        draw_pixel(x0, y0, color, w);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}



static void		draw_pix(t_window *w, int off, int x, int y, Uint32 color)
{
    float x1 = -(off / 2);
    float y1 = -(off / 2);

    while (y1 < off  / 2 + 1)
    {
        while (x1 < off / 2 + 1)
        {
            draw_pixel((int)(x + x1), (int)(y + y1), color, w);
            x1++;
        }
        x1 = -(off/2);
        y1++;
    }
}


static void draw(t_window *w, t_list *lst, float max) {
    int i = 0;

    while (lst->next) {
        if (w->p) {
            if (w->col)
                line((int) ((((WIDTH - 100) / MAX) * i) + 50), HEIGHT - (int) L_CF(lst->t, 0, max, 50, HEIGHT - 50),
                     (int) ((((WIDTH - 100) / MAX) * (i + 1)) + 50),
                     HEIGHT - (int) L_CF(lst->next->t, 0, max, 50, HEIGHT - 50), w, GREEN);
            else
                line((int) ((((WIDTH - 100) / MAX) * i) + 50), HEIGHT - (int) L_CF(lst->t, 0, max, 50, HEIGHT - 50),
                     (int) ((((WIDTH - 100) / MAX) * (i + 1)) + 50),
                     HEIGHT - (int) L_CF(lst->next->t, 0, max, 50, HEIGHT - 50), w,
                     (Uint32) L_C(lst->t, 0, max, 0x0000ff, 0xffffff));

        } else {
            if (w->col)
                draw_pix(w, 4, (int) ((((WIDTH - 100) / MAX) * i) + 50),
                         HEIGHT - (int) L_CF(lst->t, 0, max, 50, HEIGHT - 50),
                         GREEN);//(Uint32)L_C(lst->t, 0, max, 0x0000ff, 0xffffff));
            else
                draw_pix(w, 2, (int) ((((WIDTH - 100) / MAX) * i) + 50),
                         HEIGHT - (int) L_CF(lst->t, 0, max, 50, HEIGHT - 50),
                         (Uint32) L_C(lst->t, 0, max, 0x0000ff, 0xffffff));
        }
        lst = lst->next;
        ++i;
    }
}

static void render_graph(t_window *w, float t)
{
    static  t_list *lst;
    static t_list *first;
    float max;
   max =  process_list(&lst, &first, t);
//    print_lst(first);
    draw(w, first, max);
}

int        render(float t)
{
    static t_window w;
    if (!w.is_init)
    {
        init_window(&w);
        w.is_init = 1;
    }
    bzero(w.img_ptr, sizeof(Uint32) * HEIGHT * WIDTH);
    render_graph(&w, t);
    while (SDL_PollEvent(&w.event))
        key_handler(w.event, &w);
    SDL_UpdateTexture(w.image, NULL, w.img_ptr, WIDTH * sizeof(Uint32));
    SDL_RenderCopy(w.renderer, w.image, NULL, NULL);
    SDL_RenderPresent(w.renderer);
    return (1);
}

