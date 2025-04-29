#include "Swordsman.h"

Swordsman::Swordsman(string name) : Character(name), swordCondition(100), maxSwordCondition(100) {
    slashes[0].name = "Flame Slash";
    slashes[0].damage = 15;
    slashes[0].impact = 10;

    slashes[1].name = "Ice Cut";
    slashes[1].damage = 20;
    slashes[1].impact = 20;

    slashes[2].name = "Swift Blade";
    slashes[2].damage = 25;
    slashes[2].impact = 30;

    slashes[3].name = "Divine Swordstrike";
    slashes[3].damage = 50;
    slashes[3].impact = 65;
}

void Swordsman::Rest() {
    Character::Rest();
    swordCondition += 15;
    if (swordCondition > maxSwordCondition) {
        swordCondition = maxSwordCondition;
    }
}

void Swordsman::Heal() {
    Character::Heal();
    swordCondition += 5;
    if (swordCondition > maxSwordCondition) {
        swordCondition = maxSwordCondition;
    }
}

void Swordsman::AddEXP() {
    xp += 10;
    if (xp == 100) {
        LevelUp();
        xp = 0;
    }
}

void Swordsman::LevelUp() {
    level++;
    maxHealth += 10;
    maxSwordCondition += 10;
    health = maxHealth;
    swordCondition = maxSwordCondition;
    cout << "Swordsman " << name << " has leveled up." << endl;
}

int Swordsman::getSwordCondition() {
    return swordCondition;
}

void Swordsman::setSwordCondition(int swordCondition) {
    this->swordCondition = swordCondition;
}

void Swordsman::showAttacks() {
    for (int i = 0; i < 4; i++) {
        cout << i+1 << ") " << slashes[i].name << " | Damage: " << slashes[i].damage << " | Impact: -" << slashes[i].impact << " sword condition." << endl;
    }
}

bool Swordsman::Attack(Character& character, AttackData attack) {
    if (swordCondition >= attack.impact) {
        setSwordCondition(swordCondition - attack.impact);
        character.setHealth(character.getHealth() - attack.damage);
        cout << getName() << " used " << attack.name << " on " << character.getName() << endl;
        cout << "Successfully dealt " << attack.damage << " damage!" << endl;
        AddEXP();
        return true;
    } else {
        cout << getName() << " tried to use " << attack.name << " but doesn't have high enough sword condition." << endl;
        return false;
    }
}
void Swordsman::PrintInfo() {
    Character::PrintInfo();
    cout << "Current Sword Condition: " << getSwordCondition() << endl;
}

void Swordsman::Image() {
    cout << R"(
      _,.
    ,` -.)
   ( _/-\\-._
  /,|`--._,-^|            ,
  \_| |`-._/||          ,'|
    |  `-, / |         /  /
    |     || |        /  /
     `r-._||/   __   /  /
 __,-<_     )`-/  `./  /
'  \   `---'   \   /  /
    |           |./  /
    /           //  /
\_/' \         |/  /
 |    |   _,^-'/  /
 |    , ``  (\/  /_
  \,.->._    \X-=/^
  (  /   `-._//^`
   `Y-.____(__}
    |     {__)
          ()
  )" << endl;
}
// Art by Joan Stark, Source: https://www.asciiart.eu/people/occupations/knights
AttackData Swordsman::getAttack(int i){
    return slashes[i-1];
}
void Swordsman::saveGame(ofstream& fout) {
    Character::saveGame(fout);
    fout << swordCondition << endl;
    fout << maxSwordCondition << endl;
}
void Swordsman::loadGame(ifstream& fin) {
    Character::loadGame(fin);
    fin >> swordCondition;
    fin >> maxSwordCondition;
}