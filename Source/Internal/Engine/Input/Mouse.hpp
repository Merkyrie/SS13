# pragma once

namespace SS13::Engine::Input
{
    inline class __Mouse
    {
        private:
            Uint32 LastState;
        public:
            void operator()();
            bool Held(Uint32 Button);
            bool Pressed(Uint32 Button);
            signed int X();
            signed int Y();
    }
    _Mouse;
}