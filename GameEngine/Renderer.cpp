#include "Renderer.h"

void Renderer::draw(Context& context, sf::RenderWindow& window) {
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

			window.clear(sf::Color::Black);
		
			window.draw(sprite);
			window.display();
		}
		
	}
};