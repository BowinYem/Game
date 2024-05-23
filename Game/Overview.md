TODO:

- Create a vector class so that we can take advatage of operator functions (therefore reducing the number of codel lines)

- Reimplement the x,y of an entity to actaully be the center - or maybe even give an option to specify a center

- For anything related to coordinates, convert from integral to floating type?

- For the rotation of an entity - implement a way for it to wrap around once it's greater than 360 
        
- Replace raw pointers
    - Create some wrapper class to encapsulate the keyboard state?
    
- After implementing some basic physics, play around with multiple resolutions 
    -	SDL_SetWindowFullscreen(GameSystems::GetGameSystems().GetWindow(), SDL_WINDOW_FULLSCREEN);
	    SDL_RenderSetLogicalSize(GameSystems::GetGameSystems().GetRenderer(), 1920, 1080);

- Make capitalizations consistent

- Why does specifying ~SpriteComponent() = default cause compilation errors?


Input Overview:
=============================

Components
----------
PlayerInputComponent - should only instantiate for players 




class PlayerInputComponent
{
public:
    void update() // process input and update player state    
}

void update()
{
    std::unique_ptr<uint8> KeyboardState = SDL_GetKeyboardState(nullptr);
}


* Have a seperate function that does this:
    


Animation?
====================================
//currentSprite = WallCycleFrames[currentFrame / (TOTAL_WALK_CYCLE_FRAMES * 3)];
++currentFrame;
if((currentFrame / (TOTAL_WALK_CYCLE_FRAMES * 3)) >= TOTAL_WALK_CYCLE_FRAMES)
{
	currentFrame = 0;
}