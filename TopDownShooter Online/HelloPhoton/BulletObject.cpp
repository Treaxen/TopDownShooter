#include "BulletObject.h"
#include "Application.h"
#include <algorithm>

Bullet::Bullet()
{
	if (Application::getInstance().BulletSprite != nullptr)
	{
		this->m_sprite = Application::getInstance().BulletSprite;
	}

	IsAlive = true;
	m_scale = Vector(0.1, 0.1, 0.1);
	Life = 3.0f;
}

void Bullet::update(double elapsedTime)
{
	GameObject::update(elapsedTime);

	Life -= elapsedTime;

	if (Life <= 0)
	{
		IsAlive = false;
	}
	else
	{
		float distance = (m_position - Application::getInstance().EnemySpaceship.getPos()).length();

		//Check for collision with ships
		if ((this->m_position - Application::getInstance().EnemySpaceship.getPos()).length() <= 25.0f)
		{
			//If it's this player's bullet
			if (Owner == Application::getInstance().PlayerID)
			{
				std::cout << "Enemy Hit!" << std::endl;
				Application::getInstance().EnemySpaceship.TakeDamage(1);
				IsAlive = false;

				//Only P1 should send damage notify
				if (Application::getInstance().PlayerID == 1)
				{
					Application::getInstance().sendDamageNotify(2, 1);
				}
			}
		}
		else if ((this->m_position - Application::getInstance().MySpaceship.getPos()).length() <= 25.0f)
		{
			//If it's this enemy's bullet
			if (Owner != Application::getInstance().PlayerID)
			{
				std::cout << "I am Hit!" << std::endl;
				Application::getInstance().EnemySpaceship.TakeDamage(1);
				IsAlive = false;

				//Only p1 should send damage notify
				if (Application::getInstance().PlayerID == 1)
				{
					Application::getInstance().sendDamageNotify(1, 1);
				}

			}
		}
	}
	
}
