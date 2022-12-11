# include "Internal/Engine.hpp"

# include "Internal/Game/Interface.hpp"
# include "Internal/Game/Interface/Toggle.hpp"

namespace SS13::Game::Interface
{
    __Toggle::__Toggle()
    {
        Neck.Left(_Interface.X + _Interface.Size * 0);
        Neck.InvertedUp(_Interface.Y + _Interface.Size * 4);
        Neck.Size(_Interface.Size);

        Head.Left(_Interface.X + _Interface.Size * 1);
        Head.InvertedUp(_Interface.Y + _Interface.Size * 4);
        Head.Size(_Interface.Size);

        RightEar.Left(_Interface.X + _Interface.Size * 2);
        RightEar.InvertedUp(_Interface.Y + _Interface.Size * 4);
        RightEar.Size(_Interface.Size);

        Eyes.Left(_Interface.X + _Interface.Size * 0);
        Eyes.InvertedUp(_Interface.Y + _Interface.Size * 3);
        Eyes.Size(_Interface.Size);

        Mask.Left(_Interface.X + _Interface.Size * 1);
        Mask.InvertedUp(_Interface.Y + _Interface.Size * 3);
        Mask.Size(_Interface.Size);

        LeftEar.Left(_Interface.X + _Interface.Size * 2);
        LeftEar.InvertedUp(_Interface.Y + _Interface.Size * 3);
        LeftEar.Size(_Interface.Size);

        InnerClothing.Left(_Interface.X + _Interface.Size * 0);
        InnerClothing.InvertedUp(_Interface.Y + _Interface.Size * 2);
        InnerClothing.Size(_Interface.Size);

        OuterClothing.Left(_Interface.X + _Interface.Size * 1);
        OuterClothing.InvertedUp(_Interface.Y + _Interface.Size * 2);
        OuterClothing.Size(_Interface.Size);

        Gloves.Left(_Interface.X + _Interface.Size * 2);
        Gloves.InvertedUp(_Interface.Y + _Interface.Size * 2);
        Gloves.Size(_Interface.Size);

        Toggle.Left(_Interface.X + _Interface.Size * 0);
        Toggle.InvertedUp(_Interface.Y + _Interface.Size * 1);
        Toggle.Size(_Interface.Size);

        Shoes.Left(_Interface.X + _Interface.Size * 1);
        Shoes.InvertedUp(_Interface.Y + _Interface.Size * 1);
        Shoes.Size(_Interface.Size);
    }
    
    void __Toggle::operator()()
    {
        if (Toggle.Check())
        {
            Closed = !Closed;
        }
        switch (Closed)
        {
            case true:
                Toggle.Draw();
            break;
            case false:
                Neck.Draw();
                Head.Draw();
                RightEar.Draw();
                Eyes.Draw();
                Mask.Draw();
                LeftEar.Draw();
                InnerClothing.Draw();
                OuterClothing.Draw();
                Gloves.Draw();
                Toggle.Draw();
                Shoes.Draw();
            break;
        }
    }
}