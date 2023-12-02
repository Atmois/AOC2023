#include <iostream>
#include <fstream>
#include <string>

int findGameN(std::string string)
{
    std::string num1S;
    std::string num2S;
    std::string num3S;
    std::string gameNumS;
    int gameNum;
    bool checkRun = true;
    while (checkRun == true)
    {
        for (int i = 0; i < string.length(); i++)
        {
            if (isdigit(string[i]))
            {
                if (isdigit(string[i + 1]) && isdigit(string[i + 2]))
                {
                    num1S = string[i];
                    num2S = string[i + 1];
                    num3S = string[i + 2];
                    gameNumS = num1S + num2S + num3S;
                    gameNum = std::stoi(gameNumS);
                    checkRun = false;
                }
                else if (isdigit(string[i + 1]))
                {
                    num1S = string[i];
                    num2S = string[i + 1];
                    gameNumS = num1S + num2S;
                    gameNum = std::stoi(gameNumS);
                    checkRun = false;
                }
                else
                {
                    num1S = string[i];
                    gameNum = stoi(num1S);
                    checkRun = false;
                }

                break;
            }
        }
    }
    return gameNum;
}

int main()
{
    int gameNum;
    std::string string = "Game 123: 12 red, 2 green, 5 blue; 9 red, 6 green, 4 blue; 10 red, 2 green, 5 blue; 8 blue, 9 red";
    std::string string2 = "needle";

    gameNum = findGameN(string);

    if (string.find(string2) != std::string::npos)
    {
        std::cout << "!";
    }
}