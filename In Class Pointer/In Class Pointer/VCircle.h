#ifndef VCIRCLE_H
#define VCIRCLE_H


#include "GameObject.h"

namespace gm 
{
	class VCircle : public GameObject
	{
	public:
		virtual void update(sf::RenderWindow& window);
	};
}



#endif