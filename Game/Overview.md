TODO:

- Create a draw rect function in GameRenderer (for trouble shooting)

- Implement basic collison - give each entity a rectangle - a wrapper class GameRect that wraps SDL_Rect? (Still deciding on this)
    - Gonna go with using a SDL_Rect for now - can implement this in the future if this is needed.
    - Putting this the physics component

- ProjectilePool encasulates some of projectile's behavior?

- Rewrite main loop to fit the loop pattern
    - rendering and reading input needs to happen at seperate times

- Replace raw pointers
    - Create some wrapper class to encapsulate the keyboard state?
    
- After implementing some basic physics, play around with multiple resolutions 
    -	SDL_SetWindowFullscreen(GameSystems::GetGameSystems().GetWindow(), SDL_WINDOW_FULLSCREEN);
	    SDL_RenderSetLogicalSize(GameSystems::GetGameSystems().GetRenderer(), 1920, 1080);

- Why does specifying ~SpriteComponent() = default cause compilation errors?


Project Rules
=============================

- Make capitalizations consistent:
        - Lowercase
            - class members 
            - function parameters  
            - local variables
        - Uppercase:
            - constant values 
            - class types name 
            - class functions 


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