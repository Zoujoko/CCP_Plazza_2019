/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** plazza_tests
*/

#include "../inc/plazza.hpp"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

/// PROMPT ///
Test(create_prompt_1, prompt)
{
    Prompt *test_prompt = new Prompt();

    cr_assert(test_prompt->getAmount() == 0);
}

Test(create_prompt_2, prompt)
{
    Prompt *test_prompt = new Prompt();

    cr_assert(test_prompt->getSize() == PizzaSize::NoneSize);
}

Test(create_prompt_3, prompt)
{
    Prompt *test_prompt = new Prompt();

    cr_assert(test_prompt->getType() == PizzaType::NoneType);
}

Test(get_pizza_size_1, prompt)
{
    PizzaSize size = L;
    Prompt *test_prompt = new Prompt();

    cr_assert(test_prompt->gettingPizzaSize(size).compare("L") == 0);
}

Test(get_pizza_size_2, prompt)
{
    PizzaSize size = NoneSize;
    Prompt *test_prompt = new Prompt();

    cr_assert(test_prompt->gettingPizzaSize(size).compare("None") == 0);
}

Test(get_pizza_name_1, prompt)
{
    PizzaType type = Regina;
    Prompt *test_prompt = new Prompt();

    cr_assert(test_prompt->gettingPizzaName(type).compare("regina") == 0);
}

Test(get_pizza_name_2, prompt)
{
    PizzaType type = NoneType;
    Prompt *test_prompt = new Prompt();

    cr_assert(test_prompt->gettingPizzaName(type).compare("None") == 0);
}

Test(parsing_input_1, prompt)
{
    Prompt *test_prompt = new Prompt();

    std::string line = "regina XXL x2";
    test_prompt->parsingInput(line);
    cr_assert(test_prompt->getType() == PizzaType::Regina);
}

Test(parsing_input_2, prompt)
{
    Prompt *test_prompt = new Prompt();

    std::string line = "regina XXL x2";
    test_prompt->parsingInput(line);
    cr_assert(test_prompt->getSize() == PizzaSize::XXL);
}

Test(parsing_input_3, prompt)
{
    Prompt *test_prompt = new Prompt();

    std::string line = "regina XXL x2";
    test_prompt->parsingInput(line);
    cr_assert(test_prompt->getAmount() == 2);
}

Test(destruct_prompt, prompt)
{
    Prompt *test_prompt = new Prompt();

    test_prompt->~Prompt();

    cr_assert(test_prompt);
}

/// PIZZA ///
Test(create_pizza_1, pizza)
{
    order_t test_order;
    test_order.pizza = Regina;

    Pizza *test_pizza  = new Pizza(test_order, 1);

    cr_assert(test_pizza->getType() == PizzaType::Regina);
}

Test(create_pizza_2, pizza)
{
    std::string test_str = "1|8|2.00000";

    Pizza *test_pizza  = new Pizza(test_str);

    cr_assert(test_pizza->getSize() == PizzaSize::XXL);
}

Test(create_pizza_3, pizza)
{
    order_t test_order;
    test_order.pizza = Regina;

    Pizza *test_pizza  = new Pizza(test_order, 1);

    cr_assert(test_pizza->getType() == PizzaType::Regina);
}
Test(create_pizza_4, pizza)
{
    order_t test_order;
    test_order.pizza = Regina;

    Pizza *test_pizza  = new Pizza(test_order, 1);

    cr_assert(test_pizza->getBakingTime() == 2);
}


Test(serialize_data, pizza)
{
    std::string test_str = "1|8|2.00000";

    Pizza *test_pizza  = new Pizza(test_str);

    cr_assert(test_pizza->serializeData().compare("1|8|2.00000"));
}

Test(destruct_pizza, pizza)
{
    order_t test_order;
    test_order.size = L;

    Pizza *test_pizza  = new Pizza(test_order, 1);
    test_pizza->~Pizza();

    cr_assert(test_pizza);
}

/// ERROR ///
Test(create_error_1, error)
{
    std::string type = "err type";
    std::string message = "err message";

    Error *test_error = new Error(type, message);

    cr_assert(strcmp(test_error->what(), "err message") == 0);
}

Test(create_error_2, error)
{
    std::string type = "err type";
    std::string message = "err message";

    Error *test_error = new Error(type, message);

    cr_assert(test_error->getType().compare("err type") == 0);
}

Test(destruct_error, error)
{
    std::string type = "err type";
    std::string message = "err message";

    Error *test_error = new Error(type, message);
    test_error->~Error();

    cr_assert(test_error);
}

/// SHARED MEMORY ///
Test(send_and_receive_message, shared_memory)
{
    SharedMemory *test_ipc = new SharedMemory();
    std::string message = "just a test";

    test_ipc->sendMessage(message);

    cr_assert(strcmp((char *)test_ipc->receiveMessage(), "just a test") == 0);
}

Test(destruct_shared_memory, shared_memory)
{
    SharedMemory *test_ipc = new SharedMemory();

    test_ipc->~SharedMemory();

    cr_assert(test_ipc);
}

/// RECEPTION ///
Test(create_reception_1, reception)
{
    std::string multi = "2";
    std::string cooks = "5";
    std::string time = "2000";

    Reception *test_reception = new Reception(multi, cooks, time);

    cr_assert(test_reception->getMulti() == 2);
}

