#include "TScene.h"
#include "TObject.h"
TScene::TScene() = default;

std::vector<TObject*>& TScene::GetObjects()
{
	return Objects;
}

bool TScene::RegisterObject(TObject* o)
{
	if (!o)
	{
		return false;
	}
	Objects.push_back(o);

	return true;
}

bool TScene::UnregisterObject(TObject* o)
{
    if (!o)
    {
        return false;
    }

    std::vector<TObject*>::iterator it = std::find(Objects.begin(), Objects.end(), o);
    if (it != Objects.end())
    {
        Objects.erase(it);
        return true;
    }

    return false;
}

void TScene::Update(float deltaTime)
{
    for (TObject*& o : Objects)
    {
        o->Update(deltaTime);
    }
}

void TScene::Render()
{
    for (TObject*& o : Objects)
    {
        o->GetComponents();
    }
}
