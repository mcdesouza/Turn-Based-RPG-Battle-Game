#include "Character.h"


Character::Character(string name, int health, int level, int xp, string condition) : name(name),health(health),level(level),xp(xp),condition(condition) {
    maxHealth = health;
}

// Resting provides some healing attributes but mainly attributes to Condition
void Character::Rest() {
    if (condition == "Good")
        health += 10;
    else if (condition == "Moderate") {
        condition = "Good";
        health += 5;
    }
    else if (condition == "Poor") {
        condition = "Moderate";
        health += 2;
    }
    if (health > maxHealth) {
        health = maxHealth;
    }
}
void Character::Heal() {
    health += 10;
    if (health > maxHealth) {
        health = maxHealth;
    }
}
void Character::AddEXP() {
    xp += 10;
    if (xp == 100) {
        LevelUp();
        xp = 0;
    }
}
int Character::getHealth() {
    return health;
}
int Character::getLevel() {
    return level;
}
string Character::getName() {
    return name;
}
string Character::getCondition() {
    return condition;
}
void Character::setHealth(int health) {
    this->health = health;
}
void Character::setLevel(int level) {
    this->level = level;
}

void Character::LevelUp() {
    level++;
    maxHealth += 10;
    health = maxHealth;
    cout << name << " has leveled up." << endl;
    cout << "Current level: " << level << "." << endl;
    cout << "Max health has increased" << endl;
    cout << "Current health: " << maxHealth << "." << endl;
}
void Character::PrintInfo() {
    cout << "Name: " << getName() << endl;
    cout << "Current Health: " << getHealth() << endl;
    cout << "Current Condition: " << getCondition() << endl;
}
void Character::saveGame(ofstream& fout) {
    fout << name << endl;
    fout << condition << endl;
    fout << level << endl;
    fout << health << endl;
    fout << maxHealth << endl;
    fout << xp << endl;
}
void Character::loadGame(ifstream& fin) {
    getline(fin, name);
    getline(fin, condition);
    fin >> level;
    fin >> health;
    fin >> maxHealth;
    fin >> xp;
}
void Character::setCondition(string condition) {
    this->condition = condition;
}
// MAKE SURE TO CLOSE FIN AND FOUT

