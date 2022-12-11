# pragma once

namespace SS13::Engine
{
    inline class __Assert
    {
        public:
            __Assert();
            void operator()(const std::string& Message , bool Condition = true);
    }
    _Assert;
}