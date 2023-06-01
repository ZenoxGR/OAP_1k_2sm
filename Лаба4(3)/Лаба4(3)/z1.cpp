#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool hasMatchingWord(string line)
{
    string firstWord = "";
    int i = 0;
    while (line[i] != ' ')
    {
        firstWord += line[i];
        i++;
    }
    for (int j = i + 1; j < line.length(); j++)
    {
        if (line[j] == ' ')
        {
            string word = line.substr(i + 1, j - i - 1);
            if (firstWord == word)
            {
                return true;
            }
            i = j;
        }
    }
    return false;
}
int countConsonants(string line)
{
    int count = 0;
    string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    for (int i = 0; i < line.length(); i++)
    {
        if (consonants.find(line[i]) != string::npos)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    setlocale(LC_ALL, "rus");
    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");
    if (!file1.is_open() || !file2.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    string line;
    getline(file1, line);
    while (!file1.eof())
    {
        if (!hasMatchingWord(line))
        {
            file2 << line << endl;
        }
        getline(file1, line);
    }

    file1.close();
    file2.close();

    ifstream file2Read("FILE2.txt");
    if (!file2Read.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    getline(file2Read, line);
    int consonantCount = countConsonants(line);
    cout << "Кол-во согласных букв в первой строке файла FILE2: " << consonantCount << endl;

    file2Read.close();

    return 0;
}