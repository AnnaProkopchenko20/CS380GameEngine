#include "Renderer.h"

void Renderer::draw_game(Context& context, sf::RenderWindow& window) {
	window.clear(sf::Color::Green);
	auto objects = context.get_object_snapshots();
	for (auto obj : objects) {
		if (obj._type == ObjectType::Player) {
			sf::Texture texture;
			if (!texture.loadFromFile("shaun.png"))
			{
				throw std::runtime_error("cant open player picture");
			}
			sf::Sprite sprite;
			sprite.setTexture(texture);
			sprite.setPosition(obj._coord.x, obj._coord.y);

		
			window.draw(sprite);
		}
		
	}
	window.display();
};

void Renderer::draw_pause(sf::RenderWindow& window) {
	window.clear(sf::Color::Black);
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile(RendererSettings::pause_font_path))
	{
		throw std::runtime_error("cant open font");
	}
	text.setFont(font);

	text.setCharacterSize(RendererSettings::pause_font_size);

	text.setFillColor(RendererSettings::pause_colour);
	text.setString(RendererSettings::pause_message);
	window.draw(text);
	window.display();
}
