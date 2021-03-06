#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModuleCollision::ModuleCollision() {
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

	matrix[COLLIDER_NONE][COLLIDER_OBJECT_NO_COLLISION] = false;
	matrix[COLLIDER_NONE][COLLIDER_NONE] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_NONE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_NONE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_NONE][COLLIDER_OBJECT_COLLISION] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER2_SHOT] = false;

	matrix[COLLIDER_OBJECT_NO_COLLISION][COLLIDER_OBJECT_NO_COLLISION] = false;
	matrix[COLLIDER_OBJECT_NO_COLLISION][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_OBJECT_NO_COLLISION][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_OBJECT_NO_COLLISION][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_OBJECT_NO_COLLISION][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_OBJECT_NO_COLLISION][COLLIDER_OBJECT_COLLISION] = false;
	matrix[COLLIDER_OBJECT_NO_COLLISION][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_OBJECT_NO_COLLISION][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_OBJECT_NO_COLLISION][COLLIDER_NONE] = false;

	matrix[COLLIDER_PLAYER][COLLIDER_OBJECT_NO_COLLISION] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_OBJECT_COLLISION] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_NONE] = false;

	matrix[COLLIDER_ENEMY][COLLIDER_OBJECT_NO_COLLISION] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_OBJECT_COLLISION] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER2_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_NONE] = false;

	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_OBJECT_NO_COLLISION] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_OBJECT_COLLISION] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_NONE] = false;

	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_OBJECT_NO_COLLISION] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_OBJECT_COLLISION] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_NONE] = false;

	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_OBJECT_NO_COLLISION] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_OBJECT_COLLISION] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER2] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_NONE] = false;

	matrix[COLLIDER_OBJECT_COLLISION][COLLIDER_OBJECT_NO_COLLISION] = false;
	matrix[COLLIDER_OBJECT_COLLISION][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_OBJECT_COLLISION][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_OBJECT_COLLISION][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_OBJECT_COLLISION][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_OBJECT_COLLISION][COLLIDER_OBJECT_COLLISION] = false;
	matrix[COLLIDER_OBJECT_COLLISION][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_OBJECT_COLLISION][COLLIDER_PLAYER2_SHOT] = true;
	matrix[COLLIDER_OBJECT_COLLISION][COLLIDER_NONE] = true;

	matrix[COLLIDER_PLAYER2][COLLIDER_OBJECT_NO_COLLISION] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER2][COLLIDER_OBJECT_COLLISION] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER2] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER2][COLLIDER_NONE] = false;

}

ModuleCollision::~ModuleCollision() {}

update_status ModuleCollision::PreUpdate() {
	for (uint i = 0; i < MAX_COLLIDERS; ++i) {
		if (colliders[i] != nullptr && colliders[i]->to_delete == true) {
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return UPDATE_CONTINUE;
}

update_status ModuleCollision::Update() {
	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i) {
		if (colliders[i] == nullptr)
			continue;
		c1 = colliders[i];
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k) {
			if (colliders[k] == nullptr)
				continue;
			c2 = colliders[k];
			if (c1->CheckCollision(c2->rect) == true) {
				if (matrix[c1->type][c2->type] && c1->callback)
					c1->callback->OnCollision(c1, c2);
				if (IsEnabled() == true)
					if (matrix[c2->type][c1->type] && c2->callback)
						c2->callback->OnCollision(c2, c1);
			}
		}
	}
	DebugDraw();
	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw() {
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN) {
		debug = !debug;
	}
	if (debug == false)
		return;

	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i) {
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type) {
		case COLLIDER_NONE:
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_OBJECT_NO_COLLISION:
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_OBJECT_COLLISION:
			App->render->DrawQuad(colliders[i]->rect, 255, 200, 0, alpha);
			break;
		case COLLIDER_PLAYER:
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case COLLIDER_PLAYER2:
			App->render->DrawQuad(colliders[i]->rect, 0, 200, 0, alpha);
			break;
		case COLLIDER_ENEMY:
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case COLLIDER_PLAYER_SHOT:
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case COLLIDER_ENEMY_SHOT:
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		}
	}
}

bool ModuleCollision::CleanUp() {
	LOG("Freeing all colliders");
	for (uint i = 0; i < MAX_COLLIDERS; ++i) {
		if (colliders[i] != nullptr && colliders[i]->to_delete == true) {
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	for (uint i = 0; i < MAX_COLLIDERS; ++i) {
		if (colliders[i] != nullptr) {
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}
	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback) {
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i) {
		if (colliders[i] == nullptr) {
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}
	return ret;
}

bool Collider::CheckCollision(const SDL_Rect& r) const {
	return (rect.x < r.x + r.w &&
		rect.x + rect.w > r.x &&
		rect.y < r.y + r.h &&
		rect.h + rect.y > r.y);
}