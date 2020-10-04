/**************************************/
/*	World Generation by Ethan Kelly   */
/*									  */
/*	 This world generation is just    */
/*  a test to see what I can do with  */
/*	the new libtcod stuff, and some   */
/*		  pretty novel ideas          */
/*									  */
/**************************************/

/* 
 * I'm going to be honest - I don't know what the hell is going on the with math here. It's funky, unstable, and frankly stupid, but I would be lying
 * if I said it didn't make some pretty damn nice terrain when it does work. I'm going to list some rules below for future reference.
 *
 *  When the scale value calculated in MapGeneration.cpp is near the iterations, terrain goes to garbage.
 *  I did some Mathematica Scripting tests. It enlightened me a bit. I realized that basing the iteration amount on the map size is a *terrible* idea.
 * If I keep the iteration amount constant, things are easier to manage. This leads to the issue of finding an appropriate constant for the scaling factor.
 * 
 */

#include "WorldGenerationAndErosion.hpp"

TCOD_key_t keyPress{ TCODK_NONE };
// This has to be at least 42? ( ??? )
const int WIDTH_VIEW = 100;
const int HEIGHT_VIEW = 60;
const int WIDTH_MAP = 100;
const int HEIGHT_MAP = 60;

int main(int argc, char* argv[]) {
	TCODConsole::setCustomFont("terminal16x16_gs_ro.png", TCOD_FONT_LAYOUT_ASCII_INROW);
	TCODConsole::initRoot(WIDTH_VIEW, HEIGHT_VIEW, "World Generation", FULLSCREEN, TCOD_RENDERER_GLSL);
	TCODSystem::setFps(30);

	int minIter = 1000;

	std::cout << minIter << std::endl;

	// This is the scaling value for the octaves. This creates the slow additive process for each heightmap.
	//float initialScale = minIter / pow(TRANSCENDENTAL_E, ((WIDTH_MAP * HEIGHT_MAP) / (static_cast<float>((WIDTH_MAP + HEIGHT_MAP)/50) * minIter)));

	float initialScale = 100;

	std::cout << "Scale value: " << initialScale << std::endl;

	std::shared_ptr<PerlinMapGeneration> mapGen = std::make_shared<PerlinMapGeneration>(minIter, initialScale, WIDTH_MAP, HEIGHT_MAP, WIDTH_VIEW, HEIGHT_VIEW);
	
	std::unique_ptr<Camera> camera1 = std::make_unique<Camera>(WIDTH_VIEW, HEIGHT_VIEW);

	while(!TCODConsole::isWindowClosed())
	{
		keyPress = TCODConsole::checkForKeypress();

		TCODConsole::root->clear();

		if(keyPress.c == 'r') {
			mapGen->generate(minIter, initialScale);
		}

		mapGen->update();

		camera1->render(mapGen);

		TCODConsole::root->flush();
	}

	return 0;
}