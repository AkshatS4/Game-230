#ifndef HCIRCLE_H
#define HCIRCLE_H


#include "GameObject.h"

namespace gm
{
	class HCircle : public GameObject
	{
	public:
		virtual void update(sf::RenderWindow& window);
	};
}



#endif