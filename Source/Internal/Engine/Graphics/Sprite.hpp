# pragma once

namespace SS13::Engine::Graphics
{
    class _Sprite
    {
        protected:
            std::string vPath;
            SDL_Texture* vTexture;
            signed int vWidth;
            signed int vHeight;
        protected:
            signed int vX{0};
            signed int vY{0};
            float vScale{1.0f};
        public:
            _Sprite(const std::string& Path);
        public:
            signed int Left();
            signed int Up();
            signed int Right();
            signed int Down();
        public:
            void Left(signed int Value);
            void Up(signed int Value);
            void Right(signed int Value);
            void Down(signed int Value);
        public:
            void InvertedLeft(signed int Value);
            void InvertedUp(signed int Value);
            void InvertedRight(signed int Value);
            void InvertedDown(signed int Value);
        public:
            void ScaledOffsetX(signed int Coefficient);
            void ScaledOffsetY(signed int Coefficient);
        public:
            void Size(signed int Value);
            void Scale(float Coefficient);
        public:    
            void Draw();
    };
}