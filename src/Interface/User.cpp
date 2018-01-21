//
// Created by Arthur  on 1/20/18.
//

#include "User.h"

User::User() {
    userFileLocation = "../../HeroesOfCivilization/ResourceFiles/users";
    userBufferFileLocation = "../../HeroesOfCivilization/ResourceFiles/usersBuffer";
}

bool User::FindUser(std::string name) {
    std::ifstream userFile(userFileLocation);
    assert(userFile);

    std::string line;
    std::istringstream iss;

    while (getline(userFile, line)) {
        iss.str(line);
        std::string tmp;
        iss >> tmp;

        if (tmp == name) {
            userFile.clear();
            userFile.seekg(0);
            userFile.close();

            return true;
        }
    }

    userFile.clear();
    userFile.seekg(0);
    userFile.close();

    return false;
}

int User::GetPoints(std::string name) {
    std::ifstream userFile(userFileLocation);
    assert(userFile);

    std::string line;
    std::istringstream iss;

    while (getline(userFile, line)) {
        iss.str(line);
        std::string tmp;
        iss >> tmp;

        //        tmp.clear();
        //        iss >> tmp;

        if (tmp == name) {
            iss >> tmp;
            int result = atoi(tmp.c_str());
            userFile.clear();
            userFile.seekg(0);
            userFile.close();

            return result;
        }
    }

    userFile.clear();
    userFile.seekg(0);
    userFile.close();

    return 0;
}

void User::ChangeUserPoints(std::string name, int points) {
    std::ifstream userFile(userFileLocation);
    assert(userFile);

    std::string line;
    std::istringstream iss;

    std::ofstream newUserData(userBufferFileLocation);

    bool flag = false;

    while (getline(userFile, line)) {
        std::string tmp;
        iss.str(line);
        iss >> tmp;
        if (tmp == name) {
            newUserData << name << " " << points << "\n";
            flag = true;
            continue;
        } else {
            newUserData << line << "\n";
        }
    }

    if (!flag) {
        newUserData << name << " " << points << "\n";
    }

    userFile.clear();
    userFile.seekg(0);
    userFile.close();
    newUserData.close();

    std::ifstream newUserData1(userBufferFileLocation);
    std::ofstream userFile1(userFileLocation);

    std::string str;
    while (getline(newUserData1, str)) {
        userFile1 << str << "\n";
    }
    newUserData1.close();

}