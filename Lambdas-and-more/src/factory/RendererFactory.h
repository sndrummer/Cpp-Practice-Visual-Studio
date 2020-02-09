#pragma once
#include <map>
#include <string>
#include "IRenderer.h"

class RendererFactory
{
public:
	static RendererFactory& getInstance(); // make it a singleton

	// callback function constructor, function pointer remember function pointer is returnType (*NameOfFunction) (paramType1, paramType2);
	typedef IRenderer* (*CreateCallback)();
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
