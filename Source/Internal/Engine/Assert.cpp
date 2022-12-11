# include <iostream>

# include "External/SDL.h"

# include "Internal/Engine/Assert.hpp"

namespace SS13::Engine
{
    Assert::Assert()
    {
        std::system("ChCp 437");
        std::system("Cls");
    }

    void Assert::operator()(const std::string& Title , const std::string& Message , bool Condition)
    {
        if (Condition)
        {
            if (SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR , Title.c_str() , Message.c_str() , nullptr) < 0)
            {
                std::cerr << Title << ": " << Message << "\n";
                std::system("Pause");
            }
            std::exit(-1);
        }
    }
}