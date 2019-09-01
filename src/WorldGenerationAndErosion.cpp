/**************************************/
/*	World Generation by Ethan Kelly   */
/*									  */
/*	 This world generation is just    */
/*  a test to see what I can do with  */
/*	the new libtcod stuff, and some   */
/*		  pretty novel ideas          */
/*									  */
/**************************************/

#include "WorldGenerationAndErosion.hpp"

int main(int argc, char* argv[]) {
	TCODConsole::setCustomFont("terminal16x16_gs_ro.png", TCOD_FONT_LAYOUT_ASCII_INROW);
	TCODConsole::initRoot(70, 35, "World Generation", FULLSCREEN, TCOD_RENDERER_GLSL);
	TCODSystem::setFps(30);

	TCOD_key_t keyPress = TCODConsole::checkForKeypress();

	while(!TCODConsole::isWindowClosed())
	{
		keyPress = TCODConsole::checkForKeypress();

		TCODConsole::root -> clear();
		TCODConsole::root -> flush();
	}

	return 0;
}