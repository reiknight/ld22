#ifndef CLASS_GAME_H
#define CLASS_GAME_H

#include "Globals.h"
#include "Timer.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"

#define GAME_WIDTH 640
#define GAME_HEIGHT 480

/**
 * Core class
 */

class Game
{
  public:
    /**
     * Returns single instance of Game.
     * @return Unique instance of Game in whole program.
     */
    static Game* getInstance()
    {
      static Game instance;
      return &instance;
    }
    void reload();
    void clean();
    /**
     * Game loop
     */
    void loop();
    /**
     * Render the active scene.
     */
    void render();
    /**
     * Update the active scene.
     * @param dt milliseconds passed from last call.
     */
    void update(float);
    /***
     * Read the keyboard status
     */
    void readKeyboard(unsigned char key, bool pressed);
    void readMouse(int button, int state, int x, int y);
    TextureManager* getTextureManager();
    InputManager* getInputManager();
    ResourceManager* getResourceManager();
    SceneManager* getSceneManager();
    Player* getPlayer();
  private:
    Game();
    Game(Game const&);
    void operator=(Game const&);
    ~Game();
    /**
     * Ensure Game is executed at the same framerate
     * on all platforms
     */
    Timer timer;
    TextureManager *tm;
    InputManager *im;
    ResourceManager *rm;
    SceneManager *sm;
    Player *player;
};

#endif
