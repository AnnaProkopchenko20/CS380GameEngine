#include "Renderer.h"

void Renderer::draw_game(Context& context, sf::RenderWindow& window) {
	window.clear(sf::Color::Black);
	auto objects = context.get_object_snapshots();
	for (auto obj : objects) {
		if (obj._type == ObjectType::Player) {
			sf::Texture texture;
			if (!texture.loadFromFile("shaun.png"))
			{
				// error
			}
			sf::Sprite sprite;
			sprite.setTexture(texture);
			sprite.setPosition(obj._coord.x, obj._coord.y);

		
			window.draw(sprite);
		}
		
	}
	window.display();
};

void Renderer::draw_game_pause(sf::RenderWindow& window) {
	window.clear(sf::Color::Black);
	sf::Text text;
	text.setString("Game is paused");
	window.draw(text);
	window.display();
}
