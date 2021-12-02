#include "bouncing_text.h"

#define HEIGHT 20
#define WIDTH 8
#define FPS 30

void clear(void) {
	printf("\e[1;1H\e[2J");
}

void show(int x, int y, char* text) {

	for(int j = 0; j <= HEIGHT; ++j) {
		printf("\n");
		for(int i = 0; i <= WIDTH; ++i) {
			if(i == x && j == y) printf("%s", text);
			else printf(" ");
		}
	}
	printf("\n");
}

void bouncingText(char* text) {
	Point p;
	int t = 0;
	p.x = 5;
	p.y = 4;
	double a = .001;
	double v = 0;
	bool reversed = true;
	while(1) {
		if(p.y >= HEIGHT) {
			reversed = reversed? false: true;
			p.y = HEIGHT;
		}
		if(p.y < 4) {
			p.y = 4;
			reversed = reversed? false: true;
			t = 0;
		}
		usleep(1000000 / FPS);
		clear();
		show(p.x, p.y, text);
		if(reversed) {
			p.y += (1/2.0) * a * t * t;
			t++;
		} else {
			p.y -= (1/2.0) * a * t * t;
			t--;
		}
	}
}
