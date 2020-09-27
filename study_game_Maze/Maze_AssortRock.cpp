/*
미로찾기

필요조건 : 20 * 20 크기의 미로, 시작점과 끝점, 움직이는 캐릭터, 도착
예외조건 : 벽이 막혀있을 때 움직이면 안됨, 잘못된 입력(상하좌우를 제외한 입력)

규칙
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
*/
#include<iostream>
#include<conio.h> //키를 누르면 바로 반응하게하기 위해서 쓰는 헤더

using namespace std;

int InputInt() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');

		return INT_MAX;
	}
	return iInput;
}

struct _tagPoint {
	int x;
	int y;
};

//typedef : 타입을 재정의하는 기능이다(별명 생성)
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos) {

	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 18;
	pEndPos->y = 19;

	pPlayerPos->x = 0;
	pPlayerPos->y = 0;

	strcpy(Maze[0], "2000000000000000000");
	strcpy(Maze[1], "1111111100000000000");
	strcpy(Maze[2], "0010000100001111000");
	strcpy(Maze[3], "0110001111111001000");
	strcpy(Maze[4], "0011110001000001000");
	strcpy(Maze[5], "0010000011000001000");
	strcpy(Maze[6], "0010000001100001000");
	strcpy(Maze[7], "0010001111111111100");
	strcpy(Maze[8], "0011001000010000100");
	strcpy(Maze[9], "0000001111010000100");
	strcpy(Maze[10], "0000001000011001100");
	strcpy(Maze[11], "0000001000001001100");
	strcpy(Maze[12], "0111111000001001000");
	strcpy(Maze[13], "0100000000001001000");
	strcpy(Maze[14], "0110000111111000011");
	strcpy(Maze[15], "0000111100100000010");
	strcpy(Maze[16], "0011100000111111110");
	strcpy(Maze[17], "0010000000100000000");
	strcpy(Maze[18], "1110000000111100000");
	strcpy(Maze[19], "1000000000000111113");
}

void OutPutMaze(char Maze[21][21], PPOINT pPlayerPos) {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "★";
			else if (Maze[i][j] == '0')
				cout << "■";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "○";
			else if (Maze[i][j] == '3')
				cout << "◎";
		}
		cout << endl;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y -1 >= 0) {
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0') {
			pPlayerPos->y -= 1;
		}
		else
			return;
	}
	else
		return;
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->y +1 <= 19) {
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0') {
			pPlayerPos->y += 1;
		}
		else
			return;
	}
	else
		return;
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x + 1 <= 18) {
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0') {
			pPlayerPos->x += 1;
		}
		else
			return;
	}
	else
		return;
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos) {
	if (pPlayerPos->x - 1 >= 0) {
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0') {
			pPlayerPos->x -= 1;
		}
		else
			return;
	}
	else
		return;
}

void PlayerMove(char Maze[21][21], PPOINT pPlayerPos, char cInput) {
	switch (cInput) {
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}

int main() {
	bool bRun = true;
	char strMaze[21][21] = {};

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos); //미로 설정

	while (bRun) {
		
		OutPutMaze(strMaze, &tPlayerPos);//미로 출력
		cout << "w = 위, s = 아래, a = 왼쪽, d = 오른쪽, q = 종료 : ";
		char cInput = _getch();

		if (cInput == 'q' || cInput == 'Q') {
			cout << "게임을 종료하셨습니다." << endl;
			break;
		}

		PlayerMove(strMaze, &tPlayerPos, cInput);

		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y) {
			cout << endl << "축하합니다! 도착하셨습니다!";
			break;
		}
		system("cls");
	}
	return 0;
}