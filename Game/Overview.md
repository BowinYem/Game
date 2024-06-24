TODO / IDEAS:

- Should GameSystems::window and GameSystems::renderer be shared_ptrs? Should they instead be unique_ptrs? 

- Create an enum for Game Entities identifying what kind of entitty it is: i.e: player, projectile, meteor, etc....

- Create a draw rect function in GameRenderer (for trouble shooting)

- Implement basic collison - give each entity a rectangle - a wrapper class GameRect that wraps SDL_Rect? (Still deciding on this)
    - Gonna go with using a SDL_Rect for now - can implement this in the future if this is needed.
    - Putting this in the physics component - have it check to see if it is colliding with another entity 

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
    
Collision System Overview:
=============================

* Going with brute force O(n^2) approach for now since our game is simple. This will later need to reimplemented later down the line. 
        void ProjectilePool::Update()
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

bool PhysicsComponent::IsColliding(const entity*) // I.E: Is the owner of this component colliding with some other entity?
{
    return SDL_IntersectRect(CollisionBox, Entity.GetCollisionBox());
}



Look into (results came from googling "collision detection check all entities")
https://gamedev.stackexchange.com/questions/46745/what-is-the-best-way-to-check-lists-of-objects-that-collide
https://gamedev.stackexchange.com/questions/201773/efficient-way-to-check-collisions-for-many-objects
https://stackoverflow.com/questions/10392335/how-to-check-for-2d-collision-without-checking-every-object
