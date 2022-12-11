# pragma once

namespace SS13::Engine::Graphics
{
    class _Button : public _Sprite
    {
        public:
            using _Sprite::_Sprite;
            bool Check();
    };
}