Test(create_reception_2, reception)
{
    std::string multi = "2";
    std::string cooks = "5";
    std::string time = "2000";

    Reception *test_reception = new Reception(multi, cooks, time);

    cr_assert(test_reception->getCooks() == 5);
}

Test(create_reception_3, reception)
{
    std::string multi = "2";
    std::string cooks = "5";
    std::string time = "2000";

    Reception *test_reception = new Reception(multi, cooks, time);

    cr_assert(test_reception->getRestockTime() == 2000);
}

Test(create_reception_4, reception)
{
    std::string multi = "2";
    std::string cooks = "5";
    std::string time = "2000";

    Reception *test_reception = new Reception(multi, cooks, time);

    cr_assert(test_reception->getGood() == true);
}

Test(good_order, reception)
{
    std::string multi = "2";
    std::string cooks = "5";
    std::string time = "2000";

    Reception *test_reception = new Reception(multi, cooks, time);

    cr_assert(test_reception->goodOrder() == true);
}

Test(add_to_log, reception)
{
    std::string multi = "2";
    std::string cooks = "5";
    std::string time = "2000";

    Reception *test_reception = new Reception(multi, cooks, time);

    cr_assert(test_reception->addingToLog() == true);
}

Test(destruct_reception, reception)
{
    std::string multi = "2";
    std::string cooks = "5";
    std::string time = "2000";

    Reception *test_reception = new Reception(multi, cooks, time);
    test_reception->~Reception();

    cr_assert(test_reception);
}

/// MUTEX ///
Test(all_mutex, mutex)
{
    Mutex *test_mutex = new Mutex();

    test_mutex->lock();
    test_mutex->unlock();
    test_mutex->trylock();
    test_mutex->~Mutex();

    cr_assert(test_mutex);
}

/// KITCHEN ///
Test(create_kitchen_1, kitchen)
{
    int time = 5;
    int cooks = 2;
    int restock = 200;

    Kitchen *test_kitchen = new Kitchen(time, cooks, restock);

    cr_assert(test_kitchen->getCookingTime() == 5);
}

Test(create_kitchen_2, kitchen)
{
    int time = 5;
    int cooks = 2;
    int restock = 200;

    Kitchen *test_kitchen = new Kitchen(time, cooks, restock);

    cr_assert(test_kitchen->getCooksNb() == 2);
}

Test(create_kitchen_3, kitchen)
{
    int time = 5;
    int cooks = 2;
    int restock = 200;

    Kitchen *test_kitchen = new Kitchen(time, cooks, restock);

    cr_assert(test_kitchen->getRestockTime() == 200);
}

Test(create_kitchen_4, kitchen)
{
    int time = 5;
    int cooks = 2;
    int restock = 200;

    Kitchen *test_kitchen = new Kitchen(time, cooks, restock);

    cr_assert(test_kitchen->getCommand().compare(""));
}

// Test(all_kitchen, kitchen)
// {
//     int time = 5;
//     int cooks = 2;
//     int restock = 200;

//     Kitchen *test_kitchen = new Kitchen(time, cooks, restock);

//     test_kitchen->checkingCooks();

//     cr_assert(test_kitchen);
// }

Test(get_status, kitchen)
{
    int time = 5;
    int cooks = 2;
    int restock = 200;

    Kitchen *test_kitchen = new Kitchen(time, cooks, restock);

    SharedMemory test_mem = SharedMemory();

    cr_assert(test_kitchen->getStatus(test_mem) == true);
}

Test(get_pid, kitchen)
{
    int time = 5;
    int cooks = 2;
    int restock = 200;

    Kitchen *test_kitchen = new Kitchen(time, cooks, restock);

    cr_assert(test_kitchen->getPid() != 0);
}

Test(get_nb_commands, kitchen)
{
    int time = 5;
    int cooks = 2;
    int restock = 200;

    Kitchen *test_kitchen = new Kitchen(time, cooks, restock);

    cr_assert(test_kitchen->checkNbCommands() == true);
}

Test(print_status, kitchen)
{
    int time = 5;
    int cooks = 2;
    int restock = 200;

    Kitchen *test_kitchen = new Kitchen(time, cooks, restock);
    test_kitchen->printStatus();

    cr_assert(test_kitchen);
}

Test(test_cooks_and_destruct, kitchen)
{
    int time = 5;
    int cooks = 2;
    int restock = 200;

    Kitchen *test_kitchen = new Kitchen(time, cooks, restock);
    test_kitchen->startCooks();
    test_kitchen->joinCooks();
    test_kitchen->isKitchenActive();
    test_kitchen->restockIngredients();
    test_kitchen->~Kitchen();

    cr_assert(test_kitchen);
}

/// COOK ///
static void *increment(void *ptr)
{
    return (ptr);
}

Test(create_cook, cook)
{
    int x = 2;
    Cook *test_cook = new Cook(NULL, increment, &x);
    test_cook->start();
    test_cook->join();

    cr_assert(test_cook);
}

Test(destruct_cook, cook)
{
    int x = 2;
    Cook *test_cook = new Cook(NULL, increment, &x);

    test_cook->~Cook();

    cr_assert(test_cook);
}

/// PROCESS ///
Test(create_process, process)
{
    SharedMemory mem = SharedMemory();
    float multiplier = 2;
    int maxCooks = 5;
    int restock = 2000;

    Process *test_process = new Process(mem, multiplier, maxCooks, restock);
    test_process->getProcessPid();
    test_process->~Process();

    cr_assert(test_process);
}