#include "Entity.h"

void Entity::initVariables()
{
	this->texture = NULL;
	this->sprite = NULL;
	this->animationComponent = NULL;
	this->selected = false;
	this->played = false;
}

Entity::Entity()
{
	this->initVariables();
}


Entity::~Entity()
{


}

void Entity::CreateSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
	this->sprite->setTexture(*this->texture);
}

void Entity::createAnimationComponent(sf::Texture & texture_sheet)
{
	this->animationComponent = new AnimationComponent(*this->sprite, texture_sheet);
}

const bool & Entity::getSelected() const
{
	// TODO: inserir instru��o de retorno aqui
	return this->selected;
}

const bool& Entity::getPlayed() const
{
	return this->played;
}

void Entity::setDamage(int damage)
{
	this->hp -= damage;

}
void Entity::setHp(int hp)
{
	this->hp = hp;

}

void Entity::setPower(int power)
{
	this->power = power;
}

int Entity::getType()
{
	return this->type;
}

void Entity::SetPosition(const float x, const float y)
{
	if (this->sprite)
		this->sprite->setPosition(sf::Vector2f(x, y));
}

void Entity::SetScale(const float x, const float y)
{
	this->sprite->setScale(x, y);
}

void Entity::update(sf::Vector2f mousePos, const float &dt)
{
	if(this->hp > 0){
		if (this->sprite->getGlobalBounds().contains(mousePos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					this->selected = true;
			}
		}

		if (!this->sprite->getGlobalBounds().contains(mousePos)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				this->selected = false;

			}
		}

		if (selected){
			this->sprite->setColor(sf::Color::Yellow);
		}
		else {
			this->sprite->setColor(sf::Color::White);
		}
	} else{ 
		this->selected = false;
		this->sprite->setColor(sf::Color::Black);
	}
	if (this->hp <= 0) {
		this->selected = false;
	}
	

}


void Entity::render(sf::RenderTarget * target)
{
	if (this->sprite)
		target->draw(*this->sprite);
}

std::string Entity::getName()
{
	return this->name;
}

int Entity::getHp()
{
	return this->hp;
}

int Entity::getPower()
{
	return this->power;
}

void Entity::setPlayed(bool value)
{
	this->played = value;
}

void Entity::setSelected(bool value)
{
	this->selected = value;
	if (selected) {
		this->sprite->setColor(sf::Color::Yellow);
	}
	else {
		this->sprite->setColor(sf::Color::White);
	}
}


