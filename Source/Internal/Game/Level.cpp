# include "Internal/Engine.hpp"

# include "Internal/Game/Level.hpp"

namespace SS13::Game
{
    __Level::__Level()
    {
        for (signed int X{0} ; X < Size ; X++)
        {
            for (signed int Y{0} ; Y < Size ; Y++)
            {
                Map[X][Y].Size(Tile);
            }
        }
    }

    void __Level::operator()()
    {
        for (signed int X{0} ; X < Size ; X++)
        {
            for (signed int Y{0} ; Y < Size ; Y++)
            {
                Map[X][Y].Left(this->X + X * Tile);
                Map[X][Y].Up(this->Y + Y * Tile);
                Map[X][Y].Draw();
            }
        }
    }
}