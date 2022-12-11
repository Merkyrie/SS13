# pragma once

namespace SS13::Engine::Input
{
    inline class __Keyboard
    {
        private:
            Uint8 LastState[SDL_NUM_SCANCODES];
        public:
            void operator()();
            bool Held(signed int Key);
            bool Pressed(signed int Key);
    }
    _Keyboard;
}