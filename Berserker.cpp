#include "Berserker.h"
Berserker::Berserker(string name) : Character(name), stamina(100), maxStamina(100) {
    strikes[0].name = "Rage Fist";
    strikes[0].damage = 15;
    strikes[0].impact = 15;

    strikes[1].name = "Earth Impact";
    strikes[1].damage = 30;
    strikes[1].impact = 45;

    strikes[2].name = "Blood Bash";
    strikes[2].damage = 25;
    strikes[2].impact = 25;

    strikes[3].name = "Iron Fist";
    strikes[3].damage = 45;
    strikes[3].impact = 60;
}

void Berserker::Rest() {
    Character::Rest();
    stamina += 15;
    if (stamina > maxStamina) {
        stamina = maxStamina;
    }
}

void Berserker::Heal() {
    Character::Heal();
    stamina += 5;
    if (stamina > maxStamina) {
        stamina = maxStamina;
    }
}

void Berserker::AddEXP() {
    xp += 10;
    if (xp == 100) {
        LevelUp();
        xp = 0;
    }
}

void Berserker::LevelUp() {
    level++;
    maxHealth += 15;
    maxStamina += 10;
    health = maxHealth;
    stamina = maxStamina;
    cout << "Berserker " << name << " has leveled up." << endl;
}

int Berserker::getStamina() {
    return stamina;
}

void Berserker::setStamina(int stamina) {
    this->stamina = stamina;
}

void Berserker::showAttacks() {
    for (int i = 0; i < 4; i++) {
        cout << i+1 << ") " << strikes[i].name << " | Damage: " << strikes[i].damage << " | Impact: -" << strikes[i].impact << " stamina." << endl;
    }
}

bool Berserker::Attack(Character& character, AttackData attack) {
    if (stamina >= attack.impact) {
        setStamina(stamina - attack.impact);
        character.setHealth(character.getHealth() - attack.damage);
        cout << getName() << " used " << attack.name << " on " << character.getName() << endl;
        cout << "Successfully dealt " << attack.damage << " damage!" << endl;
        AddEXP();
        return true;
    } else {
        cout << getName() << " tried to use " << attack.name << " but doesn't have enough stamina." << endl;
        return false;
    }
}

void Berserker::PrintInfo() {
    Character::PrintInfo();
    cout << "Current Stamina: " << getStamina() << endl;
}

void Berserker::Image() {
    cout << R"(
        |||||||||
        | _   _ |
       (  ' _ '  )
        |  ___  |
         |_____|
  _______/     \_______
 /                     \
|   |\             /|   |
|   ||  .       .  ||   |
|   / \           / \   |
\  |   | |_ | _| |   |  /
|==|   | |_ | _| |   |==|
/  /_ _|_|__|__|_|_ _\  \
|___| /            \|___|
     |      |       |
     |      |       |
     |      |       |
     |      |       |
      "|""|"""|""|""
       |  |   |  |      -Berserker-
       |  |   |  |
      /   )   (   \
     Ooooo     ooooO
      )" << endl;
}
// Author not shown, Source: https://www.asciiart.eu/sports-and-outdoors/boxing
AttackData Berserker::getAttack(int i){
    return strikes[i-1];
}
void Berserker::saveGame(ofstream& fout) {
    Character::saveGame(fout);
    fout << stamina << endl;
    fout << maxStamina << endl;
}
void Berserker::loadGame(ifstream& fin) {
    Character::loadGame(fin);
    fin >> stamina;
    fin >> maxStamina;
}