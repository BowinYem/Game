#include "GameRect.h"

GameRect::GameRect(const float x_, const float y_, const float w_, const float h_) :
    x{x_}, y{y_}, w{w_}, h{h_}
{
    //...
}

bool GameRect::HasIntersection(const GameRect& rectA, const GameRect& rectB)
{
    SDL_Rect rectA_ = rectA.GetIRect();
    SDL_Rect rectB_ = rectB.GetIRect();
    return SDL_HasIntersection(&rectA_, &rectB_); 
}