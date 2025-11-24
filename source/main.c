#include <nds.h>
#include <fat.h>
#include <stdio.h>

#include "menu/main_menu.h"
#include "menu/save_menu.h"
#include "core/slot_system.h"

enum GameState {
	STATE_MAIN_MENU,
	STATE_PLAY_GAME,
	STATE_INGAME,
	STATE_PAUSED,
	STATE_SETTINGS,
	STATE_EXIT
};

PrintConsole consoleSub;

int currentActiveSlot = -1;

int main(int argc, char* argv[]) {
	powerOn(POWER_ALL_2D);

	if (!fatInitDefault()) {
		consoleDemoInit();
		iprintf("FAT Init Failed!\nPlease insert SD card.");
		while(1) swiWaitForVBlank();
	}

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
	consoleSetWindow(&consoleSub, 2, 2, 28, 20);

	enum GameState state = STATE_MAIN_MENU;

	while (state != STATE_EXIT) {
		switch (state) {
			case STATE_MAIN_MENU: {
				int choice = mainMenu();

				if (choice == 0) {
					state = STATE_PLAY_GAME;
				} else if (choice == 1) {
					state = STATE_SETTINGS;
				} else {
					state = STATE_EXIT;
				}
				break;
			}

			case STATE_PLAY_GAME:
				int slot = saveSlotsMenu();

				if (slot != -1) {
					currentActiveSlot = slot;

					SaveData myGameData = g_slotSystem.slots[slot].slotData;

					iprintf("\nStarting Game...\nSlot: %d", slot);

					state = STATE_INGAME;
				} else {
					state = STATE_MAIN_MENU;
				}
				break;

			case STATE_INGAME:
				// TODO Game Loop!

				consoleClear();
				iprintf("In Game! Slot %d\nPress START to exit", currentActiveSlot);
				while (1) {
					scanKeys();
					if (keysDown() & KEY_START) {
						state = STATE_MAIN_MENU;
						break;
					}
					swiWaitForVBlank();
				}
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
