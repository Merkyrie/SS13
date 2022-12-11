# pragma once

namespace SS13::Engine
{
    inline class Assert
    {
        public:
            Assert();
            void operator()(const std::string& Title , const std::string& Message , bool Condition = true);
    }
    _Assert;
}