#pragma once
#ifndef worldgenerationanderosion_camera_hpp
#define worldgenerationanderosion_camera_hpp

class Camera {
public:
	Camera( int width, int height );
	~Camera();

	bool render( std::shared_ptr<PerlinMapGeneration> mapGen );
private:
	std::shared_ptr<TCODConsole> camera;
	int width, height;
	int x, y;
};

#endif //worldgenerationanderosion_camera_hpp
