#include <iostream>
#include <fstream>
#include <string>

int findGameNum(std::string string)
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
    const int redLimit = 12;
    const int greenLimit = 13;
    const int blueLimit = 14;
    int redCubes;
    int greenCubes;
    int blueCubes;

    int gameNum;
    int colonPos;
    int semicolonPos;
    bool checkRun = true;
    std::string string = "Game 123: 12 red, 2 green, 5 blue; 9 red, 6 green, 4 blue; 10 red, 2 green, 5 blue; 8 blue, 9 red";
    /*
     */
    gameNum = findGameNum(string);

    colonPos = string.find(":");
    colonPos = colonPos + 1;
    if (colonPos != std::string::npos)
    {
        string = string.substr(colonPos + 1);
    }

    semicolonPos = string.find(";");
    std::string cubeSubsets[4];
    int i = 0;
    while (checkRun == true && i < 3)
    {
        if (semicolonPos != std::string::npos)
        {
            cubeSubsets[i] = string.substr(0, semicolonPos);
            semicolonPos = semicolonPos + 1;
            string = string.substr(semicolonPos + 1);
            semicolonPos = string.find(";");
        }
        else
        {
            checkRun = false;
        }
        i++;
    }

    /*
    std::cout << cubeSubsets[0] << "\n"
              << cubeSubsets[1] << "\n"
              << cubeSubsets[2] << "\n"
              << cubeSubsets[3] << "\n";
    */

    checkRun = true;
    std::string totalNumS;
    std::string totalNum1;
    std::string totalNum2;
    int totalNum;

    std::string colour;
    int colourPos;
    while (checkRun == true)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < cubeSubsets[i].length(); j++)
            {
                if (isdigit(cubeSubsets[i][j]))
                {
                    totalNum1 = cubeSubsets[i][j];
                    if (j + 1 < cubeSubsets[i].length() && isdigit(cubeSubsets[i][j + 1]))
                    {
                        totalNum2 = cubeSubsets[i][j + 1];
                        totalNumS = totalNum1 + totalNum2;
                        totalNum = std::stoi(totalNumS);
                        checkRun = false;
                    }
                    
                    std::string leftovers = cubeSubsets[i].substr(j + 1);
                    if ((colourPos = leftovers.find("red")) != std::string::npos)
                    {
                        colour = "red";
                    }
                    else if ((colourPos = leftovers.find("green")) != std::string::npos)
                    {
                        colour = "green";
                    }
                    else if ((colourPos = leftovers.find("blue")) != std::string::npos)
                    {
                        colour = "blue";
                    }
                }
                std::cout << totalNum << " " << colour << "\n";
            }
        }
        checkRun = false;
    }
}

// Take string find first num then remove that bit and check if that num is under limit if yes continue then do the same until end, if all are valid then add game num to total num