#include "Pch.h"
#include "ActorEntity.h"
#include "Camera.h"
#include "Globals.h"

inline std::unordered_map<EntityType, std::wstring> EntityIDNames = {
		{EntityType::Imp,LIT(L"Imp")},
		{EntityType::Kappa,LIT(L"Kappa")},
		{EntityType::Humanoid,LIT(L"Humanoid")},
		{EntityType::Corpse,LIT(L"Corpse")},
		{EntityType::Rabbit,LIT(L"Rabbit")},
		{EntityType::DialogNPC,LIT(L"DialogNPC")},
		{EntityType::Hyena,LIT(L"Hyena")},
		{EntityType::Vulture,LIT(L"Vulture")},
		{EntityType::Furnace,LIT(L"Furnace")},
		{EntityType::Armorer,LIT(L"Armorer")},
		{EntityType::MetalSmith,LIT(L"MetalSmith")},
		{EntityType::LandClaim,LIT(L"LandClaim")},
		{EntityType::Foundation,LIT(L"Foundation")},
		{EntityType::Tanner,LIT(L"Tanner")},
		{EntityType::Gazelle,LIT(L"Gazelle")},
		{EntityType::Bedroll,LIT(L"Bedroll")},
		{EntityType::Alchemist,LIT(L"Alchemist")},
		{EntityType::Rocknose,LIT(L"Rocknose")},
		{EntityType::Ostrich,LIT(L"Ostrich")},
		{EntityType::Kudo,LIT(L"Kudo")},
		{EntityType::Fawn,LIT(L"Fawn")},
		{EntityType::HyenaBoss,LIT(L"HyenaBoss")},
		{EntityType::Spider,LIT(L"Spider")},
		{EntityType::Slamander,LIT(L"Slamander")},
		{EntityType::Scorpion,LIT(L"Scorpion")},
		{EntityType::ScorpionBoss,LIT(L"ScorpionBoss")},
		{EntityType::Snake,LIT(L"Snake")},
		{EntityType::Antilope,LIT(L"Antilope")},
		{EntityType::RhinoKing,LIT(L"RhinoKing")},
		{EntityType::Rhino,LIT(L"Rhino")},
		{EntityType::RockNoseBoss,LIT(L"RockNoseBoss")},
		{EntityType::Locust,LIT(L"Locust")},
		{EntityType::Jaguar,LIT(L"Jaguar")},
		{EntityType::Tiger,LIT(L"Tiger")},
		{EntityType::Wight,LIT(L"Wight")},
		{EntityType::Wolf,LIT(L"Wolf")},
		{EntityType::Crocodile,LIT(L"Crocodile")},
		{EntityType::SnakeBoss,LIT(L"SnakeBoss")},
		{EntityType::Player,LIT(L"Player")}

};

