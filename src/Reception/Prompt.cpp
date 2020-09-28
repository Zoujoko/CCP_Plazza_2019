/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Prompt
*/

#include "Prompt.hpp"

Prompt::Prompt()
{
    this->_amount = 0;
    this->_pizzaType = PizzaType::NoneType;
    this->_pizzaSize = PizzaSize::NoneSize;
}

// Retrieving the user order
std::vector<order_t>Prompt::getInput()
{
    order_t input;

    this->_orders.clear();
    std::string line;
    std::cout << "Let me take your order : ";
    std::getline(std::cin, line);
    input.input = line;
    input.amount = 0;
    this->_orders.push_back(input);
    this->parsingInput(line);
    return this->_orders;
}

// To associate easily pizza name inputs and PizzaType and avoid multiple ifs
const pizza_name_t pizzaNames[] = {
    {PizzaType::Regina, "regina"},
    {PizzaType::Margarita, "margarita"},
    {PizzaType::Americana, "americana"},
    {PizzaType::Fantasia, "fantasia"},
    {PizzaType::NoneType, ""}
};

//Getting Pizza Name
std::string Prompt::gettingPizzaName(PizzaType type)
{
    for (size_t i = 0; pizzaNames[i].type != PizzaType::NoneType; i++)
        if (type == pizzaNames[i].type)
            return pizzaNames[i].name;
    return "None";
}

// To associate easily pizza size inputs and PizzaSize and avoid multiple ifs
const pizza_size_t pizzaSizes[] = {
    {PizzaSize::S, "S"},
    {PizzaSize::M, "M"},
    {PizzaSize::L, "L"},
    {PizzaSize::XL, "XL"},
    {PizzaSize::XXL, "XXL"},
    {PizzaSize::NoneSize, ""}
};

std::string Prompt::gettingPizzaSize(PizzaSize pizzaSize)
{
    for (size_t i = 0; pizzaSizes[i].size != PizzaSize::NoneSize; i++)
        if (pizzaSize == pizzaSizes[i].size)
            return pizzaSizes[i].name;
    return "None";
}

// Getters
PizzaType Prompt::getType() const
{
    return (this->_pizzaType);
}

PizzaSize Prompt::getSize() const
{
    return (this->_pizzaSize);
}

int Prompt::getAmount() const
{
    return (this->_amount);
}

// Adding actual order to all orders vector
void Prompt::addingOrderToVector()
{
    order_t clientOrder;

    clientOrder.pizza = this->_pizzaType;
    clientOrder.size = this->_pizzaSize;
    clientOrder.amount = 1;
    for (int i = 0; i < this->_amount; i++) {
        this->_orders.push_back(clientOrder);
    }
    clientOrder.amount = this->_amount;
}

// Setting the pizzas type
void Prompt::setPizza(std::string line)
{
    std::string pizza("");
    std::regex regexp("[a-zA-Z]+");
    auto ite = std::sregex_iterator(line.begin(), line.end(), regexp);
    auto end = std::sregex_iterator();

    this->_pizzaType = PizzaType::NoneType;
    for (std::sregex_iterator i = ite; i != end; i++) {
        std::smatch match = *i;
        pizza = match.str();
        std::transform(pizza.begin(), pizza.end(), pizza.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
        if (pizza.compare("") != 0)
            break;
    }
    for (size_t i = 0; pizzaNames[i].type != PizzaType::NoneType; i++)
        if (pizza.compare(pizzaNames[i].name) == 0)
            this->_pizzaType = pizzaNames[i].type;
}

// Setting the pizzas amount
void Prompt::setAmount(std::string line)
{
    std::regex regexp("x[0-9]+");
    auto ite = std::sregex_iterator(line.begin(), line.end(), regexp);
    auto end = std::sregex_iterator();

    this->_amount = 0;
    for (std::sregex_iterator i = ite; i != end; i++) {
        std::smatch match = *i;
        this->_amount = std::stoi(match.str().c_str() + 1);
    }
}

// Setting the pizzas size
void Prompt::setSize(std::string line)
{
    std::string size = ("");
    std::regex regexp("S|M|L|XL|XXL");
    auto ite = std::sregex_iterator(line.begin(), line.end(), regexp);
    auto end = std::sregex_iterator();

    this->_pizzaSize = PizzaSize::NoneSize;
    for (std::sregex_iterator i = ite; i != end; i++) {
        std::smatch match = *i;
        size = match.str();
    }
    for (size_t i = 0; pizzaSizes[i].size != PizzaSize::NoneSize; i++)
        if (size.compare(pizzaSizes[i].name) == 0)
            this->_pizzaSize = pizzaSizes[i].size;
}

// Parsing the order one by one with a regex
void Prompt::parsingInput(std::string line)
{
    std::regex regexp("[^;]+");
    auto ite = std::sregex_iterator(line.begin(), line.end(), regexp);
    auto end = std::sregex_iterator();

    for (std::sregex_iterator i = ite; i != end; i++) {
        std::smatch match = *i;
        this->setPizza(match.str());
        this->setSize(match.str());
        this->setAmount(match.str());
        this->addingOrderToVector();
    }
}

Prompt::~Prompt()
{
    this->_orders.clear();
}