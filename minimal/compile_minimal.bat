@REM set cc65path="C:\Retro\DEV\cc65-snapshot-win32"
@REM set mypath="C:\Users\Brizio\Documents\GitHub\PortableChase\minimal"
@REM set configpath="C:\Users\Brizio\Documents\GitHub\PortableChase\minimal\experiments"

@REM 
set cc65path="D:\personal\cc65-snapshot-win32"
@REM 
set configpath="D:\Userfiles\fcaruso\Documents\GitHub\ASCII-CHASE\minimal\experiments"
@REM 
set mypath="d:\Userfiles\fcaruso\Documents\GitHub\ASCII-CHASE\minimal"


set Deliverables=%mypath%\deliverables

mkdir %deliverables% 2> NUL

del %deliverables%\*
del %mypath%\atmos\*.o
del %mypath%\c64\*.o
del %mypath%\patch\*.o

cd %cc65path%\bin\




@REM Atari 5200: Out of memory (fixable) - CONIO and joystick issues
@REM cl65.exe -O -t atari5200 -lib %cc65path%\lib\atari5200.lib %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\atari5200.a52

@REM Atari 2600: Out of memory  CONIO and joystick issues?
@REM cl65.exe -O -t atari2600 -lib %cc65path%\lib\atari2600.lib %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\atari2600.a26

@REM vic20-16k works on minimal build!
@REM 
cl65.exe -O -t vic20 -DVERY_SIMPLE_STRATEGY --config %mypath%\..\cfg\vic20-8k.cfg %mypath%\display_macros.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input_macros.c %mypath%\main.c  -o %deliverables%\MINIMAL_cvic20-8k.prg


cl65.exe -O -t c16 -DVERY_SIMPLE_STRATEGY --config %mypath%\..\cfg\c16-16k.cfg %mypath%\display_macros.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input_macros.c %mypath%\main.c  -o %deliverables%\MINIMAL_c16-16k.prg


@REM pce runs out of memory
@REM cl65.exe -O -t pce %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\pcengine.bin


@REM conio issues
@REM cl65.exe -O -t lynx  %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\lynx.bin


@REM conio issues + color unrecognized 
@REM cl65.exe -O -t supervision  %mypath%\display_macros.c %mypath%\powerUps.c %mypath%\enemy.c %mypath%\invincible_enemy.c %mypath%\level.c %mypath%\character.c %mypath%\text.c %mypath%\missile.c %mypath%\strategy.c %mypath%\input.c %mypath%\main.c  -o %deliverables%\supervision.bin




