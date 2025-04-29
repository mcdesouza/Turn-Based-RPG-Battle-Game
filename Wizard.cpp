#include "Wizard.h"

Wizard::Wizard(string name) : Character(name), mana(100), maxMana(100){
    spells[0].name = "Firebolt";
    spells[0].damage = 15;
    spells[0].impact = 10;

    spells[1].name = "Lightning Spell";
    spells[1].damage = 25;
    spells[1].impact = 40;

    spells[2].name = "Ice Blast";
    spells[2].damage = 20;
    spells[2].impact = 20;

    spells[3].name = "Ultimate Underworld Flames";
    spells[3].damage = 50;
    spells[3].impact = 70;
}
void Wizard::Rest() {
    Character::Rest();
    mana += 15;
    if (mana > maxMana) {
        mana = maxMana;
    }
}
void Wizard::Heal() {
    Character::Heal();
    mana += 5;
    if (mana > maxMana) {
        mana = maxMana;
    }
}
void Wizard::AddEXP() {
    xp += 10;
    if (xp == 100) {
        LevelUp();
        xp = 0;
    }
}
void Wizard::LevelUp() {
    level++;
    maxHealth += 10;
    maxMana += 5;
    health = maxHealth;
    mana = maxMana;
    cout << "Wizard " << name << " has leveled up." << endl;
    cout << "Current level: " << level << "." << endl;
    cout << "Max health has increased" << endl;
    cout << "Current health: " << maxHealth << "." << endl;
    cout << "Max mana has increased" << endl;
    cout << "Current mana: " << maxMana << "." << endl;
}
int Wizard::getMana() {
    return mana;
}
void Wizard::setMana(int mana) {
    this->mana = mana;
}
void Wizard::showAttacks() {
    for (int i = 0; i < 4; i++) {
        cout << i+1 << ") " << spells[i].name << " | Damage: " << spells[i].damage << " | Impact: -" << spells[i].impact << " mana." << endl;
    }
}
// choose attack and character target,
bool Wizard::Attack(Character& character, AttackData attack) {
    if (mana >= attack.impact) {
        setMana(mana - attack.impact);
        character.setHealth(character.getHealth() - attack.damage);
        cout << getName() << " used " << attack.name << " on " << character.getName() << endl;
        cout << "Successfully dealt " << attack.damage << " damage!" << endl;
        AddEXP();
        return true;
    }
    else {
        cout << getName() << " tried to use " << attack.name << " but doesn't have enough mana." << endl;
        return false;
    }
}
void Wizard::PrintInfo() {
    Character::PrintInfo();
    cout << "Current Mana: " << getMana() << endl;
}
void Wizard::Image() {

    cout << R"(
                    ____
                  .'* *.'
               __/_*_*(_
              / _______ \
             _\_)/___\(_/_
            / _((\- -/))_ \
            \ \())(-)(()/ /
             ' \(((()))/ '
            / ' \)).))/ ' \
           / _ \ - | - /_  \
          (   ( .;''';. .'  )
          _\"__ /    )\ __"/_
            \/  \   ' /  \/
             .'  '...' ' )
              / /  |  \ \
             / .   .   . \
            /   .     .   \
           /   /   |   \   \
         .'   /    b    '.  '.
     _.-'    /     Bb     '-. '-._
 _.-'       |      BBb       '-.  '-.
(________mrf\____.dBBBb.________)____)
)" << endl;
}
// Art by Morfina, Source: https://www.asciiart.eu/people/occupations/wizards
AttackData Wizard::getAttack(int i){
    return spells[i-1];
}
void Wizard::saveGame(ofstream& fout) {
    Character::saveGame(fout);
    fout << mana << endl;
    fout << maxMana << endl;
}
void Wizard::loadGame(ifstream& fin) {
    Character::loadGame(fin);
    fin >> mana;
    fin >> maxMana;
}
/*
bool attackSuccess = false;
while (!attackSuccess) {
    displaySpells(); // maybe shows available spells and mana costs
    int choice = getPlayerChoice();
    AttackData chosenSpell = spells[choice];

    attackSuccess = wizard.Attack(enemy, chosenSpell);
    if (!attackSuccess) {
        cout << "Choose another spell.\n";
    }
}
*/