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

#if !defined(_SETTINGS)
#define _SETTINGS

#include <stdlib.h>

#define C64_HARDWARE_SPRITES 0
#define C64_REDEFINED_CHARACTERS 0

#if defined(__VIC20__)
	#define SLOW_DOWN
	#define GAME_SLOW_DOWN 600
#elif defined(__C16__) || ((defined(__ATARI__) || defined(__ATARIXL__)) && defined(ATARI_MODE1)) || defined(__APPLE2__) || defined(__APPLE2ENH__)
	#define SLOW_DOWN
	#define GAME_SLOW_DOWN 250
#else
	#define GAME_SLOW_DOWN 0
#endif

#define FAST_NONEXACT_COLLISION_DECTION

#if defined(__C16__)
	#define BOMBS_NUMBER 3
#else
	#define BOMBS_NUMBER 3
#endif
	
// Possible current values are 6,7,8

#if defined(__C16__)
	#define GHOSTS_NUMBER 8
#else
	#define GHOSTS_NUMBER 8
#endif
	
#define BUBBLES_NUMBER 2


#define LIVES_NUMBER 5
#define GUNS_NUMBER 3

#define BACKGROUND_COLOR COLOR_BLACK
#define BORDER_COLOR COLOR_BLACK

#define TEXT_COLOR COLOR_WHITE

#define GHOST_VS_GHOST_COLLISION_LEVEL 16
#define GHOST_VS_GHOST_COLLISION_START 200

#define EXTRA_LIFE_THROUGH_POINTS 2000UL


#define INVINCIBILITY_FIRST_LEVEL 5

#define EXTRA_LIFE_FIRST_LEVEL 10

#if defined(DEBUG_CRASH)
	#define MIN_INVINCIBLE_GHOST_HITS 1
#else
	#define MIN_INVINCIBLE_GHOST_HITS 5
#endif
	
#define INVINCIBLE_GHOST_POINTS 5000UL;


// If two or more ghosts bump into eachother for each ghost
#define GHOST_VS_GHOST_BONUS 50UL

// If a ghost bumps into a bomb
#define GHOST_VS_BOMBS_BONUS 25UL

// Points for shooting a ghost
#define GHOST_VS_MISSILE 10UL

// Extra points for the power up
#define POWER_UP_BONUS 20UL

// Extra points for the power up
#define GUN_BONUS 30UL

// Points for each tick
#define LOOP_POINTS 1UL

// Points gained at the end of each level (to be multipled by level)
#define LEVEL_BONUS 50UL

#if defined(__C16__) || defined(__VIC20__) || ((defined(__ATARI__) || defined(__ATARIXL__)) && defined(ATARI_MODE1)) || defined(__APPLE2__) || defined(__APPLE2ENH__)
	#define INITIAL_ENEMY_SLOWDOWN 31500
	#define INITIAL_SKULL_SLOWDOWN 32500	
#else
	#define INITIAL_ENEMY_SLOWDOWN 28000
	#define INITIAL_SKULL_SLOWDOWN 29000
#endif

// MINE DISTRIBUTION
// LEVEL  1 -  5: Four central bombs
// LEVEL  6 - 10: Three central bombs
// LEVEL 11 - 15: Two central bombs
// LEVEL 16 - 20: One central bomb
// LEVEL 21 - 25: Two bombs next to the vertical borders
// LEVEL 26 - 30: Two bombs next to the lower corners
// LEVEL 31 - 35: Two bombs attached to the vertical borders
// LEVEL 36 - 40: Four bombs at the four corners 

// Starting from this level 4 central bombs
#if defined(DEBUG_CRASH)
	#define INITIAL_LEVEL 5
#else
	#define INITIAL_LEVEL 1
#endif

#define THREE_BOMB_START_LEVEL 6

// Starting from this level only two central bombs
#define TWO_BOMB_START_LEVEL 11

#define ONE_BOMB_START_LEVEL 16

// Starting from this level only 2 bombs close to the vertical borders
#define FIRST_HARD_LEVEL 21

// Starting from this level 2 bombs close to the botton corners
#define FIRST_VERY_HARD_LEVEL 26

// Starting from this level only 2 bombs on the vertical borders
#define FIRST_INSANE_LEVEL 31

// Ultimate level (four bombs at the corners)
#define FIRST_ULTIMATE_LEVEL 36

// Final level 
#define FINAL_LEVEL 40

#define FIRST_BUBBLES_LEVEL 7 // 8 because of check on levels after missile level

// Maximum number of ghost that co-exist with rockets (in non-boss levels)
#define MAX_GHOST_COUNT_FOR_BUBBLES 4

// Directions
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

#define INVINCIBLE_GHOST_TRIGGER 2

#define GUN_INITIAL_COOLDOWN (180 + level * 2)

#endif // _SETTINGS
