#pragma once
#ifndef worldgenerationanderosion_worldgenerationanderosion_hpp
#define worldgenerationanderosion_worldgenerationanderosion_hpp

// Libtcod Libs
#include "..\include\libtcod.hpp"
#include "..\include\libtcod\gui\gui.hpp"
#include "..\include\libtcod\gui\gui_portability.hpp"

// Program headers
#include "MapGeneration.hpp"
#include "Camera.hpp"

// STL
#include <bitset>
#include <memory>
#include <vector>

static const bool FULLSCREEN = false;
static const double TRANSCENDENTAL_E = 2.7182818284590452353602875;

class WorldGenEngine {
public:
	WorldGenEngine();
	~WorldGenEngine();

	void initEngine();
private:

};

#endif //worldgenerationanderosion_worldgenerationanderosion_hpp