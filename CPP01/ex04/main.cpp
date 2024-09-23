#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Parameters should be: filename, string to replace, new string" << std::endl;
        return (-1);
    }
    const char *file_in = argv[1];
    std::ifstream in(file_in);
    if (in.is_open() == false)
    {
        std::cout << "Error with opening file" << std::endl;
        return (-1);
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string file_out = file_in;
    file_out.append(".replace");
    std::string line;
    const char *file_out1 = &*file_out.data();
    std::ofstream out(file_out1);
    if (out.is_open() == false)
    {
        std::cout << "Error with creating file" << std::endl;
        return (-1);
    }
    while (std::getline(in, line))
    {
        for (unsigned i=0; i <= line.length();)
        {
            size_t position = line.find(s1, i);
            if (position == std::string::npos) break;
            line.erase(position, s1.length());
            line.insert(position, s2);
            i = position + 1;
        }
        out << line << std::endl;
    }
    in.close();
    out.close();
}




/*  замена строк
int main()
{
    std::string text ("A friend in need is a friend indeed.");
    std::string word ("friend");
    std::string word1 ("enemy");
    unsigned count=0;       // количество вхождений
    for (unsigned i=0; i <= text.length() - word.length(); )
    {
        size_t position = text.find(word, i); // получаем индекс
        //text.insert(position+word.length(), word1); //вставляет после 1 слова
        std::cout << text << std::endl;
        if (position == std::string::npos) break; // если не найдено ни одного вхождения с индекса i, выходим из цикла
        text.erase(position, word.length());
        text.insert(position, word1);
        ++count; // если же вхождение найдено, увеличиваем счетчик вхождений
        i = position + 1; // переходим к следующему индексу после position
    }
    std::cout << "The word is found " << count << " times." << std::endl; // The word is found 2 times.
}
*/

/* работа с файлом
int main()
{
    std::string line;
 
    std::ifstream in("hello.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();     // закрываем файл

    std::ofstream out;          // поток для записи
    out.open("hello.txt");      // открываем файл для записи
    if (out.is_open())
    {
        out << "Hello World!" << std::endl;
    }
    out.close(); 
    std::cout << "File has been written" << std::endl;
}
*/