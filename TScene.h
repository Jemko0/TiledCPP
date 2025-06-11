#pragma once

#include "Engine.h"
#include "IRenderableAsset.h"

FORWARD_DECLARE(TObject);

class ENGINE_API TScene : public IRenderableAsset
{
public:
    std::vector<TObject*>& GetObjects();

    bool RegisterObject(TObject* o);
    bool UnregisterObject(TObject* o);

    void Update(float deltaTime);
    void Render() override;

    TScene();
    ~TScene() = default;

private:
    std::vector<TObject*> Objects;
};