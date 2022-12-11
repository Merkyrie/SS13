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
        Equip.RelativeX(2);
        Equip.RelativeY(2);

        Swap.Scale(Scale);
        Swap.Left(Frame.Left());
        Swap.Up(Frame.Up());
        Swap.RelativeX(14);
        Swap.RelativeY(2);

        RightHand.Scale(Scale);
        RightHand.Left(Frame.Left());
        RightHand.Up(Frame.Up());
        RightHand.RelativeX(2);
        RightHand.RelativeY(12);

        LeftHand.Scale(Scale);
        LeftHand.Left(Frame.Left());
        LeftHand.Up(Frame.Up());
        LeftHand.RelativeX(34);
        LeftHand.RelativeY(12);

        Selection.Scale(Scale);
        Selection.Left(Frame.Left());
        Selection.Up(Frame.Up());
        Selection.RelativeX(0);
        Selection.RelativeY(10);
    }
    
    void __Hands::operator()()
    {
        if (Swap.Check())
        {
            switch (Right)
            {
                case true:
                    Selection.RelativeX(32);
                break;
                case false:
                    Selection.RelativeX(-32);
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