# include <iostream>
# include <vector>

# include "External/SDL_image.h"

# include "Internal/Engine/Assert.hpp"
# include "Internal/Engine/Graphics.hpp"
# include "Internal/Engine/Graphics/Atlas.hpp"
# include "Internal/Engine/Graphics/Sprite.hpp"

namespace SS13::Engine::Graphics
{
    _Sprite::_Sprite(const std::string& Path)
    {
        vPath = Path;
        vTexture = _Atlas[vPath];
        _Assert
        (
            "Sprite" ,
            std::string{} +
            "Method: _Sprite(const std::string& Path)" + "\n" +
            "Path: " + vPath + "\n" +
            "Assert: SDL_QueryTexture(Texture , nullptr , nullptr , &Width , &Height) < 0" + "\n" +
            "SDL: " + SDL_GetError() + "\n" ,
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

    void _Sprite::ScaledOffsetX(signed int Coefficient)
    {
        vX += static_cast<signed int>(std::round(vScale * static_cast<float>(Coefficient)));
    }

    void _Sprite::ScaledOffsetY(signed int Coefficient)
    {
        vY += static_cast<signed int>(std::round(vScale * static_cast<float>(Coefficient)));
    }

    void _Sprite::Size(signed int Value)
    {
        _Assert
        (
            "Sprite" ,
            std::string{} +
            "Method: SetSize(signed int Size)" + "\n" +
            "Path: " + vPath + "\n" +
            "Assert: Width != Height" + "\n" ,
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
        SDL_Rect Rectangle
        {
            .x{_Graphics.ActualX(vX)} ,
            .y{_Graphics.ActualY(vY)} ,
            .w{_Graphics.ActualX(vWidth)} ,
            .h{_Graphics.ActualY(vHeight)} ,
        };
        SDL_RenderCopy(_Graphics.Renderer , vTexture , nullptr , &Rectangle);
    }
}