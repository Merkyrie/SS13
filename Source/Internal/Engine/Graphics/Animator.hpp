# pragma once

namespace SS13
{
    class _Animator
    {
        public:
            struct AnimStruct
            {
                _Animation AnimField;
                std::string Tag;
            };
        public:
            std::vector<AnimStruct> Animations;
            std::vector<AnimStruct>::size_type Animation;
        public:
            _Animator(const std::string& Path , signed int Size , Uint32 Duration);
            void Set(const std::string& Tag);
            void Update();
            void Draw(signed int X , signed int Y);
    };
}