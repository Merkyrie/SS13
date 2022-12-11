# include <vector>
# include <filesystem>

# include "External/SDL.h"

# include "Internal/Time.hpp"
# include "Internal/Sprite.hpp"
# include "Internal/Animation.hpp"
# include "Internal/Animator.hpp"

namespace SS13
{
    _Animator::_Animator(const std::string& Path , signed int Size , Uint32 Duration)
    {
        for (const std::filesystem::directory_entry& Entry : std::filesystem::directory_iterator(Path))
        {
            Animations.emplace_back
            (AnimStruct
            {
                .AnimField{Entry.path().string() , Size , Duration} ,
                .Tag{(Entry.path().filename().string())} ,
            }
            );
        }
        Animation = 0;
    }

    void _Animator::Set(const std::string& Tag)
    {
        for (std::vector<AnimStruct>::size_type Index{0} ; Index < Animations.size() ; Index++)
        {
            if (Animations[Index].Tag == Tag)
            {
                if (Animation != Index)
                {
                    Animation = Index;
                    Animations[Animation].AnimField.Reset();
                }
                break;
            }
        }
    }

    void _Animator::Update()
    {
        Animations[Animation].AnimField.Update();
    }

    void _Animator::Draw(signed int X , signed int Y)
    {
        Animations[Animation].AnimField.Draw(X , Y);
    }
}