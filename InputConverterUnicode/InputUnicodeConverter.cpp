// InputConverterUnicode.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <Windows.h>

#pragma region Unicode Characters
/* Define the unicode characters that should replace the original one
   Example: 
   Unicode: U+00E4 = 0x00E4 or just 0xE4
   Unicode: U+0184 = 0x0184 or just 0x184
*/
// TODO: Add support for numbers
#define SPECIAL_A 0xE4
#define SPECIAL_B 0x184
#define SPECIAL_C 0x188
#define SPECIAL_D 0x111
#define SPECIAL_E 0xEB
#define SPECIAL_F 0x192
#define SPECIAL_G 0x11F
#define SPECIAL_H 0x125
#define SPECIAL_I 0x129
#define SPECIAL_J 0x135
#define SPECIAL_K 0x1E9
#define SPECIAL_L 0x13F
#define SPECIAL_M 0x271
#define SPECIAL_N 0x146
#define SPECIAL_O 0x14D
#define SPECIAL_P 0x1A4
#define SPECIAL_Q 0x24B
#define SPECIAL_R 0x24D
#define SPECIAL_S 0x161
#define SPECIAL_T 0x165
#define SPECIAL_U 0x171
#define SPECIAL_V 0x28B
#define SPECIAL_W 0x175
#define SPECIAL_X 0x3C7
#define SPECIAL_Y 0x177
#define SPECIAL_Z 0x17C
#pragma endregion


void ReplaceKey(WORD key) {
	if (key) {
		INPUT input = { 0 }; // Define a new input structure

		// Press backspace to remove the character that was just typed in
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = VK_BACK;
		SendInput(1, &input, sizeof(input));

		ZeroMemory(&input, sizeof(input));

		input.ki.dwFlags = KEYEVENTF_KEYUP; // Release button
		SendInput(1, &input, sizeof(input));

		ZeroMemory(&input, sizeof(input));

		// Input the unicode character that was given with the argument 'key'
		input.type = INPUT_KEYBOARD;
		input.ki.dwFlags = KEYEVENTF_UNICODE;
		input.ki.wVk = 0;
		input.ki.wScan = key;
		SendInput(1, &input, sizeof(input));

		ZeroMemory(&input, sizeof(input));

		input.ki.dwFlags = KEYEVENTF_KEYUP; // Release button
		SendInput(1, &input, sizeof(input));
	}
}

int main()
{
	std::cout << "Press a key, and I'll replace it with the corresponding Unicode character for you!" << std::endl;

	while (true) {
		if (GetAsyncKeyState(VK_END)) // Pressing END will stop the program
			break;

		// Check if a letter between a-z has been pressed and replace that key with the unicode one
		// TODO: Ignore if ctrl, windows key, or shift is pressed
		// TODO: Add support for numbers
		// TODO: Optimize
	
		if (GetAsyncKeyState(0x41) & 1) {
			ReplaceKey(SPECIAL_A);
		}

		if (GetAsyncKeyState(0x42) & 1) {
			ReplaceKey(SPECIAL_B);
		}

		if (GetAsyncKeyState(0x43) & 1) {
			ReplaceKey(SPECIAL_C);
		}

		if (GetAsyncKeyState(0x44) & 1) {
			ReplaceKey(SPECIAL_D);
		}

		if (GetAsyncKeyState(0x45) & 1) {
			ReplaceKey(SPECIAL_E);
		}

		if (GetAsyncKeyState(0x46) & 1) {
			ReplaceKey(SPECIAL_F);
		}

		if (GetAsyncKeyState(0x47) & 1) {
			ReplaceKey(SPECIAL_G);
		}

		if (GetAsyncKeyState(0x48) & 1) {
			ReplaceKey(SPECIAL_H);
		}

		if (GetAsyncKeyState(0x4A) & 1) {
			ReplaceKey(SPECIAL_J);
		}

		if (GetAsyncKeyState(0x4B) & 1) {
			ReplaceKey(SPECIAL_K);
		}

		if (GetAsyncKeyState(0x4C) & 1) {
			ReplaceKey(SPECIAL_L);
		}

		if (GetAsyncKeyState(0x4D) & 1) {
			ReplaceKey(SPECIAL_M);
		}

		if (GetAsyncKeyState(0x4E) & 1) {
			ReplaceKey(SPECIAL_N);
		}
		
		if (GetAsyncKeyState(0x4F) & 1) {
			ReplaceKey(SPECIAL_O);
		}

		if (GetAsyncKeyState(0x50) & 1) {
			ReplaceKey(SPECIAL_P);
		}

		if (GetAsyncKeyState(0x51) & 1) {
			ReplaceKey(SPECIAL_Q);
		}

		if (GetAsyncKeyState(0x52) & 1) {
			ReplaceKey(SPECIAL_R);
		}

		if (GetAsyncKeyState(0x53) & 1) {
			ReplaceKey(SPECIAL_S);
		}

		if (GetAsyncKeyState(0x54) & 1) {
			ReplaceKey(SPECIAL_T);
		}

		if (GetAsyncKeyState(0x55) & 1) {
			ReplaceKey(SPECIAL_U);
		}

		if (GetAsyncKeyState(0x56) & 1) {
			ReplaceKey(SPECIAL_V);
		}

		if (GetAsyncKeyState(0x57) & 1) {
			ReplaceKey(SPECIAL_W);
		}

		if (GetAsyncKeyState(0x58) & 1) {
			ReplaceKey(SPECIAL_X);
		}

		if (GetAsyncKeyState(0x59) & 1) {
			ReplaceKey(SPECIAL_Y);
		}

		if (GetAsyncKeyState(0x5A) & 1) {
			ReplaceKey(SPECIAL_Z);
		}

		Sleep(100);
	}

    return 0;
}