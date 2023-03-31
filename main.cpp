#include <iostream>
#include <fstream>

unsigned computeHash(const unsigned char *memory, int length) {
    unsigned hash = 0xbeaf;

    for (int c = 0; c < length; c++) {
        hash += memory[c];
        hash += hash << 10;
        hash ^= hash >> 6;
    }

    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;
    return hash;
}

struct User {
    unsigned id;
    char name[128];
};

struct Transaction {
    unsigned sender;
    unsigned receiver;
    double coins;
    long long time;
};

struct TransactionBlock {
    unsigned id;
    unsigned prevBlockId;
    unsigned prevBlockHash;
    int validTransactions;
    Transaction transactions[16];
};

User users[1000];

void createUser(char name[128], double invested)
{
    User newUser;
    newUser.id = rand();
    strcpy(newUser.name, name);
    //След създаването на потребителя се създава и системна трансакция
    // за захранване на сметката му. Тази начална трансакция се изпълнява от
    // системния потребител с идентификатор 0. Трансакцията превежда OOPCoin,
    // равно на 420 монети, за всеки един лев, който потребителят инвестира.

    Transaction newTransaction;
    newTransaction.sender = 0;
    newTransaction.receiver = newUser.id;
    newTransaction.coins = 420 * invested;
}

//Премахването на потребител е възможно с командата remove-user.
// Тя получава като параметър име на потребителя и ако то е валидно,
// премахва потребителя от системата. Всички негови OOPCoin се прехвърлят
// с трансакция на системния потребител с идентификатор 0.

void removeUser(char* name)
{
    if(!isValid(name))
    {
        std::cout << "No such user!" << std::endl;
    }
    Transaction trans;
    trans.sender =

}


int main()
{

}
