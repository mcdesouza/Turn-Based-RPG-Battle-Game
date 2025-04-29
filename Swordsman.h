#ifndef SWORDSMAN_H
#define SWORDSMAN_H
#include "Character.h"

class Swordsman: public Character {
public:
    ~Swordsman() override {};
    Swordsman(string);
    void Rest() override;
    void Heal() override;
    void AddEXP() override;
    void LevelUp() override;
    int getSwordCondition();
    void setSwordCondition(int);
    void showAttacks() override;
    bool Attack(Character&, AttackData) override;
    void Image() override;
    AttackData getAttack(int) override;
    void PrintInfo() override;
    void saveGame(ofstream& fout) override;
    void loadGame(ifstream& fin) override;
private:
    int swordCondition;
    int maxSwordCondition;
    AttackData slashes[4];
};

#endif // SWORDSMAN_H