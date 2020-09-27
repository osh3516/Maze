/*
�̷�ã�� 

�ʿ����� : 20 * 20 ũ���� �̷�, �������� ����, �����̴� ĳ����, ����
�������� : ���� �������� �� �����̸� �ȵ�, �߸��� �Է�(�����¿츦 ������ �Է�)

��Ģ
0 : ��
1 : ��
2 : ������
3 : ������
*/
#include<iostream>
#include<conio.h> //Ű�� ������ �ٷ� �����ϰ��ϱ� ���ؼ� ���� ���

using namespace std;

enum MAP_ELEMEMT {
	ME_WALL,
	ME_ROAD,
	ME_STARTPOINT,
	ME_ENDPOINT
};

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

void SetMaze(char Maze[20][20]) {
	/*
	��Ģ
0 : ��
1 : ��
2 : ������(ĳ����)
3 : ������
	*/
	strcpy(Maze[0],  "0000000000000000000");
	strcpy(Maze[1],  "2111111100000000000");
	strcpy(Maze[2],  "0010000100001111000");
	strcpy(Maze[3],  "0110001111111001000");
	strcpy(Maze[4],  "0011110001000001000");
	strcpy(Maze[5],  "0010000011000001000");
	strcpy(Maze[6],  "0010000001100001000");
	strcpy(Maze[7],  "0010001111111111100");
	strcpy(Maze[8],  "0011001000010000100");
	strcpy(Maze[9],  "0000001111010000100");
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

void OutPutMaze(char Maze[20][20]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (Maze[i][j] == '0')
				cout << "��";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "��";
			else if (Maze[i][j] == '3')
				cout << "��";
		}
		cout << endl;
	}
}

void MovePlayer(char Move, char Maze[20][20]) {
	int iPlayerIndex1=0, iPlayerIndex2=0;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (Maze[i][j] == '2') {
				iPlayerIndex1 = i;
				iPlayerIndex2 = j;
			}
		}
	}

	if (Move == 'w' || Move == 'W') {
		if (Maze[iPlayerIndex1 - 1][iPlayerIndex2] == '0')
			return;
		else {
			Maze[iPlayerIndex1 - 1][iPlayerIndex2] = '2';
			Maze[iPlayerIndex1][iPlayerIndex2] = '1';
		}
	}
	else if (Move == 's' || Move == 'S') {
		if (Maze[iPlayerIndex1 + 1][iPlayerIndex2] == '0')
			return;
		else {
			Maze[iPlayerIndex1 + 1][iPlayerIndex2] = '2';
			Maze[iPlayerIndex1][iPlayerIndex2] = '1';
		}
	}
	else if (Move == 'a' || Move == 'A') {
		if (Maze[iPlayerIndex1][iPlayerIndex2-1] == '0')
			return;
		else {
			Maze[iPlayerIndex1][iPlayerIndex2 - 1] = '2';
			Maze[iPlayerIndex1][iPlayerIndex2] = '1';
		}

	}
	else if (Move == 'd' || Move == 'D') {
		if (Maze[iPlayerIndex1][iPlayerIndex2+1] == '0')
			return;
		else {
			Maze[iPlayerIndex1][iPlayerIndex2 + 1] = '2';
			Maze[iPlayerIndex1][iPlayerIndex2] = '1';
		}
	}
}

int main() {
	bool bRun = true;
	char strMaze[20][20] = {};

	SetMaze(strMaze); //�̷� ����

	while (bRun) {
		system("cls");
		OutPutMaze(strMaze);//�̷� ���
		cout << "w = ��, s = �Ʒ�, a = ����, d = ������, q = ���� : ";
		char cInput = _getch();
	
		if (cInput == 'q' || cInput == 'Q') {
			cout << "������ �����ϼ̽��ϴ�." << endl;
			break;
		}

		MovePlayer(cInput, strMaze);	
		
		if (strMaze[19][18] != '3') {
			cout << "�����մϴ�! �̷� Ż�⿡ �����ϼ̽��ϴ�." << endl;
			break;
		}

	}
	return 0;
}