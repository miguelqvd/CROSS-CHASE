
#include "settings.h"

#include "move_player.h"

#include "character.h"
#include "skull.h"

#include "definitions.h"


extern Character player;

#if !defined(TINY_GAME)
	extern uint8_t skullXCountDown;
	extern uint8_t skullYCountDown;
	extern uint8_t playerFire;
	extern Character bullet;
	extern uint8_t guns;
	extern uint8_t playerDirection;
#endif

#if defined(FULL_GAME)
	extern uint8_t player_invincibility;
	extern uint8_t playerBlink;	
#endif

#if !defined(TINY_GAME) 
	#if !defined(ALT_MOVE)
		#define _DO_MOVE_UP \
			deletePlayer(&player); \
			--player._y; \
			SHOW_UP(); \
			skullYCountDown = SKULL_COUNT_DOWN; \
			playerDirection = UP;
		#define _DO_MOVE_DOWN \
			deletePlayer(&player); \
			++player._y; \
			SHOW_DOWN(); \
			skullYCountDown = SKULL_COUNT_DOWN; \
			playerDirection = DOWN;
		#define _DO_MOVE_LEFT \
			deletePlayer(&player); \
			--player._x; \
			SHOW_LEFT(); \
			skullXCountDown = SKULL_COUNT_DOWN; \
			playerDirection = LEFT;
		#define _DO_MOVE_RIGHT \
			deletePlayer(&player); \
			++player._x; \
			SHOW_RIGHT(); \
			skullXCountDown = SKULL_COUNT_DOWN; \
			playerDirection = RIGHT;
	#else
		#define _DO_MOVE_UP \
			--player._y; \
			SHOW_UP(); \
			skullYCountDown = SKULL_COUNT_DOWN; \
			playerDirection = UP;
		#define _DO_MOVE_DOWN \
			++player._y; \
			SHOW_DOWN(); \
			skullYCountDown = SKULL_COUNT_DOWN; \
			playerDirection = DOWN;	
		#define _DO_MOVE_LEFT \
			--player._x; \
			SHOW_LEFT(); \
			skullXCountDown = SKULL_COUNT_DOWN; \
			playerDirection = LEFT;
		 
		#define _DO_MOVE_RIGHT \
			++player._x; \
			SHOW_RIGHT(); \
			skullXCountDown = SKULL_COUNT_DOWN; \
			playerDirection = RIGHT;
	#endif
#else
	#if !defined(ALT_MOVE)
		#define _DO_MOVE_UP \
			deletePlayer(&player); \
			--player._y; \
			SHOW_UP();
			
		#define _DO_MOVE_DOWN \
			deletePlayer(&player); \
			++player._y; \
			SHOW_DOWN();
			
		#define _DO_MOVE_LEFT \
			deletePlayer(&player); \
			--player._x; \
			SHOW_LEFT();
			
		#define _DO_MOVE_RIGHT \
			deletePlayer(&player); \
			++player._x; \
			SHOW_RIGHT();
	#else
		#define _DO_MOVE_UP \
			--player._y; \
			SHOW_UP();
			
		#define _DO_MOVE_DOWN \
			++player._y; \
			SHOW_DOWN();
			
		#define _DO_MOVE_LEFT \
			--player._x; \
			SHOW_LEFT();
			
		#define _DO_MOVE_RIGHT \
			++player._x; \
			SHOW_RIGHT();		
	#endif
#endif



