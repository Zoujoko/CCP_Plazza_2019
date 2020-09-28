/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

// creates a pizza by calling cooks
void *prepareCommand(void *time)
{
    float *timer = (float *)time;
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> diff = std::chrono::system_clock::now();
    int elapsed = 0;

    while (elapsed < ((*timer) * 1000000)) {
        diff = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(diff-start).count();
    }
    return (nullptr);
}

Kitchen::Kitchen(int cookingTime, int nbCooks, int restockTime)
{
    this->_cookingTime = cookingTime;
    this->_nbCooks = nbCooks;
    this->_restockTime = restockTime;
    this->_isActive = true;
    this->_stocks.insert(std::pair<Ingredient, int>(Dough, 5));
    this->_stocks.insert(std::pair<Ingredient, int>(TomatoSauce, 5));
    this->_stocks.insert(std::pair<Ingredient, int>(Gruyere, 5));
    this->_stocks.insert(std::pair<Ingredient, int>(Ham, 5));
    this->_stocks.insert(std::pair<Ingredient, int>(Mushroom, 5));
    this->_stocks.insert(std::pair<Ingredient, int>(Steak, 5));
    this->_stocks.insert(std::pair<Ingredient, int>(Eggplant, 5));
    this->_stocks.insert(std::pair<Ingredient, int>(GoatCheese, 5));
    this->_stocks.insert(std::pair<Ingredient, int>(ChiefLove, 5));
    this->_command = std::string("None");
}

Kitchen::~Kitchen()
{
}

// reset nb of ingredients to 5 each
void Kitchen::restockIngredients()
{
    static std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> test = std::chrono::system_clock::now();
    std::map<Ingredient, int>::iterator it = this->_stocks.begin();
    float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(test-start).count();

    if (elapsed >= this->_restockTime) {
        start = std::chrono::system_clock::now();
        for (; it != this->_stocks.end(); it++)
            it->second += 1;
    }
}

// check if kitchen can receive a new command
bool Kitchen::checkNbCommands()
{
    return (this->_commands <= (2 * this->_nbCooks));
}

// check if kitchen is active or not
void Kitchen::isKitchenActive()
{
}

// prints the actual amount of ingredients
void Kitchen::printStatus()
{
    std::map<Ingredient, int>::iterator dough = this->_stocks.find(Dough);
    std::map<Ingredient, int>::iterator tomatoS = this->_stocks.find(TomatoSauce);
    std::map<Ingredient, int>::iterator gruyere = this->_stocks.find(Gruyere);
    std::map<Ingredient, int>::iterator ham = this->_stocks.find(Ham);
    std::map<Ingredient, int>::iterator mushroom = this->_stocks.find(Mushroom);
    std::map<Ingredient, int>::iterator steak = this->_stocks.find(Steak);
    std::map<Ingredient, int>::iterator eggplant = this->_stocks.find(Eggplant);
    std::map<Ingredient, int>::iterator goatcheese = this->_stocks.find(GoatCheese);
    std::map<Ingredient, int>::iterator chieflove = this->_stocks.find(ChiefLove);

    std::cout << "List of ingredients in this kitchen :" << std::endl;
    std::cout << "- Dough : " << dough->second << std::endl;
    std::cout << "- Tomato sauce : " << tomatoS->second << std::endl;
    std::cout << "- Gruyere : " << gruyere->second << std::endl;
    std::cout << "- Ham : " << ham->second << std::endl;
    std::cout << "- Mushroom : " << mushroom->second << std::endl;
    std::cout << "- steak : " << steak->second << std::endl;
    std::cout << "- Eggplant : " << eggplant->second << std::endl;
    std::cout << "- Goat cheese : " << goatcheese->second << std::endl;
    std::cout << "- Chief love <3 : " << chieflove->second << std::endl;
}

// joins cooks threads
void Kitchen::joinCooks()
{
    for (size_t i = 0; i < this->_pool.size(); i++) {
        if (this->_pool[i]->isWorking() == Cook::State::working) {
            this->_pool[i]->join();
        }
    }
}

