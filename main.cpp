#include <iostream>
#include "functions.h"
#include <fstream>
#include <vector>

//compilation
//g++ -o scratch.exe scratch.cpp inputs.cpp

std::fstream fileArchives;

struct record 
{
    
    char id_akt[1][50] {};
    char type[1][50] {}; // 
    char supervisor[2][128] {};
    char accused[2][128] {};
    char victim[2][128] {};
    char witnes[2][128] {};
    char data_start [11] {};
    char data_end [11] {};
    int num_row_s;
    int num_row_a;
    int num_row_v;
    int num_row_w;

    void reset()
    {
        char id_akt[1][50] {};
        char type[1][50] {}; // 
        char supervisor[2][128] {};
        char accused[2][128] {};
        char victim[2][128] {};
        char witnes[2][128] {};
        char data_start [11] {};
        char data_end [11] {};
    }
};

std::vector<record> akta;

bool search(record r, int number_of_record)
{
    for (int i = 0; i <= number_of_record+10; i++)
    {
        if (compare(akta[i].id_akt[0], r.id_akt[0]))
        {
            return 1;
        }
    }
    return 0;
}

int search_record_by_id(char str[], int number_of_record)
{
    for (int i = 0; i <= number_of_record+1; i++)
    {
        if (compare(akta[i].id_akt[0], str))
        {
            return i;
        }
    }

    return -1;
}

int add_record_beta(int number_of_record)
{
    record r1;
    r1.reset();

    int i1, i2;
    std::cout << "Wprowadz numer akt sprawy: " << '\n';
    i1 = input_id(r1.id_akt);

    while (search(r1, number_of_record))
    {
        std::cout << "Juz istnieje taki numer akt. Wprowadz inny: " << '\n';
        i1 = input_id(r1.id_akt);
    }

    fileArchives << r1.id_akt[0] << '\n';
    std::cout << "Wprowadz typ sprawy: " << '\n';
    i2 = input_id(r1.type);
    fileArchives << r1.type[0] << '\n';
    std::cout << "Wprowadz IMIE i NAZWISKO oficera prowadzacego sprawe: " << '\n';
    r1.num_row_s = input(r1.supervisor);
    fileArchives << r1.supervisor[0] << ' ' << r1.supervisor[1] << '\n';
    std::cout << "Wprowadz IMIE i NAZWISKO oskarzonego: " << '\n';
    r1.num_row_a = input(r1.accused);
    fileArchives << r1.accused[0] << ' ' << r1.accused[1] << '\n';
    std::cout << "Wprowadz IMIE i NAZWISKO poszkodowanego: " << '\n';
    r1.num_row_v = input(r1.victim);
    fileArchives << r1.victim[0] << ' ' << r1.victim[1] << '\n';
    std::cout << "Wprowadz IMIE i NAZWISKO swiadka: " << '\n';
    r1.num_row_w = input(r1.witnes);
    fileArchives << r1.witnes[0] << ' ' << r1.witnes[1] << '\n';

    akta.push_back(r1);

    number_of_record++;

    return number_of_record;
}

void show_record(record r)
{
    if (r.id_akt[0][0] != '@')
    {
        std::cout << '\n' << '\n';
        std::cout << "**********************************************************************************************************" << '\n';
        std::cout << "Dane wybranych akt: " << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "**********************************************************************************************************" << '\n';
        std::cout << "Numer akt sparwy: " << r.id_akt[0] << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Typ sprawy: " << r.type[0] << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Oficer prowadzacy sprawe: " << r.supervisor[0] << ' ' << r.supervisor[1] << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Oskarzony: " << r.accused[0] << ' ' << r.accused[1] << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Poszkodowany: " << r.victim[0] << ' ' << r.victim[1] << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Swiadek: " << r.witnes[0] << ' ' << r.witnes[1] << '\n';
        std::cout << "**********************************************************************************************************" << '\n';
        std::cout << '\n' << '\n';
    }
    else
    {
        std::cout << "**********************************************************************************************************" << '\n';
        std::cout << "Dane wybranych akt: " << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "**********************************************************************************************************" << '\n';
        std::cout << "Numer akt sparwy: " << ' ' << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Typ sprawy: " << ' ' << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Oficer prowadzacy sprawe: " << ' ' << ' ' << ' ' << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Oskarzony: " << ' ' << ' ' << ' ' << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Poszkodowany: " << ' ' << ' ' << ' ' << '\n';
        std::cout << "                                                                                                         |" << '\n';
        std::cout << "Swiadek: " << ' ' << ' ' << ' ' << '\n';
        std::cout << "**********************************************************************************************************" << '\n';
    }
}

void search_record_by_type(char str[], int number_of_record)
{
    int count = 0;

    for (int i = 0; i <= number_of_record; i++)
    {
        if (compare(akta[i].type[0], str))
        {
            show_record(akta[i]);
            count ++;
        }
    }

    if (count == 0)
    {
        std::cout << "Nie ma takiego typu sprawy." << '\n'; 
    }
}

