/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Reception
*/

#include "Reception.hpp"

Reception::Reception()
{

}

Reception::Reception(std::string multi, std::string cooks, std::string time)
{
    this->_orders.clear();
    this->_ipcs.clear();
    this->_multi = std::stof(multi);
    this->_maxCooks = std::stoi(cooks);
    this->_restock = std::stoi(time);
    this->_good = true;
    std::cout << "Welcome to Delfino's Pizza!" << std::endl;
}

//Reception loop for receiving and send them to kitchens
void Reception::loop()
{
    while (this->_good) {
        this->gettingOrder();
        this->givingPizza();
        this->addingToLog();
    }
}

void Reception::creatingKitchens()
{
    int place = 0;
    SharedMemory mems;

    this->_ipcs.push_back(mems);
    place = this->_ipcs.size() - 1;
    pid_t forked = fork();
    if (forked == 0) {
        Process news(mems, this->_multi, this->_maxCooks, this->_restock);
        news.mainLoop();
        this->_ipcs.erase(this->_ipcs.begin() + place);
        exit(0);
    }
}

//Giving Pizza to kitchens
void Reception::givingPizza()
{
    SharedMemory save;
    size_t which = 0;

    if (this->_ipcs.size() == 0)
        this->creatingKitchens();
    for (auto order = this->_orders.begin(); order != this->_orders.end();) {
        if (std::string(this->_ipcs.at(which).receiveMessage()).compare(0, 7, "Destroy") == 0) {
            this->_ipcs.erase(this->_ipcs.begin() + which);
            std::cout << "Kitchen destroyed " << std::endl;
            if (this->_ipcs.size() == 0)
                this->creatingKitchens();
            continue;
        }
        Pizza ones(*order, this->_multi);
        this->_ipcs.at(which).sendMessage(ones.serializeData());
        while(std::string(this->_ipcs.at(which).receiveMessage()).compare(ones.serializeData()) == 0);
        if (std::string(this->_ipcs.at(which).receiveMessage()).compare(0, 2, "Ok") == 0) {
            this->_ipcs.at(which).sendMessage("None");
            order++;
        }
        else if (std::string(this->_ipcs.at(which).receiveMessage()).compare(0, 5, "Error") == 0) {
            this->_ipcs.at(which).sendMessage("None");
            this->creatingKitchens();
        }
        if (which + 1 == this->_ipcs.size())
            which = 0;
        else
            which++;
    }
    usleep(500);
    std::cout << "Command sent " << std::endl;
}

//Using prompt class to receive order and stocking it into the vectors
void Reception::gettingOrder()
{
    Prompt prompt;

    this->_orders.clear();
    while (!(this->_orders.size() > 0)) {
        this->_orders = prompt.getInput();
        if (this->goodOrder())
            break;
        if (this->_orders.front().input.compare("status") == 0) {
            this->_orders.clear();
            (void)0;
        } else {
            this->_orders.clear();
            std::cout << "You have to write your order like this :" << std::endl;
            std::cout << "  The pizza you want to order: margarita, regina, americana, fantasia" << std::endl;
            std::cout << "  The size you want for your pizza: S, M, L, XL, XXL" << std::endl;
            std::cout << "  The amount of pizza you want like: x1, x2, x3 ..." << std::endl;
            std::cout << "  All in one line like this : Pizza Size Amount" << std::endl;
        }
    }
}

//Checking if the order is a good one
bool Reception:: goodOrder()
{
    if (this->_orders.size() >= 1) {
        if (this->_orders.front().input.compare("status") == 0) {
            this->statusCommand();
            return false;
        }
        if (this->_orders.size() == 1)
            return false;
        this->_orders.erase(this->_orders.begin());
    }
    for (auto i = this->_orders.begin(); i != this->_orders.end(); i++) {
        if ((i->amount == 0 || i->pizza == 0 || i->size == 0))
            return false;
    }
    return true;
}

//Calling status command on every kitchen
void Reception::statusCommand()
{
    std::cout << "Status command " << std::endl;
    for (auto i = this->_ipcs.begin(); i != this->_ipcs.end(); i++) {
        i->sendMessage("status");
        while(std::string(i->receiveMessage()).compare(0, 2, "Ok") != 0);
        i->sendMessage("None");
    }
}

//Adding current order to the order log
bool Reception::addingToLog()
{
    static int order = 1;
    std::ofstream file(std::string(LOGFILE), std::ios::app);

    if (file.is_open() == false)
        throw Error("Reception log", "Can't open the file");
    file << "Order n°: " << order << std::endl;
    for (auto i = this->_orders.begin(); i != this->_orders.end(); i++) {
        file << "\t" << i->amount << " " << Prompt::gettingPizzaName(i->pizza) << " in " << Prompt::gettingPizzaSize(i->size) << std::endl;
    }
    order++;
    return true;
}

//Getters
float Reception::getMulti() const
{
    return this->_multi;
}

int Reception::getCooks() const
{
    return this->_maxCooks;
}

int Reception::getRestockTime() const
{
    return this->_restock;
}

bool Reception::getGood() const
{
    return this->_good;
}

Reception::~Reception()
{
}