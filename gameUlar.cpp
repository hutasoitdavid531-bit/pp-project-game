#include <ncurses.h>  
#include <unistd.h>    
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int LEBAR = 40;
const int TINGGI = 20;

void tampilkanLoading() {
    clear();
    attron(COLOR_PAIR(2));
    mvprintw(8, 12, "Memuat Game Snake...");
    mvprintw(9, 10, "[                    ]");
    attroff(COLOR_PAIR(2));
    refresh();

    for (int i = 1; i <= 20; i++) {
        attron(COLOR_PAIR(1));
        mvprintw(9, 10 + i, "=");
        attroff(COLOR_PAIR(1));
        refresh();
        usleep(50000);
    }
    usleep(300000);
}