int number_of_lines() // the aprovimate size of dynamic arrays
{
    int k = 0;
    char str[128];
    fileArchives.open("archiwa.txt", std::fstream::in | std::fstream::out);

    while(!fileArchives.eof())
    {
        fileArchives >> str;
        k++;
    }

    fileArchives.close();

    return k;
}

int read_records_dynamic(char **data) //char data[][128]
{
    int k = 0;

    fileArchives.open("archiwa.txt", std::fstream::in | std::fstream::out);

    while(!fileArchives.eof())
    {
        fileArchives >> data[k];
        //std::cout << data[k] << ' ';
        //std::cout << k << '\n';
        k++;
    }
    //std::cout << '\n' << k << '\n';

    int s = 0, x = 0, c = 0, l=0;
    while (s < k-1)
    {
        std::cout << data[s] << '\n';
        std::cout << data[s+1] << '\n';
        std::cout << data[s+2] << ' ';
        std::cout << data[s+3] << '\n';
        std::cout << data[s+4] << ' ';
        std::cout << data[s+5] << '\n';
        std::cout << data[s+6] << ' ';
        std::cout << data[s+7] << '\n';
        std::cout << data[s+8] << ' ';
        std::cout << data[s+9] << '\n';

        record rtemp;
        rtemp.reset();       
        x = 0;
        while (data[s][x] != '\0')
        {
            rtemp.id_akt[0][x] = data[s][x];
            x++;
        }
        x = 0;
        while (data[s+1][x] != '\0')
        {
            rtemp.type[0][x] = data[s+1][x];
            x++;
        }
        x = 0;
        while (data[s+2][x] != '\0')
        {
            rtemp.supervisor[0][x] = data[s+2][x];
            x++;
        }
        x = 0;
        while (data[s+3][x] != '\0')
        {
            rtemp.supervisor[1][x] = data[s+3][x];
            x++;
        }
        x = 0;
        while (data[s+4][x] != '\0')
        {
            rtemp.accused[0][x] = data[s+4][x];
            x++;
        }
        x = 0;
        while (data[s+5][x] != '\0')
        {
            rtemp.accused[1][x] = data[s+5][x];
            x++;
        }
        x = 0;
        while (data[s+6][x] != '\0')
        {
            rtemp.victim[0][x] = data[s+6][x];
            x++;
        }
        x = 0;
        while (data[s+7][x] != '\0')
        {
            rtemp.victim[1][x] = data[s+7][x];
            x++;
        }
        x = 0;
        while (data[s+8][x] != '\0')
        {
            rtemp.witnes[0][x] = data[s+8][x];
            x++;
        }
        x = 0;
        while (data[s+9][x] != '\0')
        {
            rtemp.witnes[1][x] = data[s+9][x];
            x++;
        }
        akta.push_back(rtemp);

        s += 10;
    }

    fileArchives.close();

    return s/10;
}

void save_records(int number_of_records) 
{                                         
    fileArchives.open("archiwa.txt", std::fstream::in | std::fstream::out);

    for (int i = 0; i <= number_of_records; i++)
    {
        if (akta[i].id_akt[0][0] != '@')
        {
            fileArchives << '\n';
            fileArchives << akta[i].id_akt[0] << '\n';
            fileArchives << akta[i].type[0] << '\n';
            fileArchives << akta[i].supervisor[0] << ' ' << akta[i].supervisor[1] << '\n';
            fileArchives << akta[i].accused[0] << ' ' << akta[i].accused[1] << '\n';
            fileArchives << akta[i].victim[0] << ' ' << akta[i].victim[1] << '\n';
            fileArchives << akta[i].witnes[0] << ' ' << akta[i].witnes[1] << '\n';
        }
    }

    for(int i = 0; i < number_of_records; i++)
    {
        fileArchives << '\n';
        fileArchives << ' ' << '\n';
        fileArchives << ' ' << '\n';
        fileArchives << ' ' << ' ' << ' ' << '\n';
        fileArchives << ' ' << ' ' << ' ' << '\n';
        fileArchives << ' ' << ' ' << ' ' << '\n';
        fileArchives << ' ' << ' ' << ' ' << '\n';
    }

    fileArchives.close();
}


void delete_records(int index)
{
    //std::cout << "Wprowadz indeks _akt_ ktore chcesz usunac: " << '\n';
    //std::cin >> index;
    akta[index].id_akt[0][0] = '@';
    akta[index].type[0][0] = '@';
    akta[index].supervisor[0][0] = '@';
    akta[index].supervisor[1][0] = '@';
    akta[index].accused[0][0] = '@';
    akta[index].accused[1][0] = '@';
    akta[index].victim[0][0] = '@';
    akta[index].victim[1][0] = '@';
    akta[index].witnes[0][0] = '@';
    akta[index].witnes[1][0] = '@';
}

void delete_records_beta()
{
    int index;
    std::cout << "Wprowadz indeks _akt_ ktore chcesz usunac: " << '\n';
    std::cin >> index;    
}

