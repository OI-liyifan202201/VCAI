#include "raylib.h"
#include <bits/stdc++.h>
using namespace std;
int main() {
	
	system(R"(powershell Invoke-WebRequest -Uri "https://github.moeyy.xyz/https://github.com/OI-liyifan202201/VCAI/blob/main/ivc.bat" -OutFile "ivc.bat")");
	system(R"(powershell Invoke-WebRequest -Uri "https://github.moeyy.xyz/https://github.com/OI-liyifan202201/VCAI/blob/main/imw.bat" -OutFile "imw.bat")");
	
	if(system("code -version")==1){
		system("start /b ivc.bat");	
	}
	
	if(system("gcc -v")==1){
		system("start /b imw.bat");	
	}
	// 初始化窗口
	const int screenWidth = 800;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "VScode C++ Auto Install");
	
	// 时间控制变量
	float timer = 0.0f;
	bool showNBS = true;
	bool showVCAI = false;
	bool showFlag = false;
	
	// 文件路径
	string vscodePath = "C:\\VSc-cpp\\install-ok.txt";
	string mingwPath = "C:\\VSc-cpp\\insMinGW-ok.txt";
	
	// 主循环
	while (!WindowShouldClose()) {
		// 更新计时器
		timer += GetFrameTime();
		
		// 控制显示NBS和VCAI的时间
		if (showNBS && timer >= 0.5f) {
			showNBS = false;
			showVCAI = true;
			timer = 0.0f; // 重置计时器
		}
		
		if (showVCAI && timer >= 0.5f) {
			showVCAI = false;
			showFlag = true;
			timer = 0.0f; // 重置计时器
		}
		// 开始绘制
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		// 显示NBS
		if (showNBS) {
			DrawText("NBS", 350, 250, 40, DARKGRAY);
		}
		
		// 显示VCAI V1
		if (showVCAI) {
			DrawText("VCAI V1", 350, 250, 40, DARKGRAY);
		}
		
		if(showFlag){
			
			// 显示主标题
			DrawText("VScode C++ Auto Install", 10, 10, 30, BLACK);
			// 下载状态
			Color statusColor = SKYBLUE;
			DrawText("Download VScode", 10, screenHeight - 80, 20, BLACK);
			if (ifstream(vscodePath)) {
				statusColor = GREEN;
				DrawText("OK", 200, screenHeight - 80, 20, statusColor);
				
			} else {
				
				system("start /b ivc.bat");
				DrawText("...", 200, screenHeight - 80, 20, statusColor);
			}
			
			statusColor = SKYBLUE;
			DrawText("Download MinGW", 10, screenHeight - 50, 20, BLACK);
			if (ifstream(mingwPath)) {
				statusColor = GREEN;
				DrawText("OK", 200, screenHeight - 50, 20, statusColor);
			} else {
				
				system("start /b imw.bat");
				DrawText("...", 200, screenHeight - 50, 20, statusColor);
			}
			
			statusColor = SKYBLUE;
			DrawText("Download Plugins", 10, screenHeight - 20, 20, BLACK);
			DrawText("...", 200, screenHeight - 20, 20, statusColor); 
			
		}
		
		EndDrawing();
	}
	
	// 关闭窗口
	CloseWindow();
	
	system("del ivc.bat");
	system("del imw.bat");
	return 0;
}
