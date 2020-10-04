#include "WorldGenerationAndErosion.hpp"

Camera::Camera( int width, int height ) : width( width ), height( height ), x( 0 ), y( 0 ) {

	camera = std::make_shared<TCODConsole>(width, height);
}

Camera::~Camera() {

}

bool Camera::render( std::shared_ptr<PerlinMapGeneration> mapGen ) {
	TCODConsole::blit((mapGen->map).get(), x, y, width, height, camera.get(), 0, 0);

	TCODConsole::blit(camera.get(), 0, 0, width, height, TCODConsole::root, 0, 0);

	return true;
}