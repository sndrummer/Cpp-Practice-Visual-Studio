#include "RendererFactory.h"


RendererFactory& RendererFactory::getInstance()
{
	static RendererFactory factory;
	return factory;
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
	auto it = mRenderers.find(type);

	if (it != mRenderers.end())
	{
		// call the creation callback
		return it->second();
	}
}