#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int i){
	srand(time(NULL)); // Инициализация генератора
	int min = 1;
    int max = 20;
	int x_appl = min + rand() % (max - min + 1);
	int y_appl = min + rand() % (max - min + 1);
    int y = 10, x = 10;
    initscr();
    mvaddstr(y,x,"@");//вывод на экран
    while(1){
	int klavish = getch();
	erase();// удаляет всё с экрана erase();

	if(klavish == 'w' ){ //шаг вверх с помощью 119
	    y--;
	}else if(klavish == 115){ // шаг вниз с помощью s
	    y++;
	}else if(klavish == 100){// шаг в право с помощью d
	    x++;
	}else if(klavish == 97){// шаг в влево с помощью a
	    x--;    
	}

	// Проверка, попал ли персонаж на яблоко
     if (y == y_appl && x == x_appl) {
            // Сгенерировать новые случайные координаты для яблока
        x_appl = min + rand() % (max - min + 1);
        y_appl = min + rand() % (max - min + 1);
	}
	
	mvaddstr(y_appl,x_appl,"0");//вывод на экран яблока
	mvaddstr(y,x,"@");
    }
    getch();   
    endwin();
    return 0;
}
