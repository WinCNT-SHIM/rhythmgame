#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define INPUT_SIZE 30

#define Logox 25 //���߾��� 50
#define Logoy 10

#define Menux 44 //���߾��� 50
#define Menuy 55

#define SelectMenux 50
#define Selectmenuy 60

//Megalovania ���� ȭ�鿡�� ��� ����ϴ� ��ǥ
#define SansX 50
#define SansY 10

//���� ���� ȭ��(���� ���� ȭ��) ���� define
#define MusicInfoCount 5
#define MusicInfoTitleLine 7
#define MusicInfoSelectLine 6

extern void Gotoxy(int x, int y, unsigned short text_Color = 15, unsigned short back_Color = 0);
extern void PlayMusic(int musicnum, int(*_keyInput)[INPUT_SIZE], int(*_Musicnotes)[INPUT_SIZE], int _Musicsize, int _bpm);
extern void Playsound(int soundnum);
extern void PauseMusic();
extern void SelectAnimUpdate(int x, int y, int num);


void PrintfSelectMenu(int _selectmusicnum);
int g_Color = rand() % 8 + 8;
#pragma region "MegalovaniaNotes"
// Megalovania�� Ű ����
int _keyInputMegalovania[27][INPUT_SIZE] =
{
	{ 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 2, 1, 0, 2, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 2, 1, 2, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 1, 2, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 1, 2, 1, 2, 2, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 1, 2, 1, 2, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 1, 2, 2, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 1, 2, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 1, 2, 2, 1, 1, 0, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 1, 2, 2, 2, 1, 0, 0, 0, 2, 2, 1, 2, 2, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 0, 0, 2, 0, 2, 1, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 1, 2, 2, 1, 2, 1, 0, 0, 2, 0, 2, 1, 1, 2, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 2, 1, 0, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 1, 2, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 1, 2, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 1, 2, 2, 0, 1, 2, 2, 0, 1, 2, 2, 0, 1, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 0, 0, 0, 0, 0 },
	{ 2, 0, 2, 1, 0, 2, 0, 2, 0, 1, 0, 2, 1, 2, 2, 2, 1, 0, 2, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 1, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// Megalovania�� ��Ʈ ����(BPM: 240, 1���ڿ� 250ms)
int _MusicNotesMegalovania[27][INPUT_SIZE] =
{
	{ -250, 250, 250, -250, -1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 250, -250, -1000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 0, 250, 250, -125, 125, -125, 125, -125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 250, -125, 125, -125, 125, -125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 0, 250, 250, 250, 125, 125, 125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 250, 250, 125, 125, 125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 125, 125, 125, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 0, 250, 250, 250, 250, -125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 250, 250, 250, -125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 0, 250, 250, 125, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 250, 125, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 0, 250, 250, 125, 125, 125, 125, 125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 250, 125, 125, 125, 125, 125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 125, 250, 250, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 125, 250, 125, 250, 125, 125, 125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 125, 250, 125, 250, 125, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 125, 125, 125, 125, 250, 250, 125, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 125, 125, 250, 250, -125, 125, 125, 125, 250, 250, 250, 250, 125, 250, 125, -125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 250, 250, 250, 250, 250, -250, 0, 0, 250, 250, 250, 250, 125, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 125, 125, 250, 125, 125, 125, 125, 125, 125, 250, 125, 125, 125, 125, 250, 125, 125, 0, -125, 125, -125, 125, 250, -250, 0, 0, 0, 0 },
	{ 250, 125, 125, 250, 250, 125, 125, 125, 125, 250, 250, 125, 125, 250, 250, 250, 125, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 250, 250, 250, 250, 125, 125, 250, 250, -250, 0, 250, -125, 125, 250, 250, 125, 125, 250, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 0, 250, 250, 125, 125, 125, 125, 125, 125, 250, 250, 125, 250, 125, 250, 250, 125, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 250, 125, 125, 125, 125, 125, 125, 250, 250, 125, 250, 125, 250, 250, 125, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 0, 250, 250, -125, 250, 125, 125, 125, 250, 250, 125, 125, 250, 250, 250, 250, -125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 250, -125, 250, 125, 125, 125, 250, 250, 125, 125, 250, 250, 250, 250, -125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 250, 250, -250, 250, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 250, 250, -250, 250, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 250, -125, 125, -125, 125, -125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 250, 125, 250, 125, 125, 125, 250, 250, 250, 250, 125, 125, 125, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 250, 125, 250, 125, 125, 125, 250, 250, 250, 250, 125, 125, 125, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 250, 125, 125, -125, 125, 125, 125, 125, 125, 250, 250, 250, 125, 125, 125, 125, -125, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0 },
	{ 250, 0, 250, 125, 125, 125, 250, 125, 125, 125, 125, 125, 250, 250, 250, 125, 125, 125, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0 },//{ 125, 125, 250, 125, 125, 125, 250, 125, 125, 125, 125, 125, 250, 250, 250, 125, 125, 125, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0, 0, 0 },
	{ 250, 0, 125, 125, 250, 0, 125, 125, 250, 0, 125, 125, 250, 0, 250, 250, 250, 125, 125, 125, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0 },//{ 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 250, 250, 250, 125, 125, 125, 250, 125, 125, 125, 250, -250, 0, 0, 0, 0 },
	{ 250, 0, 250, 250, -125, 125, -125, 125, -125, 125, -125, 125, 250, 125, 125, 250, 250, -125, 125, -125, 125, -125, 125, -500, 0, 0, 0, 0, 0, 0 },
	{ 250, 250, 250, -250, -125, 125, -125, 125, -500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
#pragma endregion

#pragma region "K.K. House"
// K.K. House ���񺸺�����(������ ��)�� Ű ����
int _keyInputKKHouse[30][INPUT_SIZE] =
{
	{ 2, 2, 0, 1, 0, 1, 2, 1, 1, 0, 2, 2, 0, 1, 0, 2, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 0, 1, 0, 1, 2, 1, 1, 0, 2, 2, 0, 1, 0, 2, 1, 2, 2, 0, 2, 2, 0, 1, 0, 2, 1, 2, 2, 0 },
	{ 2, 2, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 1, 1, 0, 1, 1, 0, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2, 2, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 1, 1, 0, 1, 1, 0, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2, 2, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 1, 1, 0, 1, 1, 0, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 2, 2, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 0, 1, 0, 1, 2, 1, 1, 0, 2, 2, 0, 1, 0, 2, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //11
	{ 2, 2, 0, 1, 0, 1, 2, 1, 1, 0, 2, 2, 0, 1, 0, 2, 1, 2, 2, 0, 2, 2, 0, 1, 0, 2, 1, 2, 2, 0 },
	{ 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //15
	{ 2, 2, 2, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //20
	{ 2, 2, 2, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 1, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 2, 0, 1, 0, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 2, 0, 1, 0, 1, 2, 1, 1, 0, 2, 2, 0, 1, 0, 2, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }


};

// K.K. House ���񺸺�����(������ ��)�� ��Ʈ ���� 
int _MusicNotesKKHouse[30][INPUT_SIZE] =
{
	{369,369,0,492,0,246,246,123,123,0,369,369,0,492,0,246,246,123,123,0,0,0,0,0,0,0,0,0,0,0},
	{369,369,0,492,0,246,246,123,123,0,369,369,0,492,0,246,246,123,123,0,0,0,0,0,0,0,0,0,0,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,123,123,-123,123,123,-123,123,123,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,123,123,-123,123,123,-123,123,123,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,123,123,-123,123,123,-123,123,123,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{-492,-492,-492,-492,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{369,369,0,492,0,246,246,123,123,0,369,369,0,492,0,246,246,123,123,0,0,0,0,0,0,0,0,0,0,0},
	{369,369,0,492,0,246,246,123,123,0,369,369,0,492,0,246,246,123,123,0,0,0,0,0,0,0,0,0,0,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0}, //15
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{492,-492,-246, 246, -123, 246, -123, 0, 0, 0,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0}, //20
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{246,246,246,-123,246,-123,246,-123,123,246,0},
	{369,369,0,492,0,246,246,123,123,0,0,  0,0,  0,0,  0,  0,  0,  0,0,0,0,0,0,0,0,0,0,0,0},
	{-984,0},
};
#pragma endregion

#pragma region "Mario"
int  _keyInputMario[27][INPUT_SIZE] =
{
	{1,1,2,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2 },
	{1,1,2,2,0,1,1,2,2,0,1,1,2,2,0,1,1,2,2,0,1,1,2,2,0,1,1,2,2,0},
	{1,1,2,2,0,1,1,2,2,0,1,1,2,2,0,1,1,2,2,0,1,1,2,2,0,1,1,2,2,0},
	{2,2,1,1,0,2,2,1,1,0,1,1,2,2,0,1,1,2,2,0,1,1,2,2,0,1,1,2,2,0},
	{1,2,1,1,2,2,1,1,1},
	{1,2,1,1,2,2,1,1,1},
	{1,2,1,1,2,2,1,1,1},

	{1,1,2,0,0,1,1,2},

	{1,2,2,2,0,1,2,2,2},
	{2,1,1,1,0,2,1,1,1},

	{1,2,1,1,2,2,1,1,1},
	{1,2,1,1,2,2,1,1,1},

	{1,2,1,1,2,1,2,1,1,2},
	{1,1,2,2,0,1,1,2,2},
	{1,1,2,1},
};
int _MusicNotesMario[27][INPUT_SIZE] =
{
	//{622,622,622,-622,0,622,622,622,-622},
	{622,622,1244},
	{311,311,311,311,0,311,311,311,311,0},
	{311,311,311,311,0,311,311,311,311,0},
	{311,311,311,311,0,311,311,311,311,0},
	{622,622,311,311,622},
	{622,622,311,311,622},
	{311,311,311,311,0},

	{622,622,1244,0,0,622,622,1244},

	{311,311,311,311,0,311,311,311,311,0},
	{311,311,311,311,0,311,311,311,311,0},
	{622,622,311,311,622},
	{622,622,311,311,622},
	{622,622,311,311,622,622,622,311,311,622},
	{311,311,311,311,0,311,311,311,311,0},
	{622,622,311,622},


};
#pragma endregion

#pragma region "�Լ��� ������Ÿ��"
void Startmenu();
void LoadStartmenuUI();
void Selectmenu();
void SetMusicbar(int _bpm);
void PrintCredits();
#pragma endregion

char g_logoText[2][12][160] =
{
	{
		{"����������������������_    ����������   ���������� ____          ____ ������������������������������ ����������   ����������  ����������          ���������� \0"},
		{"��           1   ��   ��   ��   �� 1   1        /   / ��             �� ��   ��   ��   ��  ��    1         /   �� \0"},
		{"��   ����������   ��   ��   ��   ��   ��  1   1      /   /  ������������   ������������ ��   ��   ��   ��  ��     1       /    �� \0"},
		{"��   ��   ��   ��   ��   ��   ��   ��   1   1    /   /        ��   ��      ��   ��   ��   ��  ��      1     /     �� \0"},
		{"��   ��   ��   ��   ��   ��   ��   ��    1   1  /   /         ��   ��      ��   ��   ��   ��  ��       1   /      �� \0"},
		{"��   ����������   /   ��   ����������   ��     1   1/   /          ��   ��      ��   ����������   ��  ��        1_/       �� \0"},
		{"��          /    ��           ��      1      /           ��   ��      ��           ��  ��                  �� \0"},
		{"��   ��������   1    ��   ����������   ��       ��    ��            ��   ��      ��   ����������   ��  ��   ��1        /��   �� \0"},
		{"��   ��   1   1   ��   ��   ��   ��       ��    ��            ��   ��      ��   ��   ��   ��  ��   �� 1      / ��   �� \0"},
		{"��   ��    1   1  ��   ��   ��   ��       ��    ��            ��   ��      ��   ��   ��   ��  ��   ��  1    /  ��   �� \0"},
		{"��   ��    ��   ��  ��   ��   ��   ��       ��    ��            ��   ��      ��   ��   ��   ��  ��   ��   1  /   ��   �� \0"},
		{"����������    ����������  ����������   ����������       ������������            ����������      ����������   ����������  ����������    1/    ���������� \0"}
	},
	{
		{"����������   ���������� ����������������������������������         ��������          \0"},
		{"��   ��   ��   �� ��  ����������������������  ��         ��  ��          \0"},
		{"��   ��   ��   �� ��  ��         ��  ��         ��  ��          \0"},
		{"��   ��   ��   �� ��  ��         ��  ��         ��  ��          \0"},
		{"��   ��   ��   �� ��  ��         ��  ��         ��  ��          \0"},
		{"��   ����������   �� ��  ����������������������  ��         ��  ��          \0"},
		{"��           �� ��  ����������������������  ��         ��  ��          \0"},
		{"��   ����������   �� ��  ��         ��  ��         ��  ��          \0"},
		{"��   ��   ��   �� ��  ��         ��  ��         ��  ��          \0"},
		{"��   ��   ��   �� ��  ��         ��  ��         ��  ��          \0"},
		{"��   ��   ��   �� ��  ������������������ ��  ����������������������  �������������������� \0"},
		{"����������   ���������� ������������������������ ���������������������������������������������������� \0"}
	}
};

char g_startmenuText[5][6][50] = //1. start 2. exit 3. credit 4. cursor, 5. cursorremover
{
	{
		{" _____  _____   ___   ______  _____ \0"},
		{"/  ___||_   _| / _ 1  | ___ 1|_   _|\0"},
		{"l `--.   | |  / |_| 1 | |_/ /  | |  \0"},
		{" `--. l  | |  | ___ | |    /   | |  \0"},
		{"/l__/ /  | |  | | | | | |l l   | |  \0"},
		{"l____/   |_|  |_| |_| |_| l_|  |_|  \0"}
	},
	{
		{" ____  __   __ _____  _____  \0"},
		{"|  __| 1 1 / /|_   _||_   _| \0"},
		{"| |__   1 1 /   | |    | |   \0"},
		{"|  __|  /  1    | |    | |   \0"},
		{"| |___ / /1 1  _| |_   | |   \0"},
		{"|____//_/  1_1|_____|  |_|   \0"}
	},
	{
		{" _____ ______  ____  ____   _____  _____  \0"},
		{"/  __ l| ___ 1|  __||  _ 1 |_   _||_   _| \0"},
		{"| /  l/| |_/ /| |__ | | | |  | |    | |   \0"},
		{"| |    |    / |  __|| | | |  | |    | |   \0"},
		{"| l__/l| |l l | |___| |_| | _| |_   | |   \0"},
		{"l____/ |_| l_||____/|____/ |_____|  |_|   \0"}
	},
	{
		{"      |1  \0"},
		{" _____| 1 \0"},
		{"|        1\0"},
		{"|_____   /\0"},
		{"      | / \0"},
		{"      |/  \0"}
	},
	{
		{"          \0"},
		{"          \0"},
		{"          \0"},
		{"          \0"},
		{"          \0"},
		{"          \0"}
	}
};

char g_textchoice[6][45] =
{
	{" _____  _   _  _____  _____  _____  _____ "},
	{"/  __ l| | | ||  _  ||_   _|/  __ l|  ___|"},
	{"| /  l/| |_| || | | |  | |  | /  l/| |__  "},
	{"| |    |  _  || | | |  | |  | |    |  __| "},
	{"| l__/l| | | |l l_/ / _| |_ | l__/l| |___ "},
	{"l____/ l_| |_/l___ /  l___/ l____/ l____/ "},

};
char g_textBPM[6][25] =
{
	{"______ ______ ___  ___"},
	{"| ___ l| ___ l|  l/  |"},
	{"| |_/ /| |_/ /| .  . |"},
	{"| ___ l|  __/ | |l/| |"},
	{"| |_/ /| |    | |  | |"},
	{"l____/ l_|    l_|  |_/"},
};

// ���� ���� â���� ǥ�õǴ� ���� ����(Ÿ��Ʋ, BPM)�� ����ü
struct Musicinfo {
	char _name[MusicInfoTitleLine][100] = { 0 };
	int _bpm = 0;
};

// ���� ���� â���� ǥ�õǴ� ������ ����(Ÿ��Ʋ, BPM)
Musicinfo g_Musicinfo[MusicInfoCount] = {
	{
		{
		" ___ ___    ___   ____   ____  _       ___   __ __   ____  ____   ____   ____ ",
		"|   |   |  /  _] /    | /    || |     /   1 |  |  | /    ||    1 |    | /    |",
		"| _   _ | /  [_ |   __||  o  || |    |     ||  |  ||  o  ||  _  | |  | |  o  |",
		"|  1_/  ||    _]|  |  ||     || |___ |  O  ||  |  ||     ||  |  | |  | |     |",
		"|   |   ||   [_ |  |_ ||  _  ||     ||     ||  :  ||  _  ||  |  | |  | |  _  |",
		"|   |   ||     ||     ||  |  ||     ||     | 1   / |  |  ||  |  | |  | |  |  |",
		"|___|___||_____||___,_||__|__||_____| 1___/   1_/  |__|__||__|__||____||__|__|",
		}
		, 120
	},


	{
		{
		" _   __    _   __    _   _  _____  _   _  _____  _____ ",
		"| | / /   | | / /   | | | ||  _  || | | |/  ___||  ___|",
		"| |/ /    | |/ /    | |_| || | | || | | |l `--. | |__  ",
		"|    l    |    l    |  _  || | | || | | | `--. l|  __| ",
		"| |l  l _ | |l  l _ | | | |l l_/ /| |_| |/l__/ /| |___ ",
		"l_| l_/(_)l_| l_/(_)l_| |_/ l___/  l___/ l____/ l____/ ",
		}, 122 },
	{ {
			" ____  _   _ ____  _____ ____  __  __    _    ____  ___ ___  ",
			"/ ___|| | | |  _ l| ____|  _ l|  l/  |  / l  |  _ l|_ _/ _ l ",
			"l___ l| | | | |_) |  _| | |_) | |l/| | / _ l | |_) || | | | |",
			" ___) | |_| |  __/| |___|  _ <| |  | |/ ___ l|  _ < | | |_| |",
			"|____/ l___/|_|   |_____|_| l_l_|  |_/_/   l_l_| l_l___l___/ ",
			

		}, 120 },
	{ { 0 }, 2 },
	{ { 0 }, 3 }
};

 
 
 
 
 





                                                              


// ============================================ Startmenu �Լ� ============================================
/// <summary>
/// �޴� ȭ�� ������ �����ϴ� �Լ�
/// </summary>
void Startmenu() {
	system("cls");
	static int _selectnum = 0;
	int _lownum = 0;
	int _maxnum = 2;


	while (1) {

		if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
			for (int i = 0; i < 6; i++)
			{
				Gotoxy(Menux * 2 - 20, Menuy + i + _selectnum * 8, 15, 0);
				printf("%s", g_startmenuText[4][i]);
			}
			if (_selectnum == _maxnum) {
			}
			else {
				_selectnum++;
			}
		}
		else if (GetAsyncKeyState(VK_UP) & 0x0001) {
			for (int i = 0; i < 6; i++)
			{
				Gotoxy(Menux * 2 - 20, Menuy + i + _selectnum * 8, 15, 0);
				printf("%s", g_startmenuText[4][i]);
			}
			if (_selectnum == _lownum) {
			}
			else {
				_selectnum--;
			}
		}
		else if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
			// START ���� ��, ���� ���� ȭ���� ǥ����
			if (_selectnum == 0)
			{
				// ���� ���� ȭ�� ǥ�� �Լ�
				Selectmenu();
				// ���� ���� ȭ�鿡�� EXIT�� �������� ���
				system("cls");
				// ���� ȭ���� START, EXIT, CREDIT�� �׸��� ó��
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 6; i++)
					{
						Gotoxy(Menux * 2, Menuy + i + 8 * j, 15, 0);
						printf("%s", g_startmenuText[j][i]);
					}
				}
			}
			// EXIT ���� ��, ������ ������
			else if (_selectnum == 1)
			{
				exit(0);
			}
			// CREDIT ���� ��, ũ���� ȭ���� ǥ����
			else if (_selectnum == 2)
			{
				PrintCredits();
			}
		}

		// ���� ȭ���� ȭ��ǥ(��)�� �׸��� ó��
		for (int i = 0; i < 6; i++)
		{
			Gotoxy(Menux * 2 - 20, Menuy + i + _selectnum * 8, 15, 0);
			printf("%s", g_startmenuText[3][i]);
		}
		// ���� ȭ���� Ÿ��Ʋ�� �׸��� ó��
		LoadStartmenuUI();
	}

}

/// <summary>
/// ���� ���� â�� ȭ�鿡 ǥ���ϴ� �Լ�
/// START�� ������ ��� ����
/// </summary>
void Selectmenu() {
	system("cls");

	static int _selectmusicnum = 0;
	int _lownum = 0;
	int _maxnum = 2;

	int _selectmenunum = 0;
	int _lowmenu = 0;
	int _maxmenu = 1;

	PrintfSelectMenu(_selectmusicnum);

	Playsound(_selectmusicnum + 1);

	while (1) {

		SetMusicbar(g_Musicinfo[_selectmusicnum]._bpm);
		SelectAnimUpdate(5, 10, _selectmusicnum);

		if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
			for (int i = 0; i < 6; i++)
			{
				Gotoxy(SelectMenux * 2 - 16, Selectmenuy + 10 + i + _selectmenunum * 7, 15, 0);
				printf("          ");
			}
			if (_selectmenunum == _maxmenu) {
			}
			else {
				_selectmenunum++;
			}
		}
		else if (GetAsyncKeyState(VK_UP) & 0x0001) {
			for (int i = 0; i < 6; i++)
			{
				Gotoxy(SelectMenux * 2 - 16, Selectmenuy + 10 + i + _selectmenunum * 7, 15, 0);
				printf("          ");
			}
			if (_selectmenunum == _lowmenu) {
			}
			else {
				_selectmenunum--;
			}
		}

		if ((GetAsyncKeyState(VK_RIGHT) & 0x0001) && _selectmenunum == 0) {
			if (_selectmusicnum == _maxnum) {
			}
			else {
				_selectmusicnum++;
				g_Color = rand() % 8 + 8;
				Playsound(_selectmusicnum + 1);
				system("cls");
				PrintfSelectMenu(_selectmusicnum);

			}
		}
		else if ((GetAsyncKeyState(VK_LEFT) & 0x0001) && _selectmenunum == 0) {
			if (_selectmusicnum == _lownum) {
			}
			else {
				g_Color = rand() % 8 + 8;
				_selectmusicnum--;
				Playsound(_selectmusicnum + 1);
				system("cls");
				PrintfSelectMenu(_selectmusicnum);
			}

		}

		if (GetAsyncKeyState(VK_RETURN) & 0x0001) {
			PauseMusic();
			// ���� ���� â���� CHOICE�� ������ ��, ������ ������ ������ ������
			if (_selectmenunum == 0) {
				// Megalovania ����
				if (_selectmusicnum == 0) {
					PlayMusic(_selectmusicnum, _keyInputMegalovania, _MusicNotesMegalovania, sizeof(_MusicNotesMegalovania) / sizeof(_MusicNotesMegalovania[0]), g_Musicinfo[_selectmusicnum]._bpm);
				}
				// KKHouse ����
				else if (_selectmusicnum == 1) {
					PlayMusic(_selectmusicnum, _keyInputKKHouse, _MusicNotesKKHouse, sizeof(_MusicNotesKKHouse) / sizeof(_MusicNotesKKHouse[0]), g_Musicinfo[_selectmusicnum]._bpm);
				}
				// ���� ������ ����
				else if (_selectmusicnum == 2) {
					PlayMusic(_selectmusicnum, _keyInputMario, _MusicNotesMario, sizeof(_MusicNotesMario) / sizeof(_MusicNotesMario[0]), g_Musicinfo[_selectmusicnum]._bpm);
				}
			}
			// ���� ���� â���� EXIT�� ������ ��, �Լ� ����(���� ȭ������ ���ư�)
			else if (_selectmenunum == 1) {
				break;
			}
			// ������ ���� ������ ���ھ� �Է��� ���� ���, �ٽ� ���� ���� ȭ���� �׸��� ���� �Լ�
			PrintfSelectMenu(_selectmusicnum);
		}

		// ���� ���� ȭ���� ȭ��ǥ(��)�� �׸��� ó��
		for (int i = 0; i < 6; i++)
		{
			Gotoxy(SelectMenux * 2 - 16, Selectmenuy + 10 + i + _selectmenunum * 7, 15, 0);
			printf("%s", g_startmenuText[3][i]);
		}
	}

}

/// <summary>
/// ���� ȭ���� Ÿ��Ʋ�� ǥ���ϴ� �Լ�
/// </summary>
void LoadStartmenuUI() {
	static clock_t _befortime = clock();
	clock_t _nowtime = clock();

	if (_nowtime - _befortime > 200) {
		static int _color = 1;
		_befortime = clock();

		for (int i = 0; i < 12; i++)
		{
			_color++;
			Gotoxy(Logox * 2, Logoy + i, 0, 1 + (_color % 14));
			printf("%s", g_logoText[0][i]);
		}
		for (int i = 0; i < 12; i++)
		{
			_color++;
			Gotoxy(Logox * 2 + 24, Logoy + i + 12, 0, 1 + (_color % 14));
			printf("%s", g_logoText[1][i]);
		}

		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 6; i++)
			{
				Gotoxy(Menux * 2, Menuy + i + 8 * j, 15, 0);
				printf("%s", g_startmenuText[j][i]);
			}
		}
	}
}

/// <summary>
/// ���� ���� ȭ�鿡�� �����̴� ���� �ٸ� ����ϴ� �Լ�
/// </summary>
/// <param name="_bpm"></param>
void SetMusicbar(int _bpm) {

	static clock_t s_starttime = clock();
	clock_t _nowtime = clock();
	int high = 40;
	static int _randnum[8] = { rand() % high + 2 , rand() % high + 2 ,rand() % high + 2 , rand() % high + 2 ,rand() % high + 2 ,rand() % high + 2 ,rand() % high + 2 , rand() % high + 2 };

	if (_nowtime - s_starttime > 10000 / _bpm / 2) {
		s_starttime = clock();


		for (int i = 0; i < 8; i++)
		{
			for (int j = _randnum[i]; j < high; j++)
			{
				Gotoxy((SelectMenux - 1) * 2 + i * 8, Selectmenuy - 8 - j, 15, 0);
				printf("      ");
			}
		}
		for (int i = 0; i < 8; i++)
		{

			_randnum[i] -= rand() % 3;
			if (_randnum[i] < 3) {
				_randnum[i] = rand() % 3 + high - 3;

			}

			for (int j = 0; j < _randnum[i]; j++) {
				Gotoxy((SelectMenux - 1) * 2 + i * 8, Selectmenuy - 8 - j, g_Color, 0);
				printf("����");

			}
		}

	}

}


/// <summary>
/// ���� ���� ȭ�鿡�� ���� ������ �޴����� ���ڸ� ����ϴ� �Լ�
/// �ۼ���: �ż���
/// </summary>
/// <param name="_selectmusicnum"></param>
void PrintfSelectMenu(int _selectmusicnum)
{
	Gotoxy(SelectMenux * 2, Selectmenuy, 15, 0);
	for (int i = 0; i < MusicInfoTitleLine; i++)
	{
		Gotoxy(1, 1 + i, 15, 0);
		printf("%s", g_Musicinfo[_selectmusicnum]._name[i]);
	}
	for (int i = 0; i < MusicInfoSelectLine; i++)
	{
		Gotoxy(SelectMenux * 2, Selectmenuy - 5 + i, 15, 0);
		printf("%s", g_textBPM[i]);
	}
	for (int i = 0; i < MusicInfoSelectLine; i++)
	{
		Gotoxy(SelectMenux * 2, Selectmenuy + 10 + i, 15, 0);
		printf("%s", g_textchoice[i]);
	}

	for (int i = 0; i < MusicInfoSelectLine; i++)
	{
		Gotoxy(SelectMenux * 2, Selectmenuy + 17 + i, 15, 0);
		printf("%s", g_startmenuText[1][i]);
	}
}

/// <summary>
/// ũ���� ȭ���� �׸��� �Լ�
/// </summary>
void PrintCredits()
{
	system("cls");
	
	// ũ���� ȭ�� BGM
	Playsound(4);

	// ������ Ÿ��Ʋ
	char _creditsNamesTitle[15][150] =
	{
			{" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. "},
			{"| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |"},
			{"| |     ______   | || |  _______     | || |  _________   | || |      __      | || |  _________   | || |     ____     | || |  _______     | |"},
			{"| |   .' ___  |  | || | |_   __ 1    | || | |_   ___  |  | || |     /  1     | || | |  _   _  |  | || |   .'    `.   | || | |_   __ 1    | |"},
			{"| |  / .'   1_|  | || |   | |__) |   | || |   | |_  1_|  | || |    / /1 1    | || | |_/ | | 1_|  | || |  /  .--.  1  | || |   | |__) |   | |"},
			{"| |  | |         | || |   |  __ /    | || |   |  _|  _   | || |   / ____ 1   | || |     | |      | || |  | |    | |  | || |   |  __ /    | |"},
			{"| |  1 `.___.'1  | || |  _| |  1 1_  | || |  _| |___/ |  | || | _/ /    1 1_ | || |    _| |_     | || |  1  `--'  /  | || |  _| |  1 1_  | |"},
			{"| |   `._____.'  | || | |____| |___| | || | |_________|  | || ||____|  |____|| || |   |_____|    | || |   `.____.'   | || | |____| |___| | |"},
			{"| |              | || |              | || |              | || |              | || |              | || |              | || |              | |"},
			{"| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |"},
			{" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' "}
	};

	// ������
    char _creditsNames[1][26][100] =
    {
        {
			{"                _  __                       __  __ _          ____  _    _ "},
			{"               | |/ /                      |  1/  (_)        / __ 1| |  | |"},
			{"               | ' /_   _ _   _ _ __   __ _| 1  / |_ _ __   | |  | | |__| |"},
			{"               |  <| | | | | | | '_ 1 / _` | |1/| | | '_ 1  | |  | |  __  |"},
			{"               | . 1 |_| | |_| | | | | (_| | |  | | | | | | | |__| | |  | |"},
			{"               |_|1_1__, |1__,_|_| |_|1__, |_|  |_|_|_| |_|  1____/|_|  |_|"},
			{"                     __/ |             __/ |                               "},
			{"                    |___/             |___/                                "},
			{""},
			{"   _____                        _    _                           _____ _    _ _____ _   _ "},
			{"  / ____|                      | |  | |                         / ____| |  | |_   _| 1 | |"},
			{" | (___   ___  ___  _ __   __ _| |__| |_   _  ___  ___  _ __   | (___ | |__| | | | |  1| |"},
			{"  1___ 1 / _ 1/ _ 1| '_ 1 / _` |  __  | | | |/ _ 1/ _ 1| '_ 1   1___ 1|  __  | | | | . ` |"},
			{"  ____) |  __/ (_) | | | | (_| | |  | | |_| |  __/ (_) | | | |  ____) | |  | |_| |_| |1  |"},
			{" |_____/ 1___|1___/|_| |_|1__, |_|  |_|1__, |1___|1___/|_| |_| |_____/|_|  |_|_____|_| 1_|"},
			{"                           __/ |        __/ |                                             "},
			{"                          |___/        |___/                                              "},
			{""},
            {"         _____                         _____                _____ _    _ _____ __  __ "},
			{"        / ____|                       / ____|              / ____| |  | |_   _|  1/  |"},
			{"       | (___   ___ _   _ _ __   __ _| (___   ___   ___   | (___ | |__| | | | | 1  / |"},
			{"        1___ 1 / _ 1 | | | '_ 1 / _` |1___ 1 / _ 1 / _ 1   1___ 1|  __  | | | | |1/| |"},
			{"        ____) |  __/ |_| | | | | (_| |____) | (_) | (_) |  ____) | |  | |_| |_| |  | |"},
			{"       |_____/ 1___|1__,_|_| |_|1__, |_____/ 1___/ 1___/  |_____/|_|  |_|_____|_|  |_|"},
			{"                                 __/ |                                                "},
			{"                                |___/                                                 "}
        }
    };

	// Please Enter
	char _creditsEnter[6][65] =
	{
		{"      |1                                                       "},
		{" _____| 1     _____ _                    _____     _           "},
		{"|        1   |  _  | |___ ___ ___ ___   |   __|___| |_ ___ ___ "},
		{"|_____   /   |   __| | -_| .'|_ -| -_|  |   __|   |  _| -_|  _|"},
		{"      | /    |__|  |_|___|__,|___|___|  |_____|_|_|_| |___|_|  "},
		{"      |/                                                       "}
	};

	// ũ���� ȭ�� ���
	while (1)
	{
		// ������ Ÿ��Ʋ ��� ó��
		for (int i = 0; i < sizeof(_creditsNamesTitle) / sizeof(_creditsNamesTitle[0]); i++)
		{
			Gotoxy(32, 3 + i, 15, 0);
			printf("%s", _creditsNamesTitle[i]);
		}

		// ������ ��� ó��
		for (int i = 0; i < sizeof(_creditsNames[0]) / sizeof(_creditsNames[0][0]); i++)
		{
			Gotoxy(57, 17 + i, 15, 0);
			printf("%s", _creditsNames[0][i]);
		}

		// Please Enter ���
		for (int i = 0; i < sizeof(_creditsEnter) / sizeof(_creditsEnter[0]); i++)
		{
			Gotoxy(67, 52 + i, 15, 0);
			printf("%s", _creditsEnter[i]);
		}

		// EnterŰ�� ������ ������� �����ϰ� �Լ� ����(���� ȭ������ ���ư�)
		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			PauseMusic();
			system("cls");
			break;
		}
	}
}