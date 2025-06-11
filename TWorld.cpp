#include "TWorld.h"

TWorld& TWorld::Instance()
{
    static TWorld instance;
    return instance;
}

TScene* TWorld::NewScene()
{
    Instance().m_Scene = TScene();
    return &Instance().m_Scene;
}

TScene* TWorld::GetScene()
{
    return &Instance().m_Scene;
}