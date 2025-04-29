#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// This struct allows us to store different attacks, as a character levels up, more attacks are unlockable;
struct AttackData {
    string name; // Name of each attack
    int damage;  // The damage done by the attack
    int impact;  // What effect it has on character. EX if wizard (mana drops) if Berserker (Stamina drops)
};
// Each character gets 4 attacks

class Character {
public:
    virtual ~Character() {}; // basic destructor;
    Character(string name = "Unknown", int health = 100, int level = 1, int xp = 0, string condition = "Good");
    // For this use case, we will only use names as input and give each character the rest as default.
    virtual void Rest();
    virtual void Heal();
    virtual void AddEXP();
    virtual void LevelUp();
    virtual void PrintInfo();
    virtual bool Attack(Character&, AttackData ) = 0;
    virtual void showAttacks() = 0;
    virtual void Image() = 0;
    virtual AttackData getAttack(int) = 0; // returns a particular attack at index of the int

    int getHealth();
    int getLevel();
    void setHealth(int);
    void setLevel(int);
    void setCondition(string);
    string getName();
    string getCondition();
    virtual void saveGame(ofstream& fout);
    virtual void loadGame(ifstream& fin);

protected:
    int maxHealth;
    int health;
    int level;
    int xp;
    string name;
    string condition; // Condition will be used for an attack multiplier
};
// ADD A MULTIPLIER FUNCTION OF TYPE INT TO RETURN MULTIPLIER FOR DAMAGE




#endif //CHARACTER_H
