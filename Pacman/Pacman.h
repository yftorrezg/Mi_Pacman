#pragma once

#include <algorithm>

#include <SDL.h>
#include "Texture.h"
#include "GameObject.h"
#include "Tile.h"
#include "TileGraph.h"
#include "Point.h"
#include "MoveDirection.h"

// Just a temporary solution
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

class Pacman : public GameObject
{
public:
	//static TileGraph* tileGraph;

	// Prefixed width and height of Pacman
	static const int Width = 25;
	static const int Height = 25;

	// Number of frames in movment animation
	static const int MoveFrames = 2;

	// Movement per frame
	static const int Velocity = 3;

	// Pacman();

	Pacman(Tile* tile, Texture* texture);
	~Pacman();

	// Loads texture and sets up animation clips
	bool LoadMedia();

	// Sets postiton of pacman
	// void SetPos(int x, int y);

	// Sets the tile of the pacman
	void SetTile(Tile* newTile);

	// Sets the next tile (to which pacman will go)
	void SetNextTile(Tile* newNextTile);

	// Handles key presses
	void HandleEvents(SDL_Event* event);

	// Updates the posititon and check collision
	void Update();

	// Renders pacman
	void Render();

	// Mark the object to be deleted
	void Delete();

	// Releases texture memory
	// void Free();

	// Returns current direction of movement
	MoveDirection GetMoveDirection();

	// Returns collider
	SDL_Rect GetCollider();

	// Returns position
	SDL_Point GetPosition();

	// Returns pacman's tile
	Tile* GetTile();

	// Returns the tile which pacman is going to
	Tile* GetNextTile();

	// Returns true if pacman is moving
	bool IsMoving();

private:
	// Trys to move the pacman in desired direction
	// Returns true if successful, false otherwise
	bool TryToMove(MoveDirection direction);

	// Check if pacman is colliding with other collider
	bool CheckForCollision(const SDL_Rect &otherCollider);

	// Check if given collider is colliding with another collider
	bool CheckForCollision(const SDL_Rect &collider, const SDL_Rect &otherCollider);

	Texture* pacmanTexture;

	SDL_Rect upAnimClips[2];
	SDL_Rect downAnimClips[2];
	SDL_Rect leftAnimClips[2];
	SDL_Rect rightAnimClips[2];

	int frame, frameCount;

	MoveDirection moveDir;
	MoveDirection nextDir;
	bool moving;
	SDL_Point position;

	Tile* currTile;
	Tile* nextTile;

	SDL_Rect collider;
};

