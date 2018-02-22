//
// Created by Shishir on 19/02/2018.
//

#ifndef BALL_MAINGAME_H
#define BALL_MAINGAME_H

#define GLEW_STATIC
#define GLEW_BUILD

#include <iostream>
#include "SDL2/SDL.h"
#include "GL/glew.h"

class MainGame {
private:
    bool gameState;

    int screenWidth, screenHeight;
    SDL_Window *window;
    SDL_Event evnt;

    GLuint cubeVertexBufferObjectID;
    GLuint cubeIndexBufferObjectID;

    GLuint transformMatrixBufferID;

    void initSystems();
    void gameLoop();
    void processInputs();
    void genVertex();
    void draw();

public:
    MainGame();
    ~MainGame();
    void run();

    void fatalError(std::string basic_string);
};


#endif //BALL_MAINGAME_H
