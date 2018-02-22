//
// Created by Shishir on 19/02/2018.
//

#include <conio.h>
#include "MainGame.h"

using namespace std;

MainGame::MainGame() {
    screenWidth=640;    screenHeight=480;

    gameState = true;
    window = nullptr;

    cubeVertexBufferObjectID = 0;
    cubeIndexBufferObjectID = 0;

    transformMatrixBufferID = 0;

}

MainGame::~MainGame() {
    glDeleteBuffers(1, &cubeVertexBufferObjectID);
    glDeleteBuffers(1, &cubeIndexBufferObjectID);
    glDeleteBuffers(1, &transformMatrixBufferID);

    SDL_DestroyWindow(window);
}

void MainGame::fatalError(std::string error_string) {
    cout << error_string << endl;
    cout << endl << "Press any key to continue...";
    getch();

    SDL_Quit();
    exit(1);
}

void MainGame::run() {
    initSystems();
    gameLoop();
}

void MainGame::initSystems() {

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Graphics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if(window == nullptr) {
        string errorString = "Could not create SDL Window! Error Code: ";
        errorString += SDL_GetError();
        fatalError(errorString);
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if(glContext == NULL) {
        fatalError("Could not create GL context!");
    }

    glewExperimental = true;
    GLenum error = glewInit();
    if(error != GLEW_OK) {
        fatalError("Could not initialize glew!");
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 255);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 255);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 255);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    genVertex();
}

void MainGame::genVertex() {

}

void MainGame::gameLoop() {

    while (gameState) {
        processInputs();
        draw();
    }
}

void MainGame::processInputs() {

    while (SDL_PollEvent(&evnt)) {
        switch(evnt.type) {
            case SDL_QUIT:
                gameState = false;
                break;
            case SDL_MOUSEMOTION:
                cout << evnt.motion.x << ", " << evnt.motion.y << endl;
                break;
            case SDL_KEYDOWN:
                switch (evnt.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        gameState = false;
                        break;
                    default:
                        ;
                }
                break;
            default:
                gameState = true;
                break;
        }
    }
}

void MainGame::draw() {

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(window);
}
