#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleRender.h"
#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_timer.h"
#include "ModuleInput.h"
#include "ModulePlayer.h"

bool gate = true;
Module* module_offBo;
Module* module_onBo;

ModuleFadeToBlack::ModuleFadeToBlack(){
	//screen = { 0, 0, SCREEN_WIDTH * SCREEN_SIZE, SCREEN_HEIGHT * SCREEN_SIZE };
}

ModuleFadeToBlack::~ModuleFadeToBlack(){}

bool ModuleFadeToBlack::Start(){
	bool ret = true;
	LOG("Preparing Fade Screen");
	return ret;
}

update_status ModuleFadeToBlack::Update() {
	if (current_step == fade_step::none)
		return UPDATE_CONTINUE;

	Uint32 now = SDL_GetTicks() - start_time;
	float normalized = MIN(1.0f, (float)now / (float)total_time);

	switch (current_step) {
	case fade_step::fade_to_black: {
		if (now >= total_time) {
			App->player->Disable();
			module_offBo->Disable();
			module_onBo->Enable();
			App->player->Enable();

			total_time += total_time;
			start_time = SDL_GetTicks();
			current_step = fade_step::fade_from_black;
		}
	} break;

	case fade_step::fade_from_black: {
		normalized = 1.0f - normalized;

		if (now >= total_time)
			current_step = fade_step::none;
	} break;
	}

	return UPDATE_CONTINUE;
}

bool ModuleFadeToBlack::FadeToBlack(Module* module_off, Module* module_on, float time) {
	bool ret = false;
	if (current_step == fade_step::none){
		module_onBo = module_on;
		module_offBo = module_off;
		current_step = fade_step::fade_to_black;
		start_time = SDL_GetTicks();
		total_time = (Uint32)(time * 0.5f * 1000.0f);
		ret = true;
	}
	return ret;
}