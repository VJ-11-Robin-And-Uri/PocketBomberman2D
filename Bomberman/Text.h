#pragma once

#include <string>
#include <glm/glm.hpp>

class Text
{
public:
	void render(const std::string& text, const glm::vec2& position);

private:
	std::string toUpperCase(const std::string& text);
};

