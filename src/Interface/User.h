//
// Created by Arthur  on 1/20/18.
//

#ifndef HEROESOFCIVILIZATION_USER_H
#define HEROESOFCIVILIZATION_USER_H


#include <string>
#include <fstream>
#include <cassert>
#include <sstream>

class User {
public:
    User();

    void ChangeUserPoints(std::string, int);

    int GetPoints(std::string);
    bool FindUser(std::string);

private:
    std::string userFileLocation;
    std::string userBufferFileLocation;
};

#endif //HEROESOFCIVILIZATION_USER_H
