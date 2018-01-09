/* --------------------------------------------------------------------------------------- */ 
// 
// CROSS CHASE by Fabrizio Caruso
//
// Fabrizio_Caruso@hotmail.com
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.

// Permission is granted to anyone to use this software for non-commercial applications, 
// subject to the following restrictions:

// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software in
// a product, an acknowledgment in the product documentation would be
// appreciated but is not required.

// 2. Altered source versions must be plainly marked as such, and must not
// be misrepresented as being the original software.

// 3. This notice may not be removed or altered from any source distribution.
/* --------------------------------------------------------------------------------------- */ 
 
#if !defined(TINY_GAME) 
 
#include "missile.h"
#include "settings.h"
#include "sound_macros.h"
#include "display_macros.h"
#include "level.h"
#include "text.h"
#include "character.h"

extern unsigned int points;
extern unsigned char ghostCount;
extern Character ghosts[GHOSTS_NUMBER];
extern Image DEAD_GHOST_IMAGE;
extern unsigned char level;

extern Item extraPoints;
extern Item freeze;
	
#if defined(FULL_GAME) 
	extern Item extraLife;
	extern Item invincibility;
	
	extern Character leftEnemyMissile;
	extern Character rightEnemyMissile;
	extern unsigned char bubbles_x[BUBBLES_NUMBER];
	extern Character bubbles[BUBBLES_NUMBER];
	extern unsigned char dead_bubbles;
	extern unsigned char missileBasesDestroyed;
#endif

void checkMissileVsGhost(Character * missilePtr,
						 Character * ghostPtr)
{
	if(ghostPtr->_status && 
	   areCharctersAtSamePosition(missilePtr, ghostPtr))
	{
		points+=GHOST_VS_MISSILE;
		ghostPtr->_imagePtr = (Image *)&DEAD_GHOST_IMAGE;
		ghostDies(ghostPtr);
	}
}
	
void checkMissileVsGhosts(Character * missilePtr)
{
	unsigned char i = 0;
	for(;i<GHOSTS_NUMBER;++i)
	{
		checkMissileVsGhost(missilePtr, &ghosts[i]);
	};
}
	
#if defined(FULL_GAME)
	void reducePowerUpsCoolDowns(void)
	{
		extraPoints._coolDown/=2;
		invincibility._coolDown/=2;
		freeze._coolDown/=2;
		TICK_SOUND();		
	}
#elif !defined(TINY_GAME)
	void reducePowerUpsCoolDowns(void)
	{
		extraPoints._coolDown/=2;
		freeze._coolDown/=2;		
		TICK_SOUND();		
	}
#else	
#endif	

void _moveMissile(Character *missilePtr, unsigned short missileDirection)
{
	DELETE_MISSILE(missilePtr->_x,missilePtr->_y,missilePtr->_imagePtr);
	switch(missileDirection)
	{
		case RIGHT:
			++missilePtr->_x;
		break;
		case DOWN:
			++missilePtr->_y;
		break;
		case UP:
			--missilePtr->_y;
		break;
		case LEFT:
			--missilePtr->_x;
		break;
	}	
}

unsigned char setMissileInitialPosition(Character *missilePtr, Character *playerPtr,
							  unsigned short missileDirection)
{
	missilePtr->_x = playerPtr->_x; 
	missilePtr->_y = playerPtr->_y;
	_moveMissile(missilePtr, missileDirection);
	if(wallReached(missilePtr))
	{
		die(missilePtr);
		DELETE_MISSILE(missilePtr->_x,missilePtr->_y,misslePtr->_imagePtr);
		#if defined(FULL_GAME)
			// TODO: Implement this
			DRAW_BROKEN_WALL(missilePtr->_x, missilePtr->_y);
		#endif
		return 0;
	}
	return 1;
}

#if defined(FULL_GAME)
	void destroyEnemyMissile(Character * enemyMissilePtr)
	{
		enemyMissilePtr->_status = 0;
		EXPLOSION_SOUND();
		DELETE_MISSILE(enemyMissilePtr->_x,enemyMissilePtr->_y,enemyMissilePtr->_imagePtr);
		points+=HORIZONTAL_MISSILE_BONUS;
		displayStats();				
		++missileBasesDestroyed;
		reducePowerUpsCoolDowns();		
	}
#endif

void moveMissile(Character * missilePtr, unsigned short missileDirection)
{
	_moveMissile(missilePtr, missileDirection);
	if(wallReached(missilePtr))
	{
		die(missilePtr);
		DELETE_MISSILE(missilePtr->_x,missilePtr->_y,misslePtr->_imagePtr);
		#if defined(FULL_GAME)
			DRAW_BROKEN_WALL(missilePtr->_x, missilePtr->_y);
			if(oneMissileLevel())
			{
				if(missilePtr->_x==XSize-1 && missilePtr->_y==YSize/2 && rightEnemyMissile._status)
				{
					destroyEnemyMissile(&rightEnemyMissile);
				}
			}				
			else if(missileLevel() || bossLevel())
			{
				if(missilePtr->_x==XSize-1 && missilePtr->_y==ENEMY_MISSILE_OFFSET && rightEnemyMissile._status)
				{
					destroyEnemyMissile(&rightEnemyMissile);	
				}
				else if(missilePtr->_x==0 && missilePtr->_y==YSize-1-ENEMY_MISSILE_OFFSET && leftEnemyMissile._status)
				{
					destroyEnemyMissile(&leftEnemyMissile);	
				}
			}
			if((rocketLevel() || bossLevel()) && missilePtr->_y==YSize-1)
			{
				unsigned char i;
				for(i=0;i<BUBBLES_NUMBER;++i)
				{
					if(missilePtr->_x==bubbles_x[i] && bubbles[i]._status)
					{
						bubbles[i]._status = 0;
						++dead_bubbles;
						EXPLOSION_SOUND();
						DELETE_MISSILE(bubbles[i]._x,bubbles[i]._y,bubbles[i]._imagePtr);
						DELETE_MISSILE(leftEnemyMissile._x,leftEnemyMissile._y,leftEnemyMissile._imagePtr);
						points+=VERTICAL_MISSILE_BONUS;
						displayStats();					
						if(dead_bubbles==BUBBLES_NUMBER)
						{
							reducePowerUpsCoolDowns();		
						}
					}
				}
			}			
		#endif		
	}
	else
	{
		DRAW_MISSILE(missilePtr->_x, missilePtr->_y, missilePtr->_imagePtr);
	}
}

#endif
