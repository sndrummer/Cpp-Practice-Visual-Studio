#include "RendererFactory.h"


RendererFactory& RendererFactory::getInstance()
{
	static RendererFactory instance;
	return instance;
}


void RendererFactory::registerRenderer(const std::string& type, const CreateCallback cb)
{
	mRenderers[type] = cb;
}

//mRenderers[type] = renderer;
void RendererFactory::unregisterRenderer(const std::string& type)
{
	mRenderers.erase(type);
}

IRenderer* RendererFactory::createRenderer(const std::string& type)
{
	const auto it = mRenderers.find(type);

	if (it != mRenderers.end())
	{
		// call the creation callback
		return it->second();
	}
	return nullptr;
}
