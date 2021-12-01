#include "bouncing_text.h"

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
	float a = .00001;
	float v = 0;
	bool reversed = true;
	while(1) {
		if(p.y > HEIGHT) {
			reversed = reversed? false: true;
			p.y = HEIGHT;
		}
		if(v < 0) {
			reversed = reversed? false: true;
			p.y = 4;
			v = 0;
		}
		usleep(1000000 / FPS);
		clear();
		show(p.x, p.y, text);
		if(reversed) {
			v += a * t;
			p.y += (v*v) / (2*a);
			t++;
		} else {
			v -= a * t;
			p.y -= (v*v) / (2*a);
			t--;
		}
	}
}
