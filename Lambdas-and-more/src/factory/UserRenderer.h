#pragma once
#include "IRenderer.h"

class UserRenderer : public IRenderer
{
public:
	void render() override;
};
