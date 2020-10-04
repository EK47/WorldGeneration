#pragma once
#ifndef worldgenerationanderosion_mapgeneration_hpp
#define worldgenerationanderosion_mapgeneration_hpp

class WaterDroplet {
public:
	WaterDroplet( int x, int y );
	~WaterDroplet();
private:
	unsigned short timeLeft;
	float sedimentAmount;
	int x, y;
};

class PerlinMapGeneration {
public:
	PerlinMapGeneration( int iterations, int scale, int width, int height, int viewingWidth, int viewingHeight );
	~PerlinMapGeneration();

	bool erode(int time, int dropletsPerTime, float avgIntensity);
	bool generate( int iterations, int scale );
	void update();

	std::vector<std::shared_ptr<TCODHeightMap>> mapVector;
	std::shared_ptr<TCODConsole> map;
private:
	std::shared_ptr<TCODNoise> terrainGen;
	int iterations, width, height, viewingWidth, viewingHeight;
};

#endif //worldgenerationanderosion_mapgeneration_hpp