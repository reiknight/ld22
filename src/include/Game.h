#ifndef CLASS_GAME_H
#define CLASS_GAME_H

#include "Globals.h"
#include "Timer.h"
#include "TextureManager.h"
#include "Scene.h"

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
    void readKeyboard(char key, bool pressed);
    TextureManager* getTextureManager();
  private:
    Game();
    Game(Game const&);
    void operator=(Game const&);
    ~Game();
    void loadTextures();
    /**
     * Ensure Game is executed at the same framerate
     * on all platforms
     */
    Timer timer;
    TextureManager *tm;
    Scene *scene;
};

#endif
