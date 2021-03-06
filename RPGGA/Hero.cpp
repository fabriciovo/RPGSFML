#include "Hero.h"



Hero::Hero()
{
}

Hero::Hero(float x, float y, std::string name, int hp, int power,int type, sf::Texture* texture)
{
	this->name = name;
	this->hp = hp;
	this->power = power;
	this->type = type;
	this->CreateSprite(texture);
	this->createAnimationComponent(*texture);
	this->SetPosition(x, y);
	this->selected = false;
	this->played = false;
	this->originalX = x;
	this->originalY = y;

	this->animationComponent->addAnimation("IDLE", 90.f, 0, 0, 1, 0, 18, 18);


}

Hero::Hero(std::string name, int hp, int power)
{
	this->selected = false;
	this->played = false;
	this->name = name;
	this->hp = hp;
	this->power = power;
}

Hero::Hero(Entity* hero)
{

	this->selected = false;
	this->played = false;
	this->name = hero->getName();
	this->hp = hero->getHp();
	this->power = hero->getPower();

}


Hero::~Hero()
{

}
void Hero::special(Entity *entity)
{
	this->spell = new Especial(this->type, entity);
	this->setPlayed(true);
}

void Hero::action(Entity * entity)
{
	std::cout << "HERO " << this->name << " ATTACK" << std::endl;
	entity->setDamage(this->power);
	this->setPlayed(true);
	this->setSelected(false);
}

Especial * Hero::getSpell()
{
	if (this->spell != nullptr) {
		return this->spell;
	}
	return nullptr;
}

void Hero::updateAnimation(const float & dt)
{

		this->animationComponent->play("IDLE", dt);
	
}



