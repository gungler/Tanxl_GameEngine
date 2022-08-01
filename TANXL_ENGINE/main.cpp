#include "Tanxl_OpenGL_Draw.h"
#include "Tanxl_UniqueID.h"
#include "Tanxl_DataBase.h"
int main()
{
	//Data Function Test

	TANXL_DataBase NData;
	int n = 0x11111, i = 5;
	while (i--)
	{
		std::cout << "Updating : " << n << std::endl;
		NData.Set_Instance(n++, "Updating" + std::to_string(n));
		std::cout << NData;
		NData.AppendItem(false);
	}
	NData.Print_Data();

	//Get Instance

	GameStateBase* GSB{ &GameStateBase::GetStateBase(10, 10) };

	InsertEventBase* IEB{ &InsertEventBase::GetInsertBase() };

	//InsertKey Init

	Key_Unit MOVE_UP;
	MOVE_UP.GLFW_KEY = GLFW_KEY_UP;
	MOVE_UP.MoveLen = 0.01f;
	MOVE_UP.MoveToY = true;
	IEB->RegistEvent(MOVE_UP);
	MOVE_UP.GLFW_KEY = GLFW_KEY_W;
	IEB->RegistEvent(MOVE_UP);

	Key_Unit MOVE_LEFT;
	MOVE_LEFT.GLFW_KEY = GLFW_KEY_LEFT;
	MOVE_LEFT.MoveLen = -0.01f;
	MOVE_LEFT.MoveToX = true;
	IEB->RegistEvent(MOVE_LEFT);
	MOVE_LEFT.GLFW_KEY = GLFW_KEY_A;
	IEB->RegistEvent(MOVE_LEFT);

	Key_Unit MOVE_RIGHT;
	MOVE_RIGHT.GLFW_KEY = GLFW_KEY_RIGHT;
	MOVE_RIGHT.MoveLen = 0.01f;
	MOVE_RIGHT.MoveToX = true;
	IEB->RegistEvent(MOVE_RIGHT);
	MOVE_RIGHT.GLFW_KEY = GLFW_KEY_D;
	IEB->RegistEvent(MOVE_RIGHT);

	Key_Unit MOVE_DOWN;
	MOVE_DOWN.GLFW_KEY = GLFW_KEY_DOWN;
	MOVE_DOWN.MoveLen = -0.01f;
	MOVE_DOWN.MoveToY = true;
	IEB->RegistEvent(MOVE_DOWN);
	MOVE_DOWN.GLFW_KEY = GLFW_KEY_S;
	IEB->RegistEvent(MOVE_DOWN);

	IEB->Set_MaxFloat(0.9f);//公式 1 - ( 1 / 游戏地图边长（方块数）)

	OpenGL_Draw OD;
	OD.mainLoop(GSB);
}
