/*****************************************************************************/
/*                                                                           */
/*                                		                                     */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 2017      Fabrizio Caruso                                  		     */
/*                					                                         */
/*              				                                             */
/* EMail:        Fabrizio_Caruso@hotmail.com                                 */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/
 
#include "character.h"
#include "settings.h"

#include <stdlib.h>

#include "display_macros.h"
#include "sound_macros.h" 
#include "sleep_macros.h"

#include "level.h"

extern unsigned char level;
extern unsigned char XSize;
extern unsigned char YSize;

extern Image PLAYER_IMAGE;
extern Image GHOST_IMAGE;
extern Image DEAD_GHOST_IMAGE;
extern Image INVINCIBLE_GHOST_IMAGE;
extern Image BOMB_IMAGE;
extern Image POWERUP_IMAGE;
extern Image MISSILE_IMAGE;
extern Image GUN_IMAGE;
extern Image BUBBLE_IMAGE;

extern Character invincibleGhost;
extern Character player; 
extern Character powerUp;
extern Character gun;
extern Character missile;


extern Character ghosts[GHOSTS_NUMBER];
extern Character bombs[BOMBS_NUMBER];

void fillLevelWithCharacters(unsigned char nGhosts)
{

	unsigned char i;
	unsigned char j;
	unsigned char count = 0;
	
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			if(!((i==1) && (j==1)))
			{
				if(nGhosts>count)
				{
					initializeCharacter(&ghosts[count],XSize/6+j*2*(XSize/6),YSize/6+i*2*(YSize/6),1,&GHOST_IMAGE);
				}
				else
				{
					initializeCharacter(&ghosts[count],8-count,1,0,&DEAD_GHOST_IMAGE);
				}
				++count;
			}
		}
	}

	// unsigned char ghost_x[GHOSTS_NUMBER];
	// unsigned char ghost_y[GHOSTS_NUMBER];
	
	// ghost_x[0] = XSize-XSize/6+rand()%2-1;
	// ghost_y[0] = YSize-YSize/6+rand()%2-1;
	
	// ghost_x[1] = XSize/6+rand()%2-1;
	// ghost_y[1] = YSize/6+rand()%2-1+3;
	
	// ghost_x[2] = XSize/6+rand()%2-1;
	// ghost_y[2] = YSize/2+rand()%2-1;
	
	// ghost_x[3] = XSize/6+rand()%2-1;
	// ghost_y[3] = YSize-YSize/6+rand()%2-1;
	
	// ghost_x[4] = XSize/2+rand()%2-1;
	// ghost_y[4] = YSize/6+rand()%2-1+3;
	
	// #if GHOSTS_NUMBER>=6
		// ghost_x[5] = XSize/2+rand()%2-1;
		// ghost_y[5] = YSize-YSize/6+rand()%2-1;
	// #elif GHOSTS_NUMBER>=7
		// ghost_x[6] = XSize-XSize/6+rand()%2-1;
		// ghost_y[6] = YSize/6+rand()%2-1+3;
	// #else
		// ghost_x[7] = XSize-XSize/6+rand()%2-1;
		// ghost_y[7] = YSize/2+rand()%2-1;
    // #endif

	// for(i=0;i<GHOSTS_NUMBER;++i)
	// {
		// if(nGhosts>i)
		// {
			// initializeCharacter(&ghosts[i],ghost_x[i],ghost_y[i],1,&GHOST_IMAGE);
		// }
		// else
		// {
			// initializeCharacter(&ghosts[i],8-i,1,0,&DEAD_GHOST_IMAGE);			
		// }
	// }
	
	
	
	// initializeCharacter(&ghosts[0],XSize-XSize/6+rand()%3-3,YSize-YSize/6+rand()%3-3,1,&GHOST_IMAGE);

	// #if GHOSTS_NUMBER>= 2	
	// if(nGhosts>1)
	// {
		// initializeCharacter(&ghosts[1],XSize/6+rand()%3-1,YSize/6+rand()%3-2+1,1,&GHOST_IMAGE);
	// }
	// else
	// {
		// initializeCharacter(&ghosts[1],7,1,0,&DEAD_GHOST_IMAGE);
	// }
	// #endif
	
	// #if GHOSTS_NUMBER>= 3	
	// if(nGhosts>2)
	// {
		// initializeCharacter(&ghosts[2],XSize/6+rand()%3-1,YSize/2+rand()%3-2,1, &GHOST_IMAGE);
	// }
	// else
	// {
		// initializeCharacter(&ghosts[2],6,1,0, &DEAD_GHOST_IMAGE);
	// }
	// #endif
	
	// #if GHOSTS_NUMBER>= 4
	// if(nGhosts>3)
	// {
		// initializeCharacter(&ghosts[3],XSize/6+rand()%3-1,YSize-YSize/6+rand()%3-3,1,&GHOST_IMAGE);
	// }
	// else
	// {
		// initializeCharacter(&ghosts[3],5,1,0,&DEAD_GHOST_IMAGE);
	// }
	// #endif
	
	// #if GHOSTS_NUMBER>= 5
	// if(nGhosts>4)
	// {
		// initializeCharacter(&ghosts[4],XSize/2+rand()%3-1,YSize/6+rand()%3-2+1,1,&GHOST_IMAGE);
	// }
	// else
	// {
		// initializeCharacter(&ghosts[4],4,1,0,&DEAD_GHOST_IMAGE);	
	// }
	// #endif
	
	// #if GHOSTS_NUMBER>= 6
	// if(nGhosts>5)
	// {
		// initializeCharacter(&ghosts[5],XSize/2+rand()%3-1,YSize-YSize/6+rand()%3-3,1,&GHOST_IMAGE);
	// }
	// else
	// {
		// initializeCharacter(&ghosts[5],3,1,0,&DEAD_GHOST_IMAGE);	
	// }
	// #endif

	// #if GHOSTS_NUMBER>=7
	// if(nGhosts>6)
	// {
		// initializeCharacter(&ghosts[6],XSize-XSize/6+rand()%3-3,YSize/6+rand()%3-2+1,1,&GHOST_IMAGE);
	// }
	// else
	// {
		// initializeCharacter(&ghosts[6],2,1,0,&DEAD_GHOST_IMAGE);	
	// }
	// #endif
	
	// #if GHOSTS_NUMBER==8
	// if(nGhosts>7)
	// {
		// initializeCharacter(&ghosts[7],XSize-XSize/6+rand()%3-3,YSize/2+rand()%3-2,1,&GHOST_IMAGE);
	// }
	// else
	// {
		// initializeCharacter(&ghosts[7],1,1,0,&DEAD_GHOST_IMAGE);	
	// }
	// #endif
	
	
	
	
	
	initializeCharacter(&player,XSize/2+rand()%4-2,YSize/2+rand()%4-2,1,&PLAYER_IMAGE);

	DRAW_PLAYER(player._x,player._y,player._imagePtr);

	
	
	#if BOMBS_NUMBER==3	
		initializeCharacter(&bombs[0],XSize/3-2+rand()%5, ((YSize/3))-1+rand()%3,0,&BOMB_IMAGE);

		initializeCharacter(&bombs[1],XSize/3-2+rand()%5, ((YSize/3)*2)-1+rand()%3,0,&BOMB_IMAGE);

		initializeCharacter(&bombs[2],2*(XSize/3)-2+rand()%5, (YSize/2)-1+rand()%3,0,&BOMB_IMAGE);
	#elif BOMBS_NUMBER==2
		initializeCharacter(&bombs[0],XSize/2-3+rand()%7, ((YSize/3))-1+rand()%3,0,&BOMB_IMAGE);

		initializeCharacter(&bombs[1],XSize/2-3+rand()%7, ((YSize/3)*2)-1+rand()%3,0,&BOMB_IMAGE);	
	#endif

	for(i=0;i<BOMBS_NUMBER;++i)
	{
		DRAW_BOMB(bombs[i]._x, bombs[i]._y, bombs[i]._imagePtr);
	}


	initializeCharacter(&powerUp,XSize/2,YSize/2,1,&POWERUP_IMAGE);
	//DRAW_POWERUP(powerUp._x, powerUp._y, powerUp._imagePtr);
		
	initializeCharacter(&missile, 0, 0,0,&MISSILE_IMAGE);
	

	initializeCharacter(&gun,XSize/2, YSize/2, 0, &GUN_IMAGE);

	// invincibleGhost._x = (unsigned char) XSize-2;
	// invincibleGhost._y = (unsigned char) YSize-2;
			
	initializeCharacter(&invincibleGhost,XSize-2,YSize-2, 0, &INVINCIBLE_GHOST_IMAGE);

}

