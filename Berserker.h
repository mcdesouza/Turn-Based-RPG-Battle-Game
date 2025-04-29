#ifndef BERSERKER_H
#define BERSERKER_H
#include "Character.h"

class Berserker: public Character {
public:
    ~Berserker() override {};
    Berserker(string);
    void Rest() override;
    void Heal() override;
    void AddEXP() override;
    void LevelUp() override;
    int getStamina();
    void setStamina(int);
    void showAttacks() override;
    bool Attack(Character&, AttackData) override;
    void Image() override;
    AttackData getAttack(int) override;
    void PrintInfo() override;
    void saveGame(ofstream& fout) override;
    void loadGame(ifstream& fin) override;
private:
    int stamina;
    int maxStamina;
    AttackData strikes[4];
};



#endif //BERSERKER_H
