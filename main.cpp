#include <iostream>
#include <fstream>
#include <cstdlib> // for rand()
#include <ctime>   // for time()
#include "Character.h"
#include "Wizard.h"
#include "Berserker.h"
#include "Swordsman.h"

using namespace std;
void PrintIntro() {
    cout << R"(
      _    _      _                            _____
     | |  | |    | |                          |_   _|
     | |  | | ___| | ___ ___  _ __ ___   ___    | | ___
     | |/\| |/ _ \ |/ __/ _ \| '_ ` _ \ / _ \   | |/ _ \
     \  /\  /  __/ | (_| (_) | | | | | |  __/   | | (_) |
      \/  \/ \___|_|\___\___/|_| |_| |_|\___|   \_/\___/


     ______          _                   ______ _       _     _             ____________ _____
     |  ___|        | |                  |  ___(_)     | |   | |            | ___ \ ___ \  __ \
     | |_ __ _ _ __ | |_ __ _ ___ _   _  | |_   _  __ _| |__ | |_ ___ _ __  | |_/ / |_/ / |  \/
     |  _/ _` | '_ \| __/ _` / __| | | | |  _| | |/ _` | '_ \| __/ _ \ '__| |    /|  __/| | __
     | || (_| | | | | || (_| \__ \ |_| | | |   | | (_| | | | | ||  __/ |    | |\ \| |   | |_\ \
     \_| \__,_|_| |_|\__\__,_|___/\__, | \_|   |_|\__, |_| |_|\__\___|_|    \_| \_\_|    \____/
                                   __/ |           __/ |
                                  |___/           |___/
    )" << endl << endl;
    cout <<  "Fantasy Fighter RPG is a turn based RPG battle game where you fight enemies and level up" << endl << endl;
}
void MainMenu() {
    cout << "Select one of the following by entering a number to start:" << endl;
    cout << "1) New Game" << endl;
    cout << "2) Load Game" << endl;
    cout << "3) Exit" << endl << endl;
}
void CharacterChoices() {
    cout << "Choose your character:" << endl;
    cout << "1) Wizard" << endl;
    cout << "2) Berserker" << endl;
    cout << "3) Swordsman" << endl << endl;
}
void FilePrompt() {
    cout << "Please enter the name of the file you would like to load: " << endl;
}
void PrintGameInfo() {
    cout << endl;
    cout << "Now that your character has been created, here is some info on the game:" << endl << endl;
    cout << "As you progress, enemies will get stronger, if you die in battle, it is game over" << endl;
    cout << "Healing improves overall health" << endl;
    cout << "Resting improves condition, some health, and [Mana (wizard), Stamina (berserker), or Sword Condition (swordsman)]" << endl;
    cout << "You have four attacks that cost [Mana (wizard), Stamina (berserker), or Sword Condition (swordsman)]" << endl << endl;
}
void GameMenu() {
    cout << "Select one of the following by entering a number:" << endl;
    cout << "1) Enter Battle" << endl;
    cout << "2) View Character Info" << endl;
    cout << "3) Save Game and Exit" << endl;
    cout << "4) Exit Without Saving" << endl << endl;
}
void BattleMenu() {
    cout << endl;
    cout << "Select one of the following by entering a number:" << endl;
    cout << "1) Attack" << endl;
    cout << "2) Heal" << endl;
    cout << "3) Rest" << endl;
    cout << "4) Flee" << endl << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Character* player = nullptr;
    Character* enemy = nullptr;
    string characterType = "";
    PrintIntro();
    bool exit = false;
    int mainOpt;
    while (!exit) {
        MainMenu();
        cin >> mainOpt;
        switch (mainOpt) {
            case 1: { // OPTION 1 NEW CHARACTER
                string playerName;
                cout << "Enter your character's name: ";
                cin.ignore();
                getline(cin, playerName);
                // get name
                CharacterChoices();
                int choice;
                cin >> choice;
                switch (choice) {
                    case(1): {
                        characterType = "Wizard";
                        player = new Wizard(playerName);
                        cout << "You have selected type Wizard" << endl;
                        player->Image();
                        break;
                    }
                    case(2): {
                        characterType = "Berserker";
                        player = new Berserker(playerName);
                        cout << "You have selected type Berserker" << endl;
                        player->Image();
                        break;
                    }
                    case(3): {
                        characterType = "Swordsman";
                        player = new Swordsman(playerName);
                        cout << "You have selected type Swordsman" << endl;
                        player->Image();
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Returning to main menu." << endl;
                        continue;
                    }
                } // CREATE PLAYER
                break;
            }
            case 2: {
                FilePrompt();
                string fileName;
                cin >> fileName;
                ifstream fin(fileName);
                if (!fin.is_open()) {
                    cout << "Error File Not Found" << endl;
                    cout << "Returning to main menu" << endl;
                    continue;
                }
                fin >> characterType;
                if (characterType == "Wizard"){
                    player = new Wizard("Unknown");
                    fin.ignore();
                    player->loadGame(fin);
                    cout << "You have loaded type Wizard" << endl;
                    player->Image();
                }
                else if (characterType == "Berserker"){
                    player = new Berserker("Unknown");
                    fin.ignore();
                    player->loadGame(fin);
                    cout << "You have loaded type Berserker" << endl;
                    player->Image();
                }
                else if(characterType == "Swordsman"){
                    player = new Swordsman("Unknown");
                    fin.ignore();
                    player->loadGame(fin);
                    cout << "You have loaded type Swordsman" << endl;
                    player->Image();
                }
                else {
                    cout << "Invalid choice. Returning to main menu." << endl;
                    continue;
                }
                fin.close();
                break;
            }
            case 3: {
                cout << "Thanks for playing!" << endl;
                exit = true;
                continue;
            }
            default: {
                cout << "Invalid choice entered. Please try again: " << endl;
                continue;
            }
        }
        PrintGameInfo();
        while (player != nullptr) {
            int enemystatboost = 0;
            GameMenu();
            int gamechoice;
            cin >> gamechoice;
            switch (gamechoice) {
                case(1): {
                    bool inbattle = true;
                    int randomEnemy = rand() % 3;
                    switch (randomEnemy) {
                        case 0: {
                            enemy = new Wizard("Enemy Wizard");
                            cout << "Your opponent is a Wizard" << endl;
                            enemy->Image();
                            break;
                        }
                        case 1: {
                            enemy = new Berserker("Enemy Berserker");
                            cout << "Your opponent is a Berserker" << endl;
                            enemy->Image();
                            break;
                        }
                        case 2: {
                            enemy = new Swordsman("Enemy Swordsman");
                            cout << "Your opponent is a Swordsman" << endl;
                            enemy->Image();
                            break;
                        }
                    }
                    enemy->setHealth(enemy->getHealth() + enemystatboost);
                    while (inbattle) {

                        BattleMenu();
                        int battlechoice;
                        cin >> battlechoice;
                        cout << endl;
                        switch (battlechoice) {
                            case(1): {
                                cout << "Choose an Attack: " << endl;
                                player->showAttacks();
                                int attackchoice;
                                cin >> attackchoice;
                                switch (attackchoice) {
                                    case(1): {
                                        player->Attack(*enemy, player->getAttack(1));
                                        break;
                                    }
                                    case(2): {
                                        player->Attack(*enemy, player->getAttack(2));
                                        break;
                                    }
                                    case(3): {
                                        player->Attack(*enemy, player->getAttack(3));
                                        break;
                                    }
                                    case(4): {
                                        player->Attack(*enemy, player->getAttack(4));
                                        break;
                                    }
                                    default: {
                                        cout << "Invalid Choice Returning to Battle Menu" << endl;
                                        continue;
                                    }
                                }
                                break;
                            }
                            case(2): {
                                player->Heal();
                                break;
                            }
                            case(3): {
                                player->Rest();
                                break;
                            }
                            case(4): {
                                inbattle = false;
                                continue;
                            }
                            default: {
                                cout << "Invalid choice try again" << endl;
                                continue;
                            }
                        }
                        if (enemy->getHealth() <= 0) {
                            cout << endl;
                            cout << player->getName() << " has defeated the enemy" << endl << endl;
                            player->LevelUp();
                            inbattle = false;
                            continue;
                        }
                        // enemy attack
                        int enemyAction = rand() % 3 + 1; // Random number: 1 (Attack), 2 (Rest), 3 (Heal)
                        switch (enemyAction) {
                            case 1: {
                                cout << "Enemy attacks!" << endl;
                                enemy->Attack(*player, enemy->getAttack(rand() % 4 + 1)); // Random attack 1-4
                                break;
                            }
                            case 2: {
                                cout << "Enemy rests!" << endl;
                                enemy->Rest();
                                break;
                            }
                            case 3: {
                                cout << "Enemy heals!" << endl;
                                enemy->Heal();
                                break;
                            }
                        }

                        if (player->getHealth() <= 0) {
                            cout << endl;
                            cout << player->getName() << " has been defeated by the enemy" << endl << endl;
                            inbattle = false;
                            player = nullptr;
                            continue;
                        }
                        cout << endl;
                        player->PrintInfo();
                        cout << endl;
                        enemy->PrintInfo();
                        if (player->getHealth() <= 30) {
                            player->setCondition("Poor");
                        }
                        else if (player->getHealth() > 30 && player->getHealth() <= 70) {
                            player->setCondition("Moderate");
                        }
                        else {
                            player->setCondition("Good");
                        }
                        if (enemy->getHealth() <= 30) {
                            enemy->setCondition("Poor");
                        }
                        else if (enemy->getHealth() > 30 && enemy->getHealth() <= 70) {
                            enemy->setCondition("Moderate");
                        }
                        else {
                            enemy->setCondition("Good");
                        }
                    }
                    enemy = nullptr;
                    break;
                }
                case(2): {
                    cout << "Type: " << characterType << endl;
                    player->PrintInfo();
                    cout << endl;
                    cout << "Attacks:" << endl;
                    player->showAttacks();
                    cout << endl;
                    break;
                }
                case(3): {
                    cout << "Enter a name for the output file" << endl;
                    string outputFile;
                    cin >> outputFile;
                    ofstream fout(outputFile);
                    if (!fout.is_open()) {
                        cout << "Error Could Not Open File" << endl;
                        cout << "Returning to Game Menu" << endl;
                        continue;
                    }
                    fout << characterType << endl;
                    player->saveGame(fout);

                    fout.close();
                    player = nullptr;
                    break;
                }
                case(4): {
                    player = nullptr;
                    break;
                }
                default: {
                    cout << "Invalid choice entered. Please try again: " << endl;
                    continue;
                }
            }
            enemystatboost += 10; // This allows for enemy to get stronger over time
        }
    }
}

