#include "TScene.h"
#include "TObject.h"
#include "Input.h"

TScene::TScene()
{
    m_Identifier = GenerateIdentifier();
}

TScene::~TScene()
{
    delete activeCamera;

    for (TObject*& o : m_Objects)
    {
        o->BeginDestroy();
    }
}

const char* TScene::GenerateIdentifier()
{
    static const char chars[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    static char buffer[16];
    
    for (int i = 0; i < 15; ++i)
    {
        buffer[i] = chars[rand() % (sizeof(chars) - 1)];
    }

    buffer[15] = '\0';
    
    return buffer;
}

std::vector<TObject*>& TScene::GetObjects()
{
	return m_Objects;
}

bool TScene::RegisterObject(TObject* o)
{
	if (!o)
	{
		return false;
	}
	m_Objects.push_back(o);

	return true;
}

bool TScene::UnregisterObject(TObject* o)
{
    if (!o)
    {
        return false;
    }

    std::vector<TObject*>::iterator it = std::find(m_Objects.begin(), m_Objects.end(), o);
    if (it != m_Objects.end())
    {
        m_Objects.erase(it);
        return true;
    }

    return false;
}

const char* TScene::GetIdentifier()
{
    return m_Identifier;
}

TTileMap* TScene::InitTileMap(int w, int h)
{
    m_Tilemap = new TTileMap(w, h);
    return m_Tilemap;
}

TTileMap* TScene::GetTileMap()
{
    return m_Tilemap;
}

void TScene::DestroyTileMap()
{
    m_Tilemap->Cleanup();
    m_Tilemap->BeginDestroy();
}

void TScene::Init()
{
    //TObject::CreateObject<TEntity>()
}

void TScene::Update(float deltaTime)
{
    activeCamera->offset.x *= Input::lr * 40 * deltaTime;
    activeCamera->offset.y *= Input::ud * 40 * deltaTime;

    for (auto it = m_Objects.begin(); it != m_Objects.end();)
    {
        TObject* o = *it;
        if (o->bPendingDestroy)
        {
            o->Cleanup();
            it = m_Objects.erase(it);
            delete o;
            continue;
        }

        o->Update(deltaTime);
    }
}

void TScene::Render()
{
    BeginDrawing();

    for (TObject* o : m_Objects)
    {
        for (std::unique_ptr<TComponent>& c : *o->GetComponents())
        {
            c->Render();
        }
    }

    EndDrawing();
}