ActorEntity::ActorEntity(uint64_t address,std::string name,VMMDLL_SCATTER_HANDLE handle)
{
	Class = address;
	// could use a map but there are just so many varieties and i want to cover them all without dealing with all the colour variations
	if(name.substr(0,19) == "BP_NPC_Wildlife_Imp")
		EntityID = EntityType::Imp;
	else if (name.substr(0, 21) == "BP_NPC_Wildlife_Kappa")
		EntityID = EntityType::Kappa;
	else if (name.substr(0, 22) == "HumanoidNPCCharacter")
		EntityID = EntityType::Humanoid;
	else if (name == "Corpse_C")
		EntityID = EntityType::Corpse;
	else if (name == "BP_NPC_Wildlife_Rabbit_C")
		EntityID = EntityType::Rabbit;
	else if (name == "BP_HumanoidDialogueNPC_C")
		EntityID = EntityType::DialogNPC;
	else if (name.substr(0, 25) == "BP_NPC_Wildlife_Crocodile")
		EntityID = EntityType::Humanoid;
	else if (name == "BP_NPC_Wildlife_HyenaMiniboss_")
		EntityID = EntityType::HyenaBoss;
	else if (name.substr(0, 21) == "BP_NPC_Wildlife_Hyena")
		EntityID = EntityType::Hyena;
	else if (name.substr(0, 23) == "BP_NPC_Wildlife_Vulture")
		EntityID = EntityType::Vulture;
	else if (name.substr(0, 29) == "BP_PL_CraftingStation_Furnace")
		EntityID = EntityType::Furnace;
	else if (name.substr(0, 27) == "BP_PL_CraftingStation_Armor")
		EntityID = EntityType::Armorer;
	else if (name.substr(0, 27) == "BP_PL_CraftingStation_Metal")
		EntityID = EntityType::MetalSmith;
	else if (name == "LandClaim")
		EntityID = EntityType::LandClaim;
	else if (name.substr(0, 18) == "BP_BuildFoundation")
		EntityID = EntityType::Foundation;
	else if (name.substr(0, 24) == "BP_PL_WorkStation_Tanner")
		EntityID = EntityType::Tanner;
	else if (name.substr(0, 23) == "BP_NPC_Wildlife_Gazelle")
		EntityID = EntityType::Gazelle;
	else if (name.substr(0, 19) == "BP_PL_Bedroll_Fiber")
		EntityID = EntityType::Bedroll;
	else if (name.substr(0, 27) == "BP_PL_WorkStation_Alchemist")
		EntityID = EntityType::Alchemist;
	else if (name == "BP_NPC_Wildlife_RocknoseKingBoss_C")
		EntityID = EntityType::RockNoseBoss;
	else if (name.substr(0, 24) == "BP_NPC_Wildlife_Rocknose")
		EntityID = EntityType::Rocknose;
	else if (name.substr(0, 23) == "BP_NPC_Wildlife_Ostrich")
		EntityID = EntityType::Ostrich;
	else if (name.substr(0, 20) == "BP_NPC_Wildlife_Kudo")
		EntityID = EntityType::Kudo;
	else if (name.substr(0, 20) == "BP_NPC_Wildlife_Fawn")
		EntityID = EntityType::Fawn;
	else if (name.substr(0, 22) == "BP_NPC_Wildlife_Spider")
		EntityID = EntityType::Spider;
	else if (name.substr(0, 25) == "BP_NPC_Wildlife_Slamander")
		EntityID = EntityType::Slamander;
	else if (name.substr(0, 30) == "BP_NPC_Wildlife_MediumScorpion")
		EntityID = EntityType::Scorpion;
	else if (name.substr(0, 21) == "BP_NPC_Wildlife_Cobra")
		EntityID = EntityType::Snake;
	else if (name.substr(0, 24) == "BP_NPC_Wildlife_Antilope")
		EntityID = EntityType::Antilope;
	else if (name.substr(0, 25) == "BP_NPC_Wildlife_RhinoKing")
		EntityID = EntityType::RhinoKing;
	else if (name.substr(0, 29) == "BP_NPC_Wildlife_GiantScorpion")
		EntityID = EntityType::ScorpionBoss;
	else if(name == "BP_set_snake_desert_C")
		EntityID = EntityType::SnakeBoss;
	else if (name.substr(0, 22) == "BP_NPC_Wildlife_Locust")
		EntityID = EntityType::Locust;
	else if (name.substr(0, 22) == "BP_NPC_Wildlife_Jaguar")
		EntityID = EntityType::Jaguar;
	else if (name.substr(0, 21) == "BP_NPC_Wildlife_Tiger")
		EntityID = EntityType::Tiger;
	else if (name.substr(0, 21) == "BP_NPC_Wildlife_Rhino")
		EntityID = EntityType::Rhino;
	else if (name.substr(0, 21) == "BP_NPC_Wildlife_Tiger")
		EntityID = EntityType::Tiger;
	else if (name.substr(0, 21) == "BP_NPC_Wildlife_Wight")
		EntityID = EntityType::Wight;
	else if (name.substr(0, 20) == "BP_NPC_Wildlife_Wolf")
		EntityID = EntityType::Wolf;
	else if(name == "BasePlayerChar_C")
		EntityID = EntityType::Player;
	if (EntityIDNames.contains(EntityID))
		Name = EntityIDNames[EntityID];
	else
		return;
	if(!address)
		return;
	 TargetProcess.AddScatterReadRequest(handle,Class + PlayerState,reinterpret_cast<void*>(&PlayerState), sizeof(uint64_t));
	 TargetProcess.AddScatterReadRequest(handle, Class + Controller, reinterpret_cast<void*>(&Controller), sizeof(uint64_t));
	 TargetProcess.AddScatterReadRequest(handle, Class + RootComponent, reinterpret_cast<void*>(&RootComponent),sizeof(uint64_t));
	 TargetProcess.AddScatterReadRequest(handle, Class + Mesh, reinterpret_cast<void*>(&Mesh), sizeof(uint64_t));


	
}
inline FTransform GetBoneIndex(uint64_t array, uint64_t index) {
	return TargetProcess.Read<FTransform>(array + (index * 0x30));
}
ViewMatrix ToMatrixWithScale(FTransform transform)
{
	ViewMatrix m;

	m.matrix[3][0] = transform.Translation.X;
	m.matrix[3][1] = transform.Translation.Y;
	m.matrix[3][2] = transform.Translation.Z;

	float x2 = transform.Rotation.X + transform.Rotation.X;
	float y2 = transform.Rotation.Y + transform.Rotation.Y;
	float z2 = transform.Rotation.Z + transform.Rotation.Z;

	float xx2 = transform.Rotation.X * x2;
	float yy2 = transform.Rotation.Y * y2;
	float zz2 = transform.Rotation.Z * z2;
	m.matrix[0][0] = (1.0f - (yy2 + zz2)) * transform.Scale3D.X;
	m.matrix[1][1] = (1.0f - (xx2 + zz2)) * transform.Scale3D.Y;
	m.matrix[2][2] = (1.0f - (xx2 + yy2)) * transform.Scale3D.Z;


	float yz2 = transform.Rotation.Y * z2;
	float wx2 = transform.Rotation.W * x2;
	m.matrix[2][1] = (yz2 - wx2) * transform.Scale3D.Z;
	m.matrix[1][2] = (yz2 + wx2) * transform.Scale3D.Y;


	float xy2 = transform.Rotation.X * y2;
	float wz2 = transform.Rotation.W * z2;
	m.matrix[1][0] = (xy2 - wz2) * transform.Scale3D.Y;
	m.matrix[0][1] = (xy2 + wz2) * transform.Scale3D.X;


	float xz2 = transform.Rotation.X * z2;
	float wy2 = transform.Rotation.W * y2;
	m.matrix[2][0] = (xz2 + wy2) * transform.Scale3D.Z;
	m.matrix[0][2] = (xz2 - wy2) * transform.Scale3D.X;

	m.matrix[0][3] = 0.0f;
	m.matrix[1][3] = 0.0f;
	m.matrix[2][3] = 0.0f;
	m.matrix[3][3] = 1.0f;

	return m;
}
Vector3 ResolveMatrix(FTransform transform, FTransform c2w)
{
	ViewMatrix matrix; 
	ViewMatrix bonematrix = ToMatrixWithScale(transform);
	ViewMatrix c2wmatrix = ToMatrixWithScale(c2w);
	matrix.matrix[0][0] = bonematrix.matrix[0][0] * c2wmatrix.matrix[0][0];
	matrix.matrix[0][1] = bonematrix.matrix[0][1] * c2wmatrix.matrix[0][1];
	matrix.matrix[0][2] = bonematrix.matrix[0][2] * c2wmatrix.matrix[0][2];
	matrix.matrix[0][3] = bonematrix.matrix[0][3] * c2wmatrix.matrix[0][3];

	matrix.matrix[1][0] = bonematrix.matrix[1][0] * c2wmatrix.matrix[1][0];
	matrix.matrix[1][1] = bonematrix.matrix[1][1] * c2wmatrix.matrix[1][1];
	matrix.matrix[1][2] = bonematrix.matrix[1][2] * c2wmatrix.matrix[1][2];
	matrix.matrix[1][3] = bonematrix.matrix[1][3] * c2wmatrix.matrix[1][3];

	matrix.matrix[2][0] = bonematrix.matrix[2][0] * c2wmatrix.matrix[2][0];
	matrix.matrix[2][1] = bonematrix.matrix[2][1] * c2wmatrix.matrix[2][1];
	matrix.matrix[2][2] = bonematrix.matrix[2][2] * c2wmatrix.matrix[2][2];
	matrix.matrix[2][3] = bonematrix.matrix[2][3] * c2wmatrix.matrix[2][3];

	matrix.matrix[3][0] = bonematrix.matrix[3][0] * c2wmatrix.matrix[3][0];
	matrix.matrix[3][1] = bonematrix.matrix[3][1] * c2wmatrix.matrix[3][1];
	matrix.matrix[3][2] = bonematrix.matrix[3][2] * c2wmatrix.matrix[3][2];
	matrix.matrix[3][3] = bonematrix.matrix[3][3] * c2wmatrix.matrix[3][3];


	return Vector3{ matrix.matrix[3][0],  matrix.matrix[3][1],  matrix.matrix[3][2] };
}

