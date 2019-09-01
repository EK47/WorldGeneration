#pragma once
#ifndef worldgenerationanderosion_worldgenerationanderosion_hpp
#define worldgenerationanderosion_worldgenerationanderosion_hpp

#include "..\include\libtcod.hpp"

#include <memory>
#include <math.h>
#include <vector>

static const bool FULLSCREEN = false;

class WorldGenEngine {
public:
	WorldGenEngine();
	~WorldGenEngine();

	void initEngine();
private:

};

#endif //worldgenerationanderosion_worldgenerationanderosion_hpp