#include "Pch.h"
#include "Drawing.h"
#include "Globals.h"
#include "Camera.h"
#include "ActorEntity.h"
#include "Engine.h"
#include "PlayerEsp.h"
#include "ConfigUtilities.h"

std::shared_ptr<CheatFunction> UpdatePlayers = std::make_shared<CheatFunction>(10, [] {
	if (!EngineInstance.load())
		return;	
	EngineInstance.load()->UpdatePlayers();

	});

void DrawPlayerEsp()
{
	if (!EngineInstance.load())
		return;
	EngineInstance.load()->PlayersMutex.lock();
	std::vector<std::shared_ptr<ActorEntity>> players = EngineInstance.load()->GetPlayers();
	EngineInstance.load()->PlayersMutex.unlock();
	for (auto entity : players)
	{
		if (entity->GetPosition() == Vector3(0, 0, 0))
			continue;
		PlayerConfig config = Configs.Survivor;
	
		Vector2 screenpos = Camera::WorldToScreen(EngineInstance.load()->GetCameraCache().POV, entity->GetPosition());
		if (screenpos == Vector2::Zero())
			continue;
		Vector3 campos = Vector3(EngineInstance.load()->GetCameraCache().POV.Location.X, EngineInstance.load()->GetCameraCache().POV.Location.Y, EngineInstance.load()->GetCameraCache().POV.Location.Z);
		float distance = (Vector3::DistanceTo(campos,entity->GetPosition()) / 100.f) - 2;
		if (distance < 0)
			continue;
		std::wstring wdistance = config.Distance ? L"[" + std::to_wstring((int)distance) + L"m]" : L"";
		std::wstring name = config.Name ? entity->GetName() : L"";
		if (distance > config.MaxDistance)
			continue;
		DrawText(screenpos.x, screenpos.y, name + wdistance, "Verdana", config.FontSize, config.TextColour, CentreCentre);
		if (entity->GetEntityID() == Player || entity->GetEntityID() == Humanoid)
		{
			if (entity->GetHeadPosition() == Vector3(0, 0, 0))
				continue;
			Vector3 temphead = entity->GetHeadPosition();
			temphead.z += 15;
			Vector2 headscreenpos = Camera::WorldToScreen(EngineInstance.load()->GetCameraCache().POV, temphead);
			if (screenpos == Vector2::Zero())
				continue;
			float height = Vector2::Distance(screenpos, headscreenpos);
			float width = height / 2;
			OutlineRectangle(screenpos.x - (width/2), headscreenpos.y - 7, width, height, 2, Colour(0, 150, 255, 255));
		}
	}
	
}