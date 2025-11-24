#include <nds.h>
#include <stdio.h>
#include "menu.h"

enum GameState {
	STATE_MAIN_MENU,
	STATE_NEW_GAME,
	STATE_LOAD_GAME,
	STATE_INGAME,
	STATE_PAUSED,
	STATE_SETTINGS,
	STATE_EXIT
};

PrintConsole consoleSub;

int main(int argc, char* argv[]) {
	powerOn(POWER_ALL_2D);

	videoSetMode(MODE_0_2D);
	videoSetModeSub(MODE_0_2D);

	vramSetBankC(VRAM_C_SUB_BG);

	consoleInit(
		&consoleSub,
		0,
		BgType_Text4bpp,
		BgSize_T_256x256,
		16,
		6,
		false,
		true
	);
	consoleSelect(&consoleSub);
	consoleSetWindow(&consoleSub, 5, 5, 32, 32);

	enum GameState state = STATE_MAIN_MENU;

	while (state != STATE_EXIT) {
		switch (state) {
			case STATE_MAIN_MENU: {
				int choice = mainMenu();

				if (choice == 0) {
					state = STATE_NEW_GAME;
				} else if (choice == 1) {
					state = STATE_LOAD_GAME;
				} else if (choice == 2) {
					state = STATE_SETTINGS;
				} else {
					state = STATE_EXIT;
				}
				break;
			}

			case STATE_NEW_GAME:
				// runGame();
				// for now just go back to menu
				state = STATE_MAIN_MENU;
				break;

			case STATE_LOAD_GAME:
				// runLoad();
				state = STATE_MAIN_MENU;
				break;

			case STATE_SETTINGS:
				// runSettings();
				state = STATE_MAIN_MENU;
				break;

			default:
				state = STATE_EXIT;
				break;
		}
	}

	return 0;
}
