#pragma once
#include <raylib.h>
#include <raymath.h>
#include "SceneObject.h"
//just followed tutorial
//turns out i didn't need it for matrix hierachry 

//class Game {
//public:
//    Game();
//    virtual ~Game();
//    virtual bool startup();
//    virtual void shutdown();
//
//    virtual void update(float deltaTime);
//    virtual void draw();
//};

/*struct SpriteObject : public SceneObject{
public:

    SpriteObject() {}
    SpriteObject(const char* filename) { load(filename); }
    virtual ~SpriteObject() { delete m_texture; }

    bool load(const char* filename) {
        delete m_texture;
        m_texture = nullptr;
        m_texture = new aie::Texture(filename);
        return m_texture != nullptr;
    }

protected:
    TextureID m_texture;
};*/