#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

void wordsToNum()
{
    std::string tempLineStore;
    std::ifstream fileI("input.txt");
    std::ofstream fileO("input2.txt");
    while (std::getline(fileI, tempLineStore))
    {
        while (tempLineStore.find("one") != std::string::npos)
        {
            tempLineStore.replace(tempLineStore.find("one"), std::string("one").length(), "o1e");
        }
        while (tempLineStore.find("two") != std::string::npos)
        {
            tempLineStore.replace(tempLineStore.find("two"), std::string("two").length(), "t2o");
        }
        while (tempLineStore.find("three") != std::string::npos)
        {
            tempLineStore.replace(tempLineStore.find("three"), std::string("three").length(), "t3e");
        }
        while (tempLineStore.find("four") != std::string::npos)
        {
            tempLineStore.replace(tempLineStore.find("four"), std::string("four").length(), "f4r");
        }
        while (tempLineStore.find("five") != std::string::npos)
        {
            tempLineStore.replace(tempLineStore.find("five"), std::string("five").length(), "f5e");
        }
        while (tempLineStore.find("six") != std::string::npos)
        {
            tempLineStore.replace(tempLineStore.find("six"), std::string("six").length(), "s6x");
        }
        while (tempLineStore.find("seven") != std::string::npos)
        {
            tempLineStore.replace(tempLineStore.find("seven"), std::string("seven").length(), "s7n");
        }
        while (tempLineStore.find("eight") != std::string::npos)
        {
            tempLineStore.replace(tempLineStore.find("eight"), std::string("eight").length(), "e8t");
        }
        while (tempLineStore.find("nine") != std::string::npos)
        {
            tempLineStore.replace(tempLineStore.find("nine"), std::string("nine").length(), "n9n");
        }
        if (fileO.is_open())
        {
            fileO << tempLineStore << "\n";
        }
    }
    fileI.close();
    fileO.close();
}

int main()
{
    std::ifstream fileI("input2.txt");
    std::string textS;
    bool checkRun = true;
    char checkingLetter;
    std::string num1;
    std::string num2;
    std::string totalS;
    int total;
    int overall = 0;

    while (std::getline(fileI, textS))
    {
        while (checkRun == true)
        {
            for (int i = 0; i < textS.length(); i++)
            {
                checkingLetter = textS[i];
                if (isdigit(checkingLetter))
                {
                    num1 = std::string(1, checkingLetter);
                    checkRun = false;
                    break;
                }
            }
        }
        checkRun = true;
        reverse(textS.begin(), textS.end());
        while (checkRun == true)
        {
            for (int i = 0; i < textS.length(); i++)
            {
                checkingLetter = textS[i];
                if (isdigit(checkingLetter))
                {
                    num2 = std::string(1, checkingLetter);
                    checkRun = false;
                    break;
                }
            }
        }
        checkRun = true;
        totalS = num1 + num2;
        total = std::stod(totalS);
        overall = overall + total;
    }
    std::cout << overall;
    fileI.close();
}