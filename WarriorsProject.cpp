#include <iostream>

class Warrior
{
private:
    std::string name;
    int level;
    int experience;
    int health;
    int attack;
    int defense;
    int magic;

public:
    Warrior()
    {
        name = "newPlayer";
        level = 1;
        experience = 0;
        health = 100;
        attack = 10;
        defense = 30;
        magic = 5;
    } // defaulten konstruktor
    Warrior(std::string name, int level, int experience, int health, int attack, int defense, int magic)
        : name(name), level(level), experience(experience), health(health), attack(attack), defense(defense), magic(magic) {}
    // inizializirasht spisyk

    int getAttack() const
    {
        return attack;
    }

    void attackEnemy()
    {
        std::cout << name << " attacks the enemy!\n";
    }

    void defend()
    {
        defense += 5; // uvelichava zashtita da kajem s 5
        std::cout << name << " raises defense!\n";
    }

    void useMagic()
    {
        std::cout << name << " uses magic!\n";
        this->attack = this->attack + magic;
    }

    void displayStats()
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "Level: " << level << "\n";
        std::cout << "Health: " << health << "\n";
        std::cout << "Attack: " << attack << "\n";
        std::cout << "Defense: " << defense << "\n";
        std::cout << "Magic: " << magic << "\n";
    }

    bool isAlive()
    {
        return health > 0;
    }

    void receiveDamage(int damage)
    {
        if (damage > defense)
        {
            health = health + defense - damage;
            defense = 0;
        }
    }

    void gainExperience(int exp)
    {
        experience += exp;
        if (experience >= 10)
        {
            level = level + 1;
            experience = 0;
            health = health+25*level;// kolkoot po golqm level poveche se healva ako e dignal level
        }
    }
};

class Enemy
{
private:
    std::string name;
    int level;
    int health;
    int attack;
    int defense;
    int magic;

public:
    Enemy()
    {

        name = "newEnemy";
        level = 1;
        health = 100;
        attack = 5;
        defense = 0;
        magic = 5;
    }
    Enemy(std::string name, int level, int health, int attack, int defense, int magic)
        : name(name), level(level), health(health), attack(attack), defense(defense), magic(magic) {}

    int getAttack() const
    {
        return attack;
    }

    void operator=(Enemy other)
    {
        name = other.name;
        level = other.level;
        health = other.health;
        attack = other.attack;
        defense = other.defense;
        magic = other.magic;
    }

    void attackWarrior()
    {
        std::cout << name << " attacks the warrior!\n";
    }

    void defend()
    {
        defense += 5;
        std::cout << name << " raises defense!\n";
    }

    void useMagic()
    {
        std::cout << name << " uses magic!\n";
        this->defense = this->defense + magic;
    }

    void displayStats()
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "Level: " << level << "\n";
        std::cout << "Health: " << health << "\n";
        std::cout << "Attack: " << attack << "\n";
        std::cout << "Defense: " << defense << "\n";
        std::cout << "Magic: " << magic << "\n";
    }

    bool isAlive()
    {
        return health > 0;
    }

    void receiveDamage(int damage)
    {
        if (damage > defense)
        {
            health = health + defense - damage;
            defense = 0;
        }
    }
};

bool game(Warrior player, Enemy enemy)
{

    while (player.isAlive() && enemy.isAlive())
    {
        int playerAction, enemyAction;

        std::cout << "Player's stats:\n";
        player.displayStats();
        std::cout << "\nEnemy's stats:\n";
        enemy.displayStats();
        std::cout << "-----------------\n";

        std::cout << "Player's turn: (0: Attack, 1: Defend, 2: Use Magic): ";
        std::cin >> playerAction;

        switch (playerAction)
        {
        case 0:
            player.attackEnemy();
            enemy.receiveDamage(player.getAttack());
            break;
        case 1:
            player.defend();
            break;
        case 2:
            player.useMagic();
            break;
        default:
            std::cout << "Invalid choice! Player skips turn.\n";
            break;
        }
        if (enemy.isAlive())
        {
            std::cout << "Enemy's turn: (0: Attack, 1: Defend, 2: Use Magic): ";
            std::cin >> enemyAction;

            switch (enemyAction)
            {
            case 0:
                enemy.attackWarrior();
                player.receiveDamage(enemy.getAttack());
                break;
            case 1:
                enemy.defend();
                break;
            case 2:
                enemy.useMagic();
                break;
            default:
                std::cout << "Invalid choice! Enemy skips turn.\n";
                break;
            }
        }
    }

    if (player.isAlive())
    {
        std::cout << "Player wins!\n";
        player.gainExperience(10); // igracha poluchava 10xp
        return 1;
    }
    else
    {
        std::cout << "Enemy wins!\n";
        return 0;
    }
}

int main()
{
    Warrior player("Player", 1, 0, 100, 20, 5, 5);
    Enemy enemy("Goblin", 1, 50, 10, 5, 10);
    Enemy enemy0("Dragon", 2, 120, 10, 0, 20);
    Enemy enemy1("Troll", 3, 30, 50, 5, 10);
    Enemy enemy2("Orc", 5, 70, 30, 0, 0);
    Enemy arr = {enemy0,enemy1,enemy2};
    if (game(player, enemy))
    {
        switch (expression)
        {
        case /* constant-expression */:
            /* code */
            break;

        default:
            break;
        }
    }
    else
    {
        std ::cout << "GAME OVER";
    }
    return 0;
}
