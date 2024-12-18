TODO / IDEAS:

- Bug: After destorying all meteors and the max num of projectiles out of bounds, you cant shoot anymore
    - The projecile destruction logic being nested in if(meteorPool->IsMeteorInUse(i)) is causing this
    - Fixed - but test this a little more...

- Implement a count for the meteor pool and do the checks we did in projectile pool as well.

- Change SpriteComponent::SpriteComponent(const std::string& filePath), so that it accepts two additonal argument that determine the size to render the sprite ingame

- Impelemnt GameSystems::Close() - need to close SDL subsystems

- Implement extrapolation and decouple game speed from CPU speed

- Revaluate usage of unique_ptr throughout the whole program - improper use of this can cause memory issues? Question whether or not these should be
    shared_ptr instead. 

- Rewrite main loop to fit the loop pattern
    - rendering and reading input needs to happen at seperate times

- Replace raw pointers
    - Create some wrapper class to encapsulate the keyboard state?
    
- After implementing some basic physics, play around with multiple resolutions 
    -	SDL_SetWindowFullscreen(GameSystems::GetGameSystems().GetWindow(), SDL_WINDOW_FULLSCREEN);
	    SDL_RenderSetLogicalSize(GameSystems::GetGameSystems().GetRenderer(), 1920, 1080);


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


Frame Rate implementation
===============================

TO DO
* Double Check whether or not the timestep calculations are correct 
    - Make a new branch just for this
* Compare the current implementation to this:
    - https://gafferongames.com/post/fix_your_timestep/
* Rename timestep variabe to "delta" 
* Make sure we're working with floating point values - i.e use sdl_frect not sdl_rect, call the floating point version of SDL_Render, etc...
* Test whether or not implementation worked by changing MS_PER_UPDATE




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
    
Collision System Overview:
=============================

* Going with brute force O(n^2) approach for now since our game is simple. This will later need to reimplemented later down the line. 
        void MeteorPool::Update()
        {
            for each Projectile...
            //...
                for each meteor
                    check to see if the projectile has hit a meteor
                    O(n^2) - VERY BAD...but our sample size is small...
        }

Idea 1 - check to see if the entity's collisionBox is intersecting with every other existing entity's collison Box
    - Not optimal?
    - For meteors, you'll only need to see if it's colliding with the player. 
        - Have a pointer to the player globally available
        - Vice versa for the player - only compare it to any active meteor. (Have a meteor pool?)
    - For player projeciles - similar jist as above
    
- Additional Idea - we can create a physics component subtype (if neededed)


SDL_Rect GameEntity::GetCollisionBox()
{
    if(!physicsComp)
        return physicsComp.CollisionBox;
    else return a zero'd out rect?
}


Look into (results came from googling "collision detection check all entities")
https://gamedev.stackexchange.com/questions/46745/what-is-the-best-way-to-check-lists-of-objects-that-collide
https://gamedev.stackexchange.com/questions/201773/efficient-way-to-check-collisions-for-many-objects
https://stackoverflow.com/questions/10392335/how-to-check-for-2d-collision-without-checking-every-object
