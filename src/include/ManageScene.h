#ifndef CLASS_MANAGE_SCENE_H
#define CLASS_MANAGE_SCENE_H

#include "Globals.h"
#include "Scene.h"
#include "Button.h"
#include "Select.h"
#include "TextInput.h"
#include "Player.h"

class ManageScene : public Scene
{
  public:
    ManageScene();
    ~ManageScene();
    void reload();
    void clean();
    void render();
    void update(float dt);
  private:
    Button *button;
    vector<Select*> selects;
    vector<TextInput*> text_inputs;
};

#endif
