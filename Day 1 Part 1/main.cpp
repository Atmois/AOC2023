#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

int main()
{
    std::ifstream inputF("input.txt");
    std::string textS;
    bool checkRun = true;
    char checkingLetter;
    std::string num1;
    std::string num2;
    std::string totalS;
    double total;
    double overall = 0;

    while (std::getline(inputF, textS))
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
    inputF.close();
}