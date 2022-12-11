# include <iostream>

# include "External/SDL.h"

# include "Internal/Engine/Assert.hpp"

namespace SS13::Engine
{
    __Assert::__Assert()
    {
        std::system("ChCp 437");
        std::system("Cls");
    }

    void __Assert::operator()(const std::string& Message , bool Condition)
    {
        if (Condition)
        {
            if (SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR , "Assert!" , Message.c_str() , nullptr) < 0)
            {
                std::cerr << "Assert: " << Message << "\n";
                std::system("Pause");
            }
            std::exit(-1);
        }
    }
}