#include <iostream>

class Warrior
{
private:
// komentar
    std::string name;
    int level;
    int experience;
    int health;
    int attack;
    int defense;
    int magic;
    int attack_start;

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
        : name(name), level(level), experience(experience), health(health), attack(attack), defense(defense), magic(magic)
    {
        attack_start = attack;
    }
    // inizializirasht spisyk

    int getAttack() const
    {
        return attack;
    }

    void resetAttack()
    {
        attack = attack_start;
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
        attack += magic;
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

        }else{
            defense = defense - damage;
        } 
    }

    void gainExperience(int exp)
    {
        experience += exp;
        if (experience >= 100)
        {
            level = level + 1;
            experience = experience - 100;
            health = health + 25 * level; // kolkoot po golqm level poveche se healva ako e dignal level
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
    int getLevel() const
    {
        return level;
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
        defense += magic;
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
        }else{
            defense = defense - damage;
        }   
    }
};

void game(Warrior player, Enemy enemy, Enemy arr[])
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
        player.resetAttack();
        std::cout << " ____  _       ____  __ __    ___  ____       __    __  ____  ____   _____\n";
    std::cout << "|    \\| |     /    ||  |  |  /  _]|    \\     |  |__|  ||    ||    \\ / ___/\n";
    std::cout << "|  o  ) |    |  o  ||  |  | /  [_ |  D  )    |  |  |  | |  | |  _  (   \\_ \n";
    std::cout << "|   _/| |___ |     ||  ~  ||    _]|    /     |  |  |  | |  | |  |  |\\__  |\n";
    std::cout << "|  |  |     ||  _  ||___, ||   [_ |    \\     |  `  '  | |  | |  |  |/  \\ |\n";
    std::cout << "|  |  |     ||  |  ||     ||     ||  .  \\     \\      /  |  | |  |  |\\    |\n";
    std::cout << "|__|  |_____||__|__||____/ |_____||__|\\_|      \\_/\\_/  |____||__|__| \\___|\n";
   
        player.gainExperience(10 * enemy.getLevel()); // igracha poluchava 10xp
        int command;
        std ::cout << "Choose your next action: 0 - end the game, 1 - fight the dragon , 2 - fight the troll , 3 - fight the Orc: ";
        std ::cin >> command;
        std ::cout << std ::endl;
        switch (command)
        {
        case 0:
            std::cout << "  ____   ____  ___ ___    ___       ___   __ __    ___  ____  \n";
    std::cout << " /    | /    ||   |   |  /  _]     /   \\ |  |  |  /  _]|    \\ \n";
    std::cout << "|   __||  o  || _   _ | /  [_     |     ||  |  | /  [_ |  D  )\n";
    std::cout << "|  |  ||     ||  \\_/  ||    _]    |  O  ||  |  ||    _]|    / \n";
    std::cout << "|  |_ ||  _  ||   |   ||   [_     |     ||  :  ||   [_ |    \\ \n";
    std::cout << "|     ||  |  ||   |   ||     |    |     | \\   / |     ||  .  \\ \n";
    std::cout << "|___,_||__|__||___|___||_____|     \\___/   \\_/  |_____||__|\\_|\n";
            break;
        case 1:
            game(player, arr[0], arr);
            break;
        case 2:
            game(player, arr[1], arr);
            break;
        case 3:
            game(player, arr[2], arr);
            break;
        default:
            std ::cout << "Wrong input!" << std ::endl;
        }
    }
    else
    {
        std::cout << "   ___  ____     ___  ___ ___  __ __      __    __  ____  ____   _____\n";
    std::cout << "  /  _]|    \\   /  _]|   |   ||  |  |    |  |__|  ||    ||    \\ / ___/\n";
    std::cout << " /  [_ |  _  | /  [_ | _   _ ||  |  |    |  |  |  | |  | |  _  (   \\_ \n";
    std::cout << "|    _]|  |  ||    _]|  \\_/  ||  ~  |    |  |  |  | |  | |  |  |\\__  |\n";
    std::cout << "|   [_ |  |  ||   [_ |   |   ||___, |    |  `  '  | |  | |  |  |/  \\ |\n";
    std::cout << "|     ||  |  ||     ||   |   ||     |     \\      /  |  | |  |  |\\    |\n";
    std::cout << "|_____||__|__||_____||___|___||____/       \\_/\\_/  |____||__|__| \\___|\n";
    std::cout << "                                                                       \n";
        
        std::cout << "  ____   ____  ___ ___    ___       ___   __ __    ___  ____  \n";
    std::cout << " /    | /    ||   |   |  /  _]     /   \\ |  |  |  /  _]|    \\ \n";
    std::cout << "|   __||  o  || _   _ | /  [_     |     ||  |  | /  [_ |  D  )\n";
    std::cout << "|  |  ||     ||  \\_/  ||    _]    |  O  ||  |  ||    _]|    / \n";
    std::cout << "|  |_ ||  _  ||   |   ||   [_     |     ||  :  ||   [_ |    \\ \n";
    std::cout << "|     ||  |  ||   |   ||     |    |     | \\   / |     ||  .  \\ \n";
    std::cout << "|___,_||__|__||___|___||_____|     \\___/   \\_/  |_____||__|\\_|\n";
    }
}

int main()
{
    Warrior player("Player", 1, 0, 100, 20, 5, 5);
    Enemy enemy("Goblin", 1, 50, 10, 5, 10);
    Enemy enemy0("Dragon", 2, 120, 10, 0, 20);
    Enemy enemy1("Troll", 3, 30, 50, 5, 10);
    Enemy enemy2("Orc", 5, 70, 30, 0, 0);
    Enemy arr[] = {enemy0, enemy1, enemy2};
    game(player, enemy, arr);
    return 0;
}