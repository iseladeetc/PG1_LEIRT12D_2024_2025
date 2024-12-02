#include <pg/pglib.h>

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 400

typedef struct 
{
    int x; 
    int y;
    int radius;
    int dx;
    int dy;
    RGB color;
} ball_t;


#define MAX_BALLS 32
// ball_t b1;
// ball_t b2;
// ball_t b3;
ball_t balls[MAX_BALLS];
int n_balls;

void ball_init (ball_t *b, int x, int y, int radius, int dx, int dy, RGB color) 
{
    b->x = x;
    b->y = y;
    b->dx = dx;
    b->dy = dy;
    b->radius = radius;
    b->color = color;
}

void ball_show (ball_t *b)
{
    graph_circle(b->x, b->y, b->radius, b->color, true);
}

void ball_clear (ball_t *b)
{
    graph_circle(b->x, b->y, b->radius, c_white, true);
}

void ball_move (ball_t *b)
{
    b->y += b->dy;
    // testar limite infoerior da janela
    if (b->y + b->radius >= WINDOW_HEIGHT) {
        b->dy = -b->dy;
        b->y = WINDOW_HEIGHT - 1 - b->radius;
    }
    else if (b->y - b->radius <= 0) {
        b->dy = -b->dy;
        b->y = b->radius;
    }

    b->x += b->dx;
    if (b->x + b->radius >= WINDOW_WIDTH) {
        b->dx = -b->dx;
        b->x = WINDOW_WIDTH - 1 - b->radius;
    }
    else if (b->x - b->radius <= 0) {
        b->dx = -b->dx;
        b->x = b->radius;
    }
}



void mouse_handler (MouseEvent me)
{
    if (me.type == MOUSE_BUTTON_EVENT && me.button == BUTTON_LEFT &&
        me.state == BUTTON_PRESSED) {
            graph_circle(me.x, me.y, 10, c_red, true);
    }
    printf("(%d, %d)\n", me.x, me.y);
}

void screen_clear()
{
    graph_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, c_gray, true);
}

void draw_board()
{
    screen_clear();
    graph_circle(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, 40, c_green, true);
    
    int width_rect = 100;
    int height_rect = 50;
    int x = WINDOW_WIDTH/2 - width_rect/2;
    int y = WINDOW_HEIGHT/2 - height_rect/2;
    graph_rect(x, y, width_rect, height_rect, c_blue, true);

    char LEIRT13[] = "LEIRT13D";
    Size sz = graph_text_size(LEIRT13, MEDIUM_FONT);
    int free_x = width_rect - sz.width;
    //int free_y = height_rect - sz.height;
    int txt_x = x + free_x/2;
    int txt_y = y + height_rect/2 + sz.height/2;
    graph_text2(txt_x, txt_y, c_black, c_green, LEIRT13, MEDIUM_FONT);

    for (int i = 0; i < n_balls; i++) {
        ball_show(&balls[i]);
    }
}

void timer_handler()
{
    printf("Timer!\n");

    for (int i = 0; i < n_balls; i++) {
        ball_move(&balls[i]);
    }

    draw_board();
}

void keyboard_handler (KeyEvent ke)
{
    if (ke.keysym == 's') graph_exit();
    printf("tecla %c\n", ke.keysym);

}

int main() {
     // initializes the graphics, specifying dimensions and a     
    // title for the graphic window. Must be called first
    graph_init2("Hello World", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    n_balls = 0;
    ball_init(&balls[n_balls++], 30, 25, 20, 0, 10, c_blue);
    ball_init(&balls[n_balls++], 30, 40, 20, 10, 0, c_red);
    ball_init(&balls[n_balls++], 30, 40, 20, 10, 10, c_orange);

    ball_init(&balls[n_balls++], 60, 40, 20, -20, 20, c_cyan);



    graph_regist_mouse_handler(mouse_handler);
    graph_regist_timer_handler(timer_handler, 60);
    graph_regist_key_handler(keyboard_handler);

    // start the event loop 
    graph_start();
	printf("That's all folk's!\n");
    return 0;
}
