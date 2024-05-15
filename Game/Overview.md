TODO:

- Create three different kinds of input components:
    - InputComponent - overarching interface:
        - PlayerInputComponent
        - a null one
    

- Replace raw pointers
    - Leave SDL_Window and SDL_Renderer raw pointers alone for now...
    
- After implementing some basic physics, play around with multiple resolutions 
    -	SDL_SetWindowFullscreen(GameSystems::GetGameSystems().GetWindow(), SDL_WINDOW_FULLSCREEN);
	    SDL_RenderSetLogicalSize(GameSystems::GetGameSystems().GetRenderer(), 1920, 1080);

- Make capitalizations consistent

- Why does specifying ~SpriteComponent() = default cause compilation errors?


GameRenderer
===================
class GameRenderer
{
public:
    GameRenderer();
    ~GameRenderer();

    GameRendererClear();
    GameRendererCopy(const GameTexture& texture);
    GameRendererPresent();

private:
    SDL_Renderer* renderer 
};





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