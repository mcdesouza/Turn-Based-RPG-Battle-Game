#ifndef WIZARD_H
#define WIZARD_H
#include "Character.h"

class Wizard: public Character {
public:
    ~Wizard() override{};
    Wizard(string);
    void Rest() override;
    void Heal() override;
    void AddEXP() override;
    void LevelUp() override;
    int getMana();
    void setMana(int);
    void showAttacks() override;
    bool Attack(Character&, AttackData ) override;
    void Image() override;
    AttackData getAttack(int) override;
    void PrintInfo() override;
    void saveGame(ofstream& fout) override;
    void loadGame(ifstream& fin) override;
private:
    int mana;
    int maxMana;
    AttackData spells[4];
};

#endif //WIZARD_H
