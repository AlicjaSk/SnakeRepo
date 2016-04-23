#pragma once
#include <allegro5/allegro.h>

class Snake_el
{
	int x, y, size;
	ALLEGRO_BITMAP *name;

public:
	Snake_el( int size, ALLEGRO_BITMAP *&name, ALLEGRO_DISPLAY*&display);
	void Snake_el::create(ALLEGRO_BITMAP *name, int x, int y);
	~Snake_el();
};

