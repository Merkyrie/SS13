# include <iostream>
# include <vector>

# include "External/SDL_image.h"

# include "Internal/Engine/Assert.hpp"
# include "Internal/Engine/Graphics.hpp"
# include "Internal/Engine/Graphics/Atlas.hpp"
# include "Internal/Engine/Graphics/Sprite.hpp"

using namespace std::literals;

namespace SS13::Engine::Graphics
{
    _Sprite::_Sprite(const std::string& Path)
    {
        vPath = Path;
        vTexture = _Atlas[vPath];
        _Assert
        (
            "Class: _Sprite"s + "\n" +
            "Method: _Sprite(const std::string& Path)" + "\n" +
            "Path: " + vPath + "\n" +
            "Message: failed to query sprite's width and height!" + "\n" +
            SDL_GetError() + "\n" ,
            SDL_QueryTexture(vTexture , nullptr , nullptr , &vWidth , &vHeight) < 0
        );
    }

    signed int _Sprite::Left()
    {
        return vX;
    }

    signed int _Sprite::Up()
    {
        return vY;
    }

    signed int _Sprite::Right()
    {
        return vX + vWidth;
    }

    signed int _Sprite::Down()
    {
        return vY + vHeight;
    }
    
    void _Sprite::Left(signed int Value)
    {
        vX = Value;
    }

    void _Sprite::Up(signed int Value)
    {
        vY = Value;
    }

    void _Sprite::Right(signed int Value)
    {
        vX = Value - vWidth;
    }

    void _Sprite::Down(signed int Value)
    {
        vY = Value - vHeight;
    }

    void _Sprite::InvertedLeft(signed int Value)
    {
        vX = _Graphics.Width - Value;
    }

    void _Sprite::InvertedUp(signed int Value)
    {
        vY = _Graphics.Height - Value;
    }

    void _Sprite::InvertedRight(signed int Value)
    {
        vX = _Graphics.Width - (Value - vWidth);
    }

    void _Sprite::InvertedDown(signed int Value)
    {
        vY = _Graphics.Height - (Value - vHeight);
    }

    void _Sprite::RelativeX(signed int Coefficient)
    {
        vX += static_cast<signed int>(std::round(vScale * static_cast<float>(Coefficient)));
    }

    void _Sprite::RelativeY(signed int Coefficient)
    {
        vY += static_cast<signed int>(std::round(vScale * static_cast<float>(Coefficient)));
    }

    void _Sprite::Size(signed int Value)
    {
        _Assert
        (
            "Class: _Sprite"s + "\n" +
            "Method: Size(signed int Value)" + "\n" +
            "Path: " + vPath + "\n" +
            "Message: unable to use this method if sprite's width is not equal to it's height!" + "\n" ,
            vWidth != vHeight
        );
        vWidth = Value;
        vHeight = Value;
    }

    void _Sprite::Scale(float Coefficient)
    {
        vWidth = static_cast<signed int>(std::round(static_cast<float>(vWidth) / vScale * Coefficient));
        vHeight = static_cast<signed int>(std::round(static_cast<float>(vHeight) / vScale * Coefficient));
        vScale = Coefficient;
    }

    void _Sprite::Draw()
    {
        SDL_DisplayMode Mode;
        SDL_GetWindowDisplayMode(_Graphics.Window , &Mode);
        SDL_Rect Rectangle
        {
            .x{static_cast<signed int>(std::round(static_cast<float>(vX) * static_cast<float>(Mode.w) / static_cast<float>(_Graphics.Width)))} ,
            .y{static_cast<signed int>(std::round(static_cast<float>(vY) * static_cast<float>(Mode.h) / static_cast<float>(_Graphics.Height)))} ,
            .w{static_cast<signed int>(std::round(static_cast<float>(vWidth) * static_cast<float>(Mode.w) / static_cast<float>(_Graphics.Width)))} ,
            .h{static_cast<signed int>(std::round(static_cast<float>(vHeight) * static_cast<float>(Mode.h) / static_cast<float>(_Graphics.Height)))} ,
        };
        SDL_RenderCopy(_Graphics.Renderer , vTexture , nullptr , &Rectangle);
    }
}