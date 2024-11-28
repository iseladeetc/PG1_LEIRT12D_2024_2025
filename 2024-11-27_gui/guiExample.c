#include <pg/pglib.h>

#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 400

typedef struct 
{
    int x; 
    int y;
    int radius;
    RGB color;
} ball_t;


ball_t b1;

void ball_init (ball_t *b, int x, int y, int radius, RGB color) 
{
    b->x = x;
    b->y = y;
    b->radius = radius;
    b->color = color;
}

void ball_show (ball_t *b)
{
    graph_circle(b->x, b->y, b->radius, b->color, true);
}
void mouse_handler (MouseEvent me)
{
    if (me.type == MOUSE_BUTTON_EVENT && me.button == BUTTON_LEFT &&
        me.state == BUTTON_PRESSED) {
            graph_circle(me.x, me.y, 10, c_red, true);
    }
    printf("(%d, %d)\n", me.x, me.y);
}

void timer_handler()
{
    printf("Timer!\n");

    b1.y += b1.radius/2;
    ball_show(&b1);
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
    
    ball_init(&b1, 10, 20, 20, c_blue);

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

    graph_regist_mouse_handler(mouse_handler);
    graph_regist_timer_handler(timer_handler, 500);
    graph_regist_key_handler(keyboard_handler);

    // start the event loop 
    graph_start();
	printf("That's all folk's!\n");
    return 0;
}
