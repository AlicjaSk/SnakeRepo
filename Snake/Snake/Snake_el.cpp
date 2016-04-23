#include <allegro5/allegro.h>
#include "Snake_el.h"



Snake_el::Snake_el( int size, ALLEGRO_BITMAP *&name, ALLEGRO_DISPLAY*&display)
{
	name = al_create_bitmap(size, size);

	//Snake_el nowy(100, 200, 20, waz);
	al_set_target_bitmap(name);

	al_clear_to_color(al_map_rgb(55, 55, 55));
	al_set_target_bitmap(al_get_backbuffer(display));
}
void Snake_el::create(ALLEGRO_BITMAP *name,int x,int y){

	al_draw_bitmap(name, x, y, 0);

}

Snake_el::~Snake_el()
{
}
