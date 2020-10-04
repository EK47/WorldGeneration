#include "WorldGenerationAndErosion.hpp"

// The water droplet is used to move and deposit sediments around the map.

WaterDroplet::WaterDroplet( int x, int y ) : x( x ), y( y ) {
	timeLeft = 128;
	sedimentAmount = 0.0f;
}

WaterDroplet::~WaterDroplet() {

}

////////////////////////////
// MAP GENERATION SECTION //
////////////////////////////

PerlinMapGeneration::PerlinMapGeneration( int iterations, int scale, int width, int height, int viewingWidth, int viewingHeight ) : width( width ), height( height ), viewingWidth( viewingWidth ), viewingHeight( viewingHeight ) {
	
	// This generatess perlin noise
	terrainGen = std::make_shared<TCODNoise>(2);
	terrainGen->setType(TCOD_NOISE_SIMPLEX);

	map = std::make_shared<TCODConsole>(width, height);

	generate(iterations, scale);
}

PerlinMapGeneration::~PerlinMapGeneration() {

}

bool PerlinMapGeneration::generate( int iterations, int scale ) {
	// This creates n heightmaps that will later be combined to form terrain
	for(int i = 0; i <= iterations; ++i) {
		std::shared_ptr<TCODHeightMap> heightMap = std::make_shared<TCODHeightMap>(width, height);
		mapVector.push_back(heightMap);
	}

	// This clears all of the heightmaps, just in case.
	for(int i = 0; i <= iterations; ++i) {
		(mapVector.at(i))->clear();
	}

	// This can be compared to a fourier series. The radical nature of the heightmap increases as the overall effect decreases.
	// Any arbitrary constants have no meaning in the physical model. Floating point numbers are used to create precision when necessary
	for(int i = 0; i <= iterations; ++i) {
		(mapVector.at(i))->addFbm(terrainGen.get(), (width/100.0f) * (i + 3), (height/100.0f) * (i + 3), (2.0f * scale) / (i + 1), (2.0f * scale) / (i + 1), scale / (2 * (i + 1)), 0.0f, 1.0f);
	}

	// This adds the heightmaps together, then normalizes the output
	for(int i = iterations - 1; i >= 0; --i) {
		(mapVector.at(i))->add((mapVector.at(i)).get(), (mapVector.at(i + 1)).get());
		(mapVector.at(i))->normalize(0.0f, 1.0f);
	}

	mapVector.erase(mapVector.begin() + 1, mapVector.end());

	return true;
}

bool PerlinMapGeneration::erode(int time, int dropletsPerTime, float avgIntensity) {

	// This block of code generates a certain amount of droplets every specified time. The droplets run their course. After the
	// droplets have died, the system resets with new droplets.
	std::vector<WaterDroplet> droplets;

	for(int i = 0; i < time; ++i) {

	}

	return true;
}

void PerlinMapGeneration::update() {
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			TCODColor tile;

			double tileVal = (mapVector.at(0))->getValue(x, y);

			/**if( tileVal < 0.6f ) {
				tile = TCODColor::darkGreen * tileVal;
			}
			else if(tileVal >= 0.6f) {
				tile = TCODColor::lerp(TCODColor::darkerGreen, TCODColor::lightestGrey, tileVal);
			}**/

			tile = TCODColor::lerp(TCODColor::darkestGreen, TCODColor::green, tileVal);

			map->setCharBackground(x, y, tile);
		}
	}
}