#ifndef CLASS_SCENE_H
#define CLASS_SCENE_H

#include "Globals.h"
#include "Button.h"
#include "Select.h"
#include "TextInput.h"

class Scene
{
  public:
    Scene();
    virtual ~Scene();
    virtual void reload() = 0;
    virtual void clean() = 0;
    virtual void render() = 0;
    virtual void update(float dt) = 0;
};

#endif
