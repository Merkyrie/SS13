# pragma once

namespace SS13::Engine
{
    inline class __Time
    {
        private:
            Uint64 Last;
            Uint64 Current;
        public:
            void operator()();
            Uint32 Delta();
    }
    _Time;
}