// starts cooks threads
void Kitchen::startCooks()
{
    for (size_t i = 0; i < this->_pool.size(); i++)
        this->_pool[i]->start();
}

bool Kitchen::cooksActive()
{
    size_t working = 0;

    for (size_t i = 0; i < this->_pool.size(); i++) {
        if (this->_pool[i]->isWorking() == Cook::State::working) {
            working++;
        }
    }
    if (working == 0) {
        return false;
    }
    return true;
}

// Getters
bool Kitchen::getStatus(SharedMemory mems)
{
    time_t base = time(NULL);
    time_t test = time(NULL);

    this->_command.assign("None");
    while (this->_command.compare(0, 4, "None") == 0) {
        if (this->cooksActive() == true) {
            base = time(NULL);
        }
        test = time(NULL);
        if (test - base > 5) {
            this->_isActive = false;
            break;
        }
        this->_command.clear();
        this->_command = std::string(mems.receiveMessage());
        this->restockIngredients();
        if (this->_command.compare(0, 4, "None") == 0) {
            this->joinCooks();
        }
        this->restockIngredients();
        this->checkingCooks();
    }
    return (this->_isActive);
}

//Adding the command to the actual command list
bool Kitchen::addingCommand()
{
    if (!this->checkNbCommands())
        return false;
    this->_commands++;
    Pizza queue(this->_command);
    this->_queue.push_back(queue);
    return true;
}

void Kitchen::checkingCooks()
{
    float bake = 0;

    while (this->_pool.size() != this->_nbCooks && this->_queue.size() > 0) {
        if (this->_queue.size() > 0) {
            bake = this->_queue.front().getBakingTime();
            if (this->removingIngredients() == true) {
                Cook *cooker = new Cook(NULL, prepareCommand, bake);
                cooker->start();
                this->_queue.erase(this->_queue.begin());
                this->_pool.push_back(cooker);
            }
        }
    }
    for (size_t i = 0; i < this->_pool.size() ; i++) {
        if (this->_pool[i]->isWorking() == Cook::State::finished) {
            this->_pool.erase(this->_pool.begin() + i);
            this->_commands--;
        }
    }
}

bool Kitchen::removingIngredients()
{
    PizzaType pizza = this->_queue.front().getType();

    if (!(this->_stocks[Dough] > 0) || !(this->_stocks[TomatoSauce] > 0))
        return false;
    this->_stocks[Dough]--;
    this->_stocks[TomatoSauce]--;
    if (PizzaType::Regina == pizza || PizzaType::Americana == pizza || PizzaType::Margarita == pizza) {
        if(!(this->_stocks[Gruyere] > 0))
            return false;
        this->_stocks[Gruyere]--;
    }
    if (PizzaType::Regina == pizza) {
        if(!(this->_stocks[Ham] > 0))
            return false;
        this->_stocks[Ham]--;
    }
    if (PizzaType::Regina == pizza) {
        if(!(this->_stocks[Mushroom] > 0))
            return false;
        this->_stocks[Mushroom]--;
    }
    if (PizzaType::Americana == pizza) {
        if(!(this->_stocks[Steak] > 0))
            return false;
        this->_stocks[Steak]--;
    }
    if (PizzaType::Fantasia == pizza) {
        if(!(this->_stocks[Eggplant] > 0))
            return false;
        this->_stocks[Eggplant]--;
    }
    if (PizzaType::Fantasia == pizza) {
        if(!(this->_stocks[GoatCheese] > 0))
            return false;
        this->_stocks[GoatCheese]--;
    }
    if (PizzaType::Fantasia == pizza) {
        if(!(this->_stocks[ChiefLove] > 0))
            return false;
        this->_stocks[ChiefLove]--;
    }
    return true;
}

pid_t Kitchen::getPid()
{
    return (getpid());
}

size_t Kitchen::getCookingTime() const
{
    return (this->_cookingTime);
}

size_t Kitchen::getRestockTime() const
{
    return (this->_restockTime);
}

size_t Kitchen::getCooksNb() const
{
    return (this->_nbCooks);
}

std::string Kitchen::getCommand() const
{
    return this->_command;
}