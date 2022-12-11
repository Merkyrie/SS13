# include "Internal/Engine.hpp"

# include "Internal/Game/Interface.hpp"
# include "Internal/Game/Interface/Back.hpp"
# include "Internal/Game/Interface/Hands.hpp"

namespace SS13::Game::Interface
{
    __Hands::__Hands()
    {
        Frame.Scale(Scale);
        Frame.Left(_Back.Button.Right());
        Frame.Down(_Back.Button.Down());

        Equip.Scale(Scale);
        Equip.Left(Frame.Left());
        Equip.Up(Frame.Up());
        Equip.ScaledOffsetX(2);
        Equip.ScaledOffsetY(2);

        Swap.Scale(Scale);
        Swap.Left(Frame.Left());
        Swap.Up(Frame.Up());
        Swap.ScaledOffsetX(14);
        Swap.ScaledOffsetY(2);

        RightHand.Scale(Scale);
        RightHand.Left(Frame.Left());
        RightHand.Up(Frame.Up());
        RightHand.ScaledOffsetX(2);
        RightHand.ScaledOffsetY(12);

        LeftHand.Scale(Scale);
        LeftHand.Left(Frame.Left());
        LeftHand.Up(Frame.Up());
        LeftHand.ScaledOffsetX(34);
        LeftHand.ScaledOffsetY(12);

        Selection.Scale(Scale);
        Selection.Left(Frame.Left());
        Selection.Up(Frame.Up());
        Selection.ScaledOffsetX(0);
        Selection.ScaledOffsetY(10);
    }
    
    void __Hands::operator()()
    {
        if (Swap.Check())
        {
            switch (Right)
            {
                case true:
                    Selection.ScaledOffsetX(32);
                break;
                case false:
                    Selection.ScaledOffsetX(-32);
                break;
            }
            Right = !Right;
        }
        Frame.Draw();
        Equip.Draw();
        Swap.Draw();
        RightHand.Draw();
        LeftHand.Draw();
        Selection.Draw();
    }
}