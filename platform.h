#include <SDL2/SDL.h>

class Platform{
    public:
    Platform(char const* , int , int , int , int );
    ~Platform();
    Platform(const Platform&) = delete; 
    Platform& operator=(const Platform&) = delete; 

    void Update(void const*, int);
    bool ProcessInput(uint8_t*);

	SDL_Window* window{};
	SDL_Renderer* renderer{};
	SDL_Texture* texture{};
};

