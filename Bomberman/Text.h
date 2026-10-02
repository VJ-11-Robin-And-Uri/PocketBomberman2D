#pragma once

#include <string>
#include <glm/glm.hpp>
#include "Sprite.h"
#include "Texture.h"
#include "ShaderProgram.h"

// Draws text with the bitmap font in images/font.png: 8x8 cells, 16 columns x 14 rows,
// the character with code c is at index c - 32. Text is always drawn in uppercase.
// '\n' starts a new line. Only plain ASCII is supported (UTF-8 accents are not).

class Text
{
public:
	Text();
	~Text();

	bool init(ShaderProgram &program);

	void render(const std::string& text, const glm::vec2& position);

private:
	Text(const Text&);
	Text& operator=(const Text&);

	static std::string toUpperCase(const std::string& text);

private:
	Texture fontTexture;
	Sprite *sprite;
};