#if defined(JOYSTICK_CONTROL)
	#if defined(Z88DK_JOYSTICK)
		#include <games.h>
		
		void movePlayerByJoystick(uint8_t joyInput)
		{
			if(joyInput & MOVE_UP)
			{
				_DO_MOVE_UP
			}
			else if(joyInput & MOVE_DOWN)
			{
				_DO_MOVE_DOWN
			}
			else if(joyInput & MOVE_LEFT)
			{
				_DO_MOVE_LEFT
			}
			else if(joyInput & MOVE_RIGHT)
			{
				_DO_MOVE_RIGHT
			}
			#if !defined(TINY_GAME)
			else if(joyInput & MOVE_FIRE && guns>0 && !bullet._status)
			{
				playerFire = 1;
			}
			#endif
		}	
	#elif defined(__SMS__)
	// TODO: BOGUS - IMPLEMENT THIS!
		#include <arch/sms/SMSLib.h>
		
		void movePlayerByJoystick(uint8_t joyInput)
		{
			if(joyInput & PORT_A_KEY_UP)
			{
				_DO_MOVE_UP
			}
			else if(joyInput & PORT_A_KEY_DOWN)
			{
				_DO_MOVE_DOWN
			}
			else if(joyInput & PORT_A_KEY_LEFT)
			{
				_DO_MOVE_LEFT
			}
			else if(joyInput & PORT_A_KEY_RIGHT)
			{
				_DO_MOVE_RIGHT
			}
			#if !defined(TINY_GAME)
			else if(joyInput & PORT_A_KEY_1 && guns>0 && !bullet._status)
			{
				playerFire = 1;
			}
			#endif			
		}
	#else
		#include <joystick.h>
		
		void movePlayerByJoystick(uint8_t joyInput)
		{
			if(JOY_UP(joyInput))
			{
				_DO_MOVE_UP
			}
			else if(JOY_DOWN(joyInput))
			{
				_DO_MOVE_DOWN
			}
			else if(JOY_LEFT(joyInput))
			{
				_DO_MOVE_LEFT
			}
			else if(JOY_RIGHT(joyInput))
			{
				_DO_MOVE_RIGHT
			}
			#if !defined(TINY_GAME)
			else if(JOY_BTN_1(joyInput) && guns>0 && !bullet._status)
			{
				playerFire = 1;
			}
			#endif
		}	
	#endif
#else
	void movePlayerByKeyboard(uint8_t kbInput)
	{
		#if defined(ALT_MOVE)
			deletePlayer(&player);
		#endif
		if(kbInput==_MOVE_UP)
		{
			_DO_MOVE_UP
		}
		else if(kbInput==_MOVE_DOWN)
		{
			_DO_MOVE_DOWN
		}
		else if(kbInput==_MOVE_LEFT)
		{
			_DO_MOVE_LEFT
		}
		else if(kbInput==_MOVE_RIGHT)
		{
			_DO_MOVE_RIGHT
		}
		#if !defined(TINY_GAME)
		else if(kbInput==_FIRE && guns>0 && !bullet._status)
		{
			playerFire = 1;
		}
		#endif
	}
#endif

	
#if defined(NO_INPUT)
	void MOVE_PLAYER(void) {}
#elif defined(KEYBOARD_CONTROL)
	void MOVE_PLAYER(void) 
	{ 
		#if defined(ALT_MOVE)
			if(kbhit())
			{
		#endif
				movePlayerByKeyboard(GET_CHAR()); 
		#if defined(ALT_MOVE)
			}
		#endif
	}
#else
	
	#if defined(Z88DK_JOYSTICK)
		extern uint8_t stick;
		
		#define JOY_INPUT() joystick(stick)
	#elif defined(__SMS__)
		#include <arch/sms/SMSLib.h>
		
		#define JOY_INPUT() (SMS_getKeysStatus() & 0xFF)
	#else
		#define JOY_INPUT() joy_read(JOY_1)
	#endif	

	#if defined(TURN_BASED)
		void MOVE_PLAYER(void) 
		{ 
			uint8_t joyInput; 
			while(!(joyInput=JOY_INPUT())) 
			{ 
			}; 
			movePlayerByJoystick(joyInput); 
		}	
	#else
		void MOVE_PLAYER(void) { movePlayerByJoystick(JOY_INPUT()); }
	#endif
#endif