void edit_records(int index, int number_of_records)
{
    char choice;
    if (index < number_of_records)
    {
        std::cout << "Czy na pewno chcesz zmienic dane _akt_ ? " << '\n' << "Wpisz y : tak, n : nie (lub dowolny inny znak)" << '\n';
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            show_record(akta[index]);
            int i1, i2;
            std::cout << "Wprowadz numer akt sprawy: " << '\n';
            i1 = input_id(akta[index].id_akt);
            std::cout << "Wprowadz typ sprawy: " << '\n';
            i2 = input_id(akta[index].type);
            std::cout << "Wprowadz IMIE i NAZWISKO oficera prowadzacego sprawe: " << '\n';
            akta[index].num_row_s = input(akta[index].supervisor);
            std::cout << "Wprowadz IMIE i NAZWISKO oskarzonego: " << '\n';
            akta[index].num_row_a = input(akta[index].accused);
            std::cout << "Wprowadz IMIE i NAZWISKO poszkodowanego: " << '\n';
            akta[index].num_row_v = input(akta[index].victim);
            std::cout << "Wprowadz IMIE i NAZWISKO swiadka: " << '\n';
            akta[index].num_row_w = input(akta[index].witnes);
        }
        
    }
}

void run(int number_of_records)
{
    char choice;

    while (1)
    {
        std::cout << "__________________________________________________________________________________________________________" << '\n';
        std::cout << "Wybierz swoja akcje: " << '\n';
        std::cout << "__________________________________________________________________________________________________________" << '\n';
        std::cout << "Aby DODAC nowe _akta_ wcisnij:  d" << '\n';
        std::cout << '\n';
        std::cout << "Aby USUNAC _akta_ wcisnij:  u" << '\n';
        std::cout << '\n';
        std::cout << "Aby WYSWIETLIC _akta_ wcisnij:  w" << '\n';
        std::cout << '\n';
        std::cout << "Aby WYSZUKAC _akta_ po TYPIE sprawy wcisnij:  s" << '\n';
        std::cout << '\n';
        std::cout << "Aby EDYTOWAC _akta_ wcisnij:  e" << '\n';
        std::cout << '\n';
        std::cout << "Aby WYJSC nacisnij:  q" << '\n';
        std::cout << "__________________________________________________________________________________________________________" << '\n';
        std::cout << "Twoj wybor: " << '\n';
        std::cin >> choice;
        if (choice == 'q' || choice == 'Q')
        {
            save_records(number_of_records);
            break;
        } 
        else if (choice == 'd' || choice == 'D')
        {
            number_of_records = add_record_beta(number_of_records);        
        }
        else if (choice == 'w' || choice == 'W')
        {
            int index;
            char str[50];
            std::cout  << "Wprowadz numer _akt_ : " << '\n';
/*
            do 
            {
                std::cout  << "Wprowadz numer _akt_ : " << '\n';
                std::cin >> idx;
            } 
            while ((idx < 48 || idx > 57));
*/          
            std::cin >> str;
            index = search_record_by_id(str, number_of_records);
            if (index > -1)
            {
                show_record(akta[index]);
            }
            else
            {
                std::cout << "Nie ma takiego numeru _akt_." << '\n';
            }
        }
        else if (choice == 's')
        {
            int index;
            char str[50];
            std::cout << "Wprowadz typ sprawy ktory chcesz znalezc" << '\n';
            std::cin >> str;
            search_record_by_type(str, number_of_records);
        }
        else if (choice == 'u' || choice == 'U')
        {
            int index;
            char str[50];
            std::cout << "Wprowadz indeks _akt_ ktore chcesz usunac: " << '\n';
            std::cin >> str;
            index = search_record_by_id(str, number_of_records);
            if (index > -1)
            {
                delete_records(index);
            }
            else
            {
                std::cout << "Nie ma takiego numeru _akt_." << '\n';
            }
        }
        else if (choice == 'e' || choice == 'E')
        {
            int index;
            char str[50];
            std::cout << "Wprowadz indeks _akt_ ktora chcesz zmienic: " << '\n';
            std::cin >> str;
            index = search_record_by_id(str, number_of_records);
            //std::cout << index;
            if (index > -1)
            {
                edit_records(index, number_of_records);
            }
            else
            {
                std::cout << "Nie ma takiego numeru _akt_." << '\n';
            }
        }
    }
}



int main()
{
    int number_of_records, size;
//to read pure data from txt file
    size = number_of_lines() + 10;

    char **data = new char*[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = new char[128];
    }
//end of this reading

    std::cout << size << '\n';
    number_of_records = read_records_dynamic(data);

    std::cout << number_of_records << '\n';

//freeing the memory space
    for (int i = 0; i < size; i++)
    {
        delete [] data[i];
    }
    delete [] data;
//end of frreing space

    //run actaual program to edit and view database
    run(number_of_records);

/*
    for (record el : akta)
    {
        std::cout << el.id_akt[0] << ' ';
    }
*/

    return 0;
}