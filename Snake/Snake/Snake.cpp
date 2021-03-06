#include <stdio.h>

#include <allegro5/allegro.h>
#include "Snake_el.h"

bool right = false, up = false, down = false, left = false;
const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 600;
const int snake_el_SIZE = 15;
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

// jestem banankiem

int main(int argc, char **argv)
{
	double speed = 2.0;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *snake_el = NULL;
	ALLEGRO_BITMAP *waz = NULL;
	float snake_el_x = SCREEN_W / 2.0 - snake_el_SIZE / 2.0;
	float snake_el_y = SCREEN_H / 2.0 - snake_el_SIZE / 2.0;
	bool key[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);	
	
	
	Snake_el nowy(15,snake_el,display);
	

	event_queue = al_create_event_queue();


	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			if (key[KEY_UP]){
				up = true;
				down = false;
				right = false;
				left = false;
			}
			if (key[KEY_DOWN]){
				down = true;
				right = false;
				left = false;
				up = false;
			}

			if (key[KEY_LEFT]){
				left = true;
				down = false;
				right = false;
				up = false;
			}

			if (key[KEY_RIGHT]){
				right = true;
				left = false;
				down = false;
				up = false;
			}
			if (left == true){
				snake_el_x -= speed;

			}
			if (right == true){
				snake_el_x += speed;

			}

			if (up == true){
				snake_el_y -= speed;

			}

			if (down == true){
				snake_el_y += speed;

			}





			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(240, 240, 240));
			
			
			nowy.create(snake_el, snake_el_x, snake_el_y);

			al_flip_display();
			

		}
	}

	al_destroy_bitmap(snake_el);

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}