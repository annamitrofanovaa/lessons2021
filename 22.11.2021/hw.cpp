#include <iostream>
#include <fstream>
#include <string.h>

std::string numb_to_HeX(int n)
{
    std::string s;
    while (n)
    {
        int r = n % 16;
        if (r < 10)
        {
            s = char(r + '0') + s;
        }
        else
        {
            s = char(r - 10 + 'A') + s;
        }
        n /= 16;
    }
    return s;
}

std::string write_zeroes(int n)
{
    std::string str = numb_to_HeX(n);
    int lenstr = str.length();
    for (int i = 0; i < 10 - lenstr; ++i)
    {
        str = '0' + str;
    }
    return str;
}

std::string char_to_HeX(unsigned char ch)
{
    int n = ch;
    std::string s;
    while (n)
    {
        int r = n % 16;
        if (r < 10)
        {
            s = char(r + '0') + s;
        }
        else
        {
            s = char(r - 10 + 'A') + s;
        }
        n /= 16;
    }
    if (s.length() < 2)
    {
        s = "0" + s;
    }
    return s;
}

int main()
{
    char ifname[256];
    char ofname[256];

    std::cout << "Source: ";
    std::cin.getline(ifname, 256);

    std::cout << "Destination: ";
    std::cin.getline(ofname, 256);

    std::ifstream inputFile(ifname, std::ios_base::binary);
    if (!inputFile)
    {
        std::cout << "Can not open file " << ifname << std::endl;
        return 1;
    }
    std::ofstream outputFile(ofname, std::ios_base::binary);
    if (!inputFile)
    {
        std::cout << "Can not open file " << ofname << std::endl;
        inputFile.close();
        return 2;
    }

    std::string str;
    int count = 0;
    int count_str = 0;
    int ch;

    while (inputFile.peek() != EOF)
    {
        if (count == 0)
        {
            outputFile << write_zeroes(count_str) << "0:";
        }
        ++count;
        ch = inputFile.get();
        if (ch < 32)
        {
            str += '.';
        }
        else
        {
            str += ch;
        }
        outputFile << char_to_HeX(ch) << " ";

        if (count == 8)
        {
            outputFile << "| ";
        }
        if (count == 16)
        {
            outputFile << " | " << str << std::endl;
            count = 0;
            str = "";
            ++count_str;
        }
    }
    if (count != 0 && count < 8)
    {
        for (int i = 0; i < 8 - count; ++i)
        {
            outputFile << "   ";
        }
        outputFile << "| ";
        for (int i = 0; i < 8; ++i)
        {
            outputFile << "   ";
        }
        outputFile << " | " << str;
    }
    else if (count)
    {
        for (int i = 0; i < 16 - count; ++i)
        {
            outputFile << "   ";
        }
        outputFile << " | " << str;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}