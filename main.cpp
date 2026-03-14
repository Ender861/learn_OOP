
#include <iostream>
#include <string>
using namespace std;


class Character {
public:
	string name;
	int health;
	int damage;

	Character(string n, int hp, int dmg) {
		name = n;
		health = hp;
		damage = dmg;
		
		cout << "Создан персонаж: " << name << "(HP: " << health << ")\n" << endl;
	}

	virtual void specialAttack() = 0;

	void attack() {
		cout << name << " атакует с силой: " << damage << endl;
	}

	virtual ~Character() {
		cout << "Персонаж: " << name << " покинул бой!" << endl;
	}

};
class Scorpion : public Character {
public:
	Scorpion(string n) : Character(n, 1000, 20) {
		cout << "Создан персонаж: Scorpion" << endl;
	}

	void specialAttack() override {
		cout << name << " использует огненную цепь!" << endl;
	}

	void FireChain() {
		cout << name << " атакует огненной цепью" << endl;
	}

	~Scorpion() {
		cout << " Scorpion скрылся в преисподнии" << endl;
	}
};

class SubZero : public Character {
public:
	SubZero(string n) : Character(n, 1100, 20) {
		cout << "Создан персонаж: Sub-zero" << endl;
	}

	void specialAttack() override {
		cout << name << " использует ледяной шар!" << endl;
	} 

	void IceBall(){
		cout << name << " атакует ледяным шаром" << endl;
	}

	~SubZero() {
		cout << " Sub_zero скрылся во льдах" << endl;
	}
};


class Noob : public Character {
public:
	Noob(string n) : Character(n, 800, 5) {
		cout << "Персонаж создан: Noob" << endl;
	}

	void specialAttack() override {
		cout << name << " бросает песок в глаза" << endl;
	}

	void cry() {
		cout << name << " плачет" << endl;
	}

	~Noob() {
		cout << "Noob сбегает с боя" << endl;
	}
};


class Cyrax : public Character {
public:
	Cyrax(string n) : Character(n, 1200, 30) {

		cout << "Создан персонаж: Cyrax" << endl;
	}

	void specialAttack() override {
		cout << name << " атакует двойными ракетами" << endl;
	}

	void ChestMissile() {
		cout << name << " выпускает ракету из груди" << endl;
	}

	~Cyrax() {
		cout << name << "Cyrax разлетается по частям" << endl;
	}

};


class Weapon {
public:
	int damage_weapon;

	Weapon(int DmgW) {
		damage_weapon = DmgW;
	}

	virtual void abilityWeapon() = 0;

	void attack() {
		cout << "атакует с силой: " << damage_weapon << endl;
	}

	virtual ~Weapon() {
		cout << "Пропал" << endl;
	}

};

class Sword : public Weapon {
public:
	Sword(int DmgW) : Weapon(DmgW) {
		cout << "Создан меч" << endl;
	}

	void abilityWeapon() override {
		int disappearance = 5;
		cout << "Наносит постепенный урон исчезновения: " << disappearance << "\n" << endl;
	}

	~Sword() {
		cout << "Пропал с продажи" << endl;
	}
};


class Bow : public Weapon {
public:
	Bow(int DmgW) : Weapon(DmgW) {
		cout << "Создан лук" << endl;
	}

	void abilityWeapon() override {
		int bleeding = 10;

		cout << "Оставляет кровотечение с уроном: " << bleeding << "\n" << endl;
	}

	~Bow() {
		cout << "Пропал с продажи" << endl;
	}

};


class Staff : public Weapon {
public:
	Staff(int DmgW) : Weapon(DmgW) {
		cout << "Создан посох" << endl;
	}

	void abilityWeapon() override {
		int burning = 15;

		cout << "Оставляет огонь с уроном: " << burning << endl;
	}

	~Staff() {
		cout << "Пропал с карты" << endl;
	}

};


int main() {
	setlocale(LC_ALL, "RU");
	cout << "=== СОЗДАЁМ ПЕРСОНАЖЕЙ ===\n";
	Scorpion scr("Scorpion");
	SubZero su("Sub-Zero");
	Noob n("Noob");
	Cyrax cy("Cyrax");

	cout << "\n=== ОБЫЧНЫЕ ВЫЗОВЫ ===\n";

	scr.attack();
	su.attack();
	n.attack();
	cy.attack();

	scr.FireChain();
	su.IceBall();
	n.cry();
	cy.ChestMissile();

	cout << "\n=== ПОЛИМОРФИЗМ (через указатели) ===\n";

	// Создаём массив указателей на Character
	Character* fighters[4];
	fighters[0] = new Scorpion("Scorpion(в бою)");
	fighters[1] = new SubZero("Sub_zero(в бою)");
	fighters[2] = new Noob("Noob(в бою, осваивается)");
	fighters[3] = new Cyrax("Cyrax(В бою)");

	cout << "\n--- Вызов specialAttack() для всех---" << endl;

	for (int i = 0; i < 4; i++) {
		fighters[i]->specialAttack(); // Один вызов - разное поведение
	}

	cout << "\nnочистка памяти\n";
	for (int i = 0; i < 4; i++) {
		delete fighters[i]; //вызывутся правильные деструкторы
	}

	cout << "\n=== КОНЕЦ БИТВЫ===\n" << endl;



	cout << "=== СОЗДАЁМ ОРУЖИЕ ===\n";

	Sword sword(10);
	sword.attack();
	sword.abilityWeapon();

	Bow the_bow_of_war(15);
	the_bow_of_war.attack();
	the_bow_of_war.abilityWeapon();

	Staff the_fire_staff(10);
	the_fire_staff.attack();
	the_fire_staff.abilityWeapon();


	cout << "\n=== ПОЛИМОРФИЗМ (через указатели) ===\n";

	Weapon* weapons[3];
	weapons[0] = new Sword(10);
	weapons[1] = new Bow(15);
	weapons[2] = new Staff(10);

	for (int i = 0; i < 3; i++) {
		weapons[i]->abilityWeapon();
	}

	cout << "\n--- ОЧИСТКА ПАМЯТИ ---\n";

	for (int i = 0; i < 3; i++) {
		delete weapons[i];
	}

	return 0;
}