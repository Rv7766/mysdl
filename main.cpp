// g++ -std=c++17 main.cpp -o prog -lSDL2

// C++ Standard Libraries
#include <iostream>
#include<stdlib.h>
// Third-party library
#include <SDL2/SDL.h>

int main(int argc, char* argv[]){

    SDL_Window* window=nullptr;
    int number_for_sdl_init_video;
    number_for_sdl_init_video=SDL_Init(SDL_INIT_VIDEO);

    if(number_for_sdl_init_video < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }
    /*
    Request a window to be created in our platform,the parameters are for title,x and y position of our window, and the width and height of our window
    */
    window=SDL_CreateWindow("MyFirstSDLWindow",1000,0,720,640,SDL_WINDOW_SHOWN);

    //creating an infinite while loop for our appliction 
    bool gameIsRunning=true;
    while (gameIsRunning)
    {
        SDL_Event event;
        //starting our event loop
        while (SDL_PollEvent(&event))
        {
            //handle each specific event
            if(event.type == SDL_QUIT)
            {
                gameIsRunning=false;
            }
            
        }
        
    }
    /*
    We are destroying our window , we are passing in the address of our window by using the pointer that points to the memory allocated by the 'SDL_CreateWindow()' function

    Remember in c api(sdl) we don't have destructors ,so we need to deallocated memeory as well
    */
    SDL_DestroyWindow(window);
    

    /*
    We sucessfully uninitialized sdl2,which was initialized by SDL_Init(SDL_INIT_VIDEO) function, we are taking down the subsystems here before we exit our program
    */
    SDL_Quit();
    return EXIT_SUCCESS;
    ;
}

