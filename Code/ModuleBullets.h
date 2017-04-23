#ifndef __ModuleBullets_H__
#define __ModuleBullets_H__

#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleParticles.h"

class ModuleBullets : public Module {
public:
	ModuleBullets();
	~ModuleBullets();

	bool Start();
	bool Init();
	update_status Update();
	bool CleanUp();

public:
	int powerUpLevelPlayer1;
	int powerUpLevelPlayer2;
	bool bombOn = false;
	int current_time;

};
#endif
