# pragma once

namespace SS13::Game::Interface
{
    inline class __Toggle
    {
        public:    
            bool Closed{true};
            Engine::Graphics::_Button Neck{"Sprites\\Interface\\Toggle\\Neck.png"};
            Engine::Graphics::_Button Head{"Sprites\\Interface\\Toggle\\Head.png"};
            Engine::Graphics::_Button RightEar{"Sprites\\Interface\\Toggle\\Ear.png"};
            Engine::Graphics::_Button Eyes{"Sprites\\Interface\\Toggle\\Eyes.png"};
            Engine::Graphics::_Button Mask{"Sprites\\Interface\\Toggle\\Mask.png"};
            Engine::Graphics::_Button LeftEar{"Sprites\\Interface\\Toggle\\Ear.png"};
            Engine::Graphics::_Button InnerClothing{"Sprites\\Interface\\Toggle\\Inner Clothing.png"};
            Engine::Graphics::_Button OuterClothing{"Sprites\\Interface\\Toggle\\Outer Clothing.png"};
            Engine::Graphics::_Button Gloves{"Sprites\\Interface\\Toggle\\Gloves.png"};
            Engine::Graphics::_Button Toggle{"Sprites\\Interface\\Toggle\\Toggle.png"};
            Engine::Graphics::_Button Shoes{"Sprites\\Interface\\Toggle\\Shoes.png"};
        public:
            __Toggle();
            void operator()();
    }
    _Toggle;
}