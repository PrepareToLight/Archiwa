#include <iostream>

int input(char arr[][128])
{
    int i = 0, n = 2;
    arr[0][0] = '0';
    arr[0][1] = '\0';
    arr[1][0] = '0';
    arr[1][1] = '\0';
    while (1)
    {
        std::cin >> arr[i];
        i++; 
        if (std::cin.get() == '\n') //str[i][0] == 'q' && str[i][1] == '!'
        {
            i--;
            break;
        }
    }
    return i;
}

void print(char arr[][128], int i)
{
    for (int k = 0; k < i + 1; k++)
    {
        std::cout << arr[k] << " ";
    }   
}

int input_id(char arr[][50])
{
    int i = 0;
    while (1)
    {
        std::cin >> arr[i];
        /*
        do 
        {
            std::cout << "Nie zaczynamy numerowania ani zadnego slowa od symbolu 0 (zero)" << '\n' << "Wprowadz ponownie" << '\n';
            std::cin >> arr[i];
        } 
        while (arr[i][0] == '0');
        */
        i++;
        if (std::cin.get() == '\n') //str[i][0] == 'q' && str[i][1] == '!'
        {
            i--;
            break;
        }
    }
    return i;
}

void print_id(char arr[][50], int i)
{
    for (int k = 0; k < i + 1; k++)
    {
        std::cout << arr[k] << " ";
    }   
}

/*
struct date
{

    char day[3];
    char month[3];
    char year[5];

   int day;
   int month;
   int year;
   date()
   {
        std::cout << "Wprowadz poprawna date" << '\n';
        do 
        {
            std::cout << "Wprowadz poprawny dzien: ";
            std::cin >> day;
        } while (day < 0 || day > 31);
        do 
        {
            std::cout << "Wprowadz poprawny miesiac: ";
            std::cin >> month;
        } while (month < 0 || month > 12);
        do 
        {
            std::cout << "Wprowadz poprawny rok: ";
            std::cin >> year;
        } while (year < 1000 || year > 3000);
   }
};
*/
struct date
{
    char day[3];
    char month[3];
    char year[5];
    date()
    {
        std::cout << "Wprowadz poprawna date" << '\n';
        do 
        {
            std::cout << "Wprowadz poprawny dzien: ";
            std::cin >> day;
        } while ((day[0] < 48 || day[0] > 57) || ((day[0] < 48 || day[0] > 57) && (day[1] < 48 || day[1] > 57)));
        do 
        {
            std::cout << "Wprowadz poprawny miesiac: ";
            std::cin >> month;
        } while ((month[0] < 48 || month[0] > 57) && (month[1] < 48 || month[1] > 57));
       do 
        {
            std::cout << "Wprowadz poprawny rok: ";
            std::cin >> year;
        } while ((year[0] < 48 || year[0] > 57) && (year[1] < 48 || year[1] > 57));

    }
};

void show(date d)
{      
    if ((d.day[0] < 48 || d.day[0] > 57) || (d.day[1] < 48 || d.day[1] > 57))
    {
        std::cout << '0' << d.day << ".";
    }
    else
    {
        std::cout << d.day << ".";
    }

    if ((d.month[0] < 48 || d.month[0] > 57) || (d.month[1] < 48 || d.month[1] > 57))
    {
        std::cout << '0' << d.month << ".";
    }
    else
    {
        std::cout << d.month << ".";
    }

    std::cout << d.year << '\n';


}

bool compare(char str1[], char str2[])
{
    int k1 = 0, k2 = 0, compare = 0;

    while (str1[k1] != '\0')
    {
        k1++;
    }
    while (str2[k2] != '\0')
    {
        k2++;
    }

    if (k1 == k2)
    {
        for (int i = 0; i < k1; i++)
        {
            if (str1[i] == str2[i])
            {
                compare++;
            }
        }

        if (compare == k1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}


/*
int main()
{

    date d;

    std::cout << d.day << "/" << d.month << "/" << d.year << '\n'; 

   return 0;
}
*/

