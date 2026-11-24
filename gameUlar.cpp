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
void pratinjauArena() {
    clear();
    mvprintw(1, 4, "Pratinjau Arena (Tahap 1) - Tekan tombol apa saja untuk kembali");
    refresh();

    WINDOW *arena = newwin(TINGGI, LEBAR, 3, 4);
    box(arena, 0, 0);
    mvwprintw(arena, TINGGI / 2, (LEBAR / 2) - 6, "ARENA SNAKE");
    wrefresh(arena);

    getch();
    delwin(arena);
}

int tampilkanMenu() {
    const char *opsi[] = {"Mulai Game (Pratinjau)", "Keluar"};
    int jumlahOpsi = 2;
    int pilihanTerpilih = 0;

    WINDOW *menuWin = newwin(9, 32, 5, 10);
    keypad(menuWin, TRUE);

    do {
        werase(menuWin);
        box(menuWin, 0, 0);
        mvwprintw(menuWin, 1, 8, "=== SNAKE GAME ===");

        for (int i = 0; i < jumlahOpsi; i++) {
            if (i == pilihanTerpilih) {
                wattron(menuWin, A_REVERSE);
            }
            mvwprintw(menuWin, 3 + i, 4, "%s", opsi[i]);
            wattroff(menuWin, A_REVERSE);
        }
        mvwprintw(menuWin, 7, 3, "Gunakan Panah & Enter");
        wrefresh(menuWin);

        int tombol = wgetch(menuWin);
        switch (tombol) {
            case KEY_UP:
                pilihanTerpilih = (pilihanTerpilih == 0) ? jumlahOpsi - 1 : pilihanTerpilih - 1;
                break;
            case KEY_DOWN:
                pilihanTerpilih = (pilihanTerpilih == jumlahOpsi - 1) ? 0 : pilihanTerpilih + 1;
                break;
            case 10:
                delwin(menuWin);
                return pilihanTerpilih;
        }
    } while (true);
}
int main() {
    srand(time(0));
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);

    tampilkanLoading();

    while (true) {
        clear();
        refresh();
        int pilihan = tampilkanMenu();

        if (pilihan == 0) {
            pratinjauArena();
        } else {
            break;
        }
    }

    endwin();
    return 0;
}
