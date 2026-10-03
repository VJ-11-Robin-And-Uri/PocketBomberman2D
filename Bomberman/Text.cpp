#include "Text.h"

#define FONT_FILE "images/font.png"
#define GLYPH_SIZE 8
#define FONT_COLUMNS 16
#define FONT_ROWS 14
#define FIRST_CHAR 32

Text::Text()
{
	sprite = NULL;
}

Text::~Text()
{
	if (sprite != NULL)
		delete sprite;
}

bool Text::init(ShaderProgram &program)
{
	if (!fontTexture.loadFromFile(FONT_FILE, TEXTURE_PIXEL_FORMAT_RGBA))
		return false;
	fontTexture.setMinFilter(GL_NEAREST);
	fontTexture.setMagFilter(GL_NEAREST);
	sprite = Sprite::createSprite(glm::vec2(GLYPH_SIZE, GLYPH_SIZE), glm::vec2(1.f / FONT_COLUMNS, 1.f / FONT_ROWS), &fontTexture, &program);
	return true;
}

void Text::render(const std::string& text, const glm::vec2& position)
{
	if (sprite == NULL)
		return;

	glm::vec2 cursor = position;
	for (unsigned char c : text)
	{
		if (c == '\n')
		{
			cursor.x = position.x;
			cursor.y += GLYPH_SIZE;
			continue;
		}
		int index = c - FIRST_CHAR;
		if (index > 0 && index < FONT_COLUMNS * FONT_ROWS) // index 0 is the space: nothing to draw
		{
			sprite->setTexCoordDispl(glm::vec2(float(index % FONT_COLUMNS) / FONT_COLUMNS, float(index / FONT_COLUMNS) / FONT_ROWS));
			sprite->setPosition(cursor);
			sprite->render();
		}
		cursor.x += GLYPH_SIZE;
	}
}