void ActorEntity::SetUp1(VMMDLL_SCATTER_HANDLE handle)
{
	if (!Class)
		return;
	if (!RootComponent)
		return;
	
	if (EntityID == Player)
	{// printf Mesh
		//auto test2 = TargetProcess.Read<uint64_t>(Mesh + 0x0169);
		auto ComponentToWorld = TargetProcess.Read<FTransform>(Mesh + 0x1a0); // just guess this till you get a scale (1,1,1) and a roation with  0,0,-0.9998,-0.02
		printf("Scale3D %f,%f,%f\n", ComponentToWorld.Scale3D.X, ComponentToWorld.Scale3D.Y, ComponentToWorld.Scale3D.Z);
		printf("Translation %f,%f,%f\n", ComponentToWorld.Translation.X, ComponentToWorld.Translation.Y, ComponentToWorld.Translation.Z);
		printf("Rotation %f,%f,%f,%f\n", ComponentToWorld.Rotation.X, ComponentToWorld.Rotation.Y, ComponentToWorld.Rotation.Z, ComponentToWorld.Rotation.W);
		auto test = TargetProcess.Read<uint64_t>(Mesh + MasterPoseComponent);
		// printf test.length()

		auto test2 = GetBoneIndex(test, 2);
		printf("Scale3D %f,%f,%f\n", test2.Scale3D.X, test2.Scale3D.Y, test2.Scale3D.Z);
		printf("Translation %f,%f,%f\n", test2.Translation.X, test2.Translation.Y, test2.Translation.Z);
		printf("Rotation %f,%f,%f,%f\n", test2.Rotation.X, test2.Rotation.Y, test2.Rotation.Z, test2.Rotation.W);
		BoneTest = ResolveMatrix(test2, ComponentToWorld);
		printf("BoneTest %f,%f,%f\n", BoneTest.x, BoneTest.y, BoneTest.z);
	//	printf("test2 %f,%f,%f\n", test2.Scale3D.X, test2.Scale3D.Y, test2.Scale3D.Z);

		if (Controller == EngineInstance->GetPlayerController())
		{
			//AcknowledgedPawn = TargetProcess.Read<uint64_t>(Controller + AcknowledgedPawn);
			//uint64_t charactermovement = TargetProcess.Read<uint64_t>(AcknowledgedPawn + 0x0450);
			// BasePlayerChar_C player is this // HeadVisible
		
			//TargetProcess.Write<float>(Class + 0x0080, 3); // speedhack
			//TargetProcess.Write<float>(charactermovement + 0x01F0, 10000);
		}
	}

	
	UEPosition = TargetProcess.Read<UEVector>(RootComponent + RelativeLocation);
	Position = Vector3(UEPosition.X, UEPosition.Y, UEPosition.Z);
}

void ActorEntity::SetUp2()
{

}


uint64_t ActorEntity::GetClass()
{
	return Class;
}

std::wstring ActorEntity::GetName()
{
	return Name;
}

Vector3 ActorEntity::GetPosition()
{
	Position = Vector3(UEPosition.X, UEPosition.Y, UEPosition.Z);
	return Position;
}

void ActorEntity::UpdatePosition(VMMDLL_SCATTER_HANDLE handle)
{
	if (!Class)
		return;
	if (!RootComponent)
		return;
	if (!PlayerState)
		return;
	TargetProcess.AddScatterReadRequest(handle, RootComponent + RelativeLocation, reinterpret_cast<void*>(&UEPosition), sizeof(UEVector));
}