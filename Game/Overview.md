TODO:
- Replace raw pointers
    - Leave SDL_Window and SDL_Renderer raw pointers alone for now...
    
- After implmeneting Entities that can hold a graphics component, play around with multiple resolutions 
- Make capitalizations consistent
- Why does specifying ~SpriteComponent() = default cause compilation errors?

Graphics Overview:

Services
---------
Renderer - Create a singleton?
    - Create an init function - possibly apart of a large init function


Components
---------
SpriteComponent


Input Overview:

Components
----------
InputComponent - should only instantiate for players 
