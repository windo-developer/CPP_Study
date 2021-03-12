#include <iostream>
using namespace std;


enum PlayerType
{
	PT_Knight = 1,
	PT_Archer,
	PT_Mage,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc,
	MT_Skeleton,
};

struct StatInfo
{
	int type;
	int hp;
	int attack;
	int defence;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
void CreateRandomMonster();
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);

int main()
{
	srand(time(nullptr)); // 랜덤 시드

	EnterLobby();

	return 0;
}

void EnterLobby()
{
	while (true)
	{
		PrintMessage("로비에 입장했습니다.");

		// 캐릭터 생성
		StatInfo playerInfo;
		CreatePlayer(&playerInfo);
		PrintStatInfo("Player", playerInfo);

		EnterGame(&playerInfo);

		/*cout << "--------------------------" << endl;
		cout << "(1) 게임 시작 (2) 게임 종료" << endl;
		cout << "--------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}*/
	}
}

void PrintMessage(const char* msg)
{
	cout << "------------------------" << endl;
	cout << msg << endl;
	cout << "------------------------" << endl;
}

void CreatePlayer(StatInfo* playerInfo)
{
	bool isPlayerCreate = false;

	while (!isPlayerCreate)
	{
		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사 [2] 궁수 [3] 마법사");
		cout << "> ";

		int input;
		cin >> input;

		switch (input)
		{
		case PT_Knight:
			playerInfo->hp = 100;
			playerInfo->attack = 10;
			playerInfo->defence = 5;
			isPlayerCreate = true;
			break;
		case PT_Archer:
			playerInfo->hp = 80;
			playerInfo->attack = 15;
			playerInfo->defence = 3;
			isPlayerCreate = true;
			break;
		case PT_Mage:
			playerInfo->hp = 50;
			playerInfo->attack = 25;
			playerInfo->defence = 0;
			isPlayerCreate = true;
			break;
		default:
			break;
		}
	}
}

void PrintStatInfo(const char* name, const StatInfo& info)
{
	cout << "************************" << endl;
	cout << name << " HP: " << info.hp << " ATK: " << info.attack << " DEF: " << info.defence << endl;
	cout << "************************" << endl;
}

void EnterGame(StatInfo* playerInfo)
{
	const int MONSTER_COUNT = 2;

	PrintMessage("게임에 입장했습니다");

	while (true)
	{
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);

		for (int i = 0; i < MONSTER_COUNT; i++)
		{
			PrintStatInfo("Monster", monsterInfo[i]);
		}

		PrintStatInfo("Player", *playerInfo);

		PrintMessage("[1] 전투 [2] 도주");

		int input;
		cin >> input;

		if (input == 1)
		{
			int index = input - 1;
			bool victory = EnterBattle(playerInfo, &monsterInfo[index]);

			if (!victory)
				break;
		}
	}
}

void CreateMonsters(StatInfo monsterInfo[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int randValue = 1 + (rand() % 3);

		switch (randValue)
		{
		case MT_Slime:
			monsterInfo[i].hp = 30;
			monsterInfo[i].attack = 5;
			monsterInfo[i].defence = 1;
			break;
		case MT_Orc:
			monsterInfo[i].hp = 50;
			monsterInfo[i].attack = 15;
			monsterInfo[i].defence = 5;
			break;
		case MT_Skeleton:
			monsterInfo[i].hp = 100;
			monsterInfo[i].attack = 35;
			monsterInfo[i].defence = 10;
			break;
		default:
			break;
		}
	}
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo)
{
	while (true)
	{
		// 플레이어의 공격
		int damage = playerInfo->attack - monsterInfo->defence;
		if (damage < 0)
			damage = 0;

		monsterInfo->hp -= damage;
		if (monsterInfo->hp < 0)
			monsterInfo->hp = 0;

		PrintStatInfo("Monster", *monsterInfo);

		if (monsterInfo->hp == 0)
		{
			PrintMessage("몬스터를 처치했습니다!");
			cout << endl;
			return true;
		}

		// 몬스터의 공격
		damage = monsterInfo->attack - playerInfo->defence;
		if (damage < 0)
			damage = 0;

		playerInfo->hp -= damage;
		if (playerInfo->hp < 0)
			playerInfo->hp = 0;

		PrintStatInfo("Player", *playerInfo);

		if (playerInfo->hp == 0)
		{
			PrintMessage("플레이어가 사망했습니다.");
			cout << endl;
			return false;
		}
	}
}