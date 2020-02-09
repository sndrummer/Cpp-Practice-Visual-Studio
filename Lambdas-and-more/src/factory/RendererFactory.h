#pragma once
#include <map>
#include <string>
#include "IRenderer.h"

class RendererFactory
{
public:
	static RendererFactory& getInstance(); // make it a singleton

	typedef IRenderer* (*CreateCallback)(); // callback function constructor  
	void registerRenderer(const std::string& type, CreateCallback cb);
	void unregisterRenderer(const std::string& type);
	IRenderer* createRenderer(const std::string& type);


private:
	// Make a singleton
	RendererFactory() = default;
	~RendererFactory() = default;

	typedef std::map<std::string, CreateCallback> RendererMap;
	RendererMap mRenderers;
};
