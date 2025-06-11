#include "TObject.h"
#include "TScene.h"

/// <summary>
/// Handles updates, by default will update components
/// </summary>
/// <param name="deltaTime"></param>
void TObject::Update(float deltaTime)
{
	for (std::unique_ptr<TComponent>& c : m_Components)
	{
		c->Update(deltaTime);
		if (c->CanRender())
		{
			c->Render();
		}
	}
}