# include "Internal/Engine.hpp"

# include "Internal/Game/Level.hpp"
# include "Internal/Game/Player.hpp"

namespace SS13::Game
{
    __Player::__Player()
    {
        Scheme[0][0].Size(_Level.Tile);
        Scheme[0][1].Size(_Level.Tile);
        Scheme[0][2].Size(_Level.Tile);

        Scheme[1][0].Size(_Level.Tile);
        Scheme[1][1].Size(_Level.Tile);
        Scheme[1][2].Size(_Level.Tile);

        Scheme[2][0].Size(_Level.Tile);
        Scheme[2][1].Size(_Level.Tile);
        Scheme[2][2].Size(_Level.Tile);
    }

    void __Player::operator()()
    {
        if (Movement >= _Level.Tile)
        {
            X = 0;
            Y = 0;

            if (Engine::Input::_Keyboard.Held(SDL_SCANCODE_A))
            {
                Movement = 0;
                X--;
            }
            if (Engine::Input::_Keyboard.Held(SDL_SCANCODE_D))
            {
                Movement = 0;
                X++;
            }
            if (Engine::Input::_Keyboard.Held(SDL_SCANCODE_W))
            {
                Movement = 0;
                Y--;
            }
            if (Engine::Input::_Keyboard.Held(SDL_SCANCODE_S))
            {
                Movement = 0;
                Y++;
            }
        }
        else
        {
            Sprite = &Scheme[Y + 1ull][X + 1ull];

            Movement += Engine::_Time.Delta() * Speed;

            _Level.X -= X * Engine::_Time.Delta() * Speed;
            _Level.Y -= Y * Engine::_Time.Delta() * Speed;

            if (Movement >= _Level.Tile)
            {
                _Level.X = static_cast<signed int>(std::round(static_cast<float>(_Level.X) / static_cast<float>(_Level.Tile))) * _Level.Tile;
                _Level.Y = static_cast<signed int>(std::round(static_cast<float>(_Level.Y) / static_cast<float>(_Level.Tile))) * _Level.Tile;
            }
        }
        Sprite->Left(Center);
        Sprite->Up(Center);
        Sprite->Draw();
    }
}