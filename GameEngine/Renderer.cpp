#include "Renderer.h"

void Renderer::draw_game(Context& context, sf::RenderWindow& window) {

	window.clear(sf::Color::Green);

	auto objects = context.get_object_snapshots();
	for (auto obj : objects) {
		if (textures.find(obj._picture_name) == textures.end()) {
			sf::Texture* texture = new sf::Texture();
			if (!texture->loadFromFile(obj._picture_name))
			{
				throw std::runtime_error("cant open player picture");
			}
			
			textures[obj._picture_name] = texture;
		}
		sf::Sprite sprite;
		sprite.setTexture(*textures[obj._picture_name]);
		sprite.setPosition(obj._coord.x, obj._coord.y);

		if (context.get_render_mode()) {

			if (obj._base_shape == "circle") {
				float size = sprite.getLocalBounds().width / 2.f;
				sf::CircleShape shape(size);
				shape.setFillColor(sf::Color::Blue);
				shape.setPosition(obj._coord.x, obj._coord.y);
				window.draw(shape);
			}
			else if (obj._base_shape == "rectangle") {
				float x = sprite.getLocalBounds().width / 2.f;
				float y = sprite.getLocalBounds().height / 2.f;

				sf::RectangleShape shape(sf::Vector2<float>(x, y));
				shape.setFillColor(sf::Color::Blue);
				shape.setPosition(obj._coord.x + x / 2, obj._coord.y + y / 2);
				window.draw(shape);
			}
		}
		window.draw(sprite);
		
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

Renderer::Renderer() {
};

Renderer::~Renderer() {
	for (auto& kvp : textures) {
		delete textures[kvp.first];
	}
};
