#include "SpaceshipObject.h"
#include "Application.h"

Spaceship::Spaceship()
{
	m_ShootCooldownTimer = ShootCooldown;
	m_restrictMovement = true;
}

void Spaceship::update(double elapsedTime)
{
	GameObject::update(elapsedTime);
	m_ShootCooldownTimer += elapsedTime;
}

void Spaceship::TakeDamage(int damage)
{
	//Ouch!
}

void Spaceship::Shoot(Vector target)
{
	if (m_ShootCooldownTimer >= ShootCooldown)
	{
		m_ShootCooldownTimer = 0;

		Vector dir = target - m_position;
		dir.normalize();

		Bullet* bullet = new Bullet();
		bullet->setPos(m_position);
		bullet->setVelocity(dir * 1000);
		bullet->Owner = Application::getInstance().PlayerID;
		Application::getInstance().MyBulletList.push_back(bullet);

		Application::getInstance().sendShootCommand(1, dir);
	}	
}
