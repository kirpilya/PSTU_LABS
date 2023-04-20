#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int random(int max)
{
    return (rand() % (max + 1));
}
int hash_func(string tel_num, int tab_size);

string NAMES[10] = { "Андрей", "Антон", "Иван", "Сергей", "Владимир", "Николай", "Егор", "Дмитрий", "Данил", "Александр" };
string SURNAMES[10] = { "Соколов", "Кузнецов", "Попов", "Беляев", "Орлов", "Баранов", "Давыдов", "Павлов", "Романов", "Морозов" };
string PATRONYMIC[10] = { "Александрович", "Кирилович", "Олегович", "Иванович", "Алексеевич", "Михайлович", "Константинович", "Григорьевич", "Романович", "Николаевич" };
string DATES[10] = { "27.01.1988","28.02.1967","29.04.1999","30.05.1867","31.12.1999","01.06.1976","02.07.1980","03.08.1982","04.09.1955","05.10.1948" };

struct Human
{
    string name;
    string date;
    string tel_num;
    Human()
    {
        name = "NULL";
        date = "NULL";
        tel_num = "NULL";
    }
    void print()
    {
        cout << name << " " << date << " " << tel_num;
    }
};

struct hash_tab
{
    Human* humans;
    int t_size;
    int colls;
    hash_tab(int size)
    {
        humans = new Human[size];
        t_size = size;
        colls = 0;
    }
    ~hash_tab()
    {
        delete[]humans;
    }

    void print()
    {
        for (int i = 0; i < t_size; i++)
        {
            humans[i].print();
            cout << endl;
        }
    }

    void add(Human human, int size)
    {
        int idx = hash_func(human.tel_num, size);
        int hash = idx;
        if (humans[idx].name == "NULL")
        {
            humans[idx] = human;
            return;
        }
        else
        {
            while (idx < size)
            {
                if (humans[idx].name == "NULL")
                {
                    humans[idx] = human;
                    return;
                }
                idx++;
                colls++;
            }
            if (idx >= size)
            {
                idx = 0;
                colls++;
                while (idx < hash)
                {
                    if (humans[idx].name == "NULL")
                    {
                        humans[idx] = human;
                        return;
                    }
                    idx++;
                    colls++;
                }
            }
        }
    }

    void find(string tel, int size)
    {
        int hash = hash_func(tel, size);
        int idx = hash;
        while (humans[idx].tel_num != tel && idx < size)
        {
            idx++;
        }
        if (idx >= size)
        {
            idx = 0;
            while (humans[idx].tel_num != tel && idx < hash)
            {
                idx++;
            }
            if (idx >= hash)
            {
                cout << "Не найден" << endl;
            }
            else
            {
                cout << "Index: " << idx << endl;
            }
        }
        else
        {
            cout << "Index: " << idx << endl;
        }
    }
};

int hash_func(string tel_num, int tab_size)
{
    string tel_s;
    for (int i = 2; i < 10; i++)
    {
        tel_s += tel_num[i];
    }
    //cout << "tel_s = " << tel_s;
    int tel = stoi(tel_s);
    //cout << "   tel = " << tel;
    double ka = tel * 0.467;
    //cout << "   ka = " << ka;
    double t;
    double kamod1 = modf(ka, &t);
    //cout << "   kamod1 = " << kamod1 << "  ->  ";
    double H = tab_size * kamod1;;
    return int(H);
}

Human create_human()
{
    Human temp;
    temp.name = SURNAMES[random(9)] + " " + NAMES[random(9)] + " " + PATRONYMIC[random(9)];
    temp.date = DATES[random(9)];
    string temp_telnum = "89";
    for (int i = 0; i < 10; i++)
    {
        temp_telnum += to_string(random(9));
    }
    temp.tel_num = temp_telnum;
    return temp;
}

void fill_human_arr(Human* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = create_human();
    }
}

void print_human_arr(Human* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i].print();
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    int size_m;
    cout << "Размер массива: ";
    cin >> size_m;
    cout << endl;
    Human* humans = new Human[size_m];
    fill_human_arr(humans, size_m);
    cout << "Исходный массив:\n\n";
    print_human_arr(humans, size_m);
    cout << "\nХеш таблица:\n\n";
    hash_tab HASH_TABLE(size_m);
    for (int i = 0; i < size_m; i++)
    {
        HASH_TABLE.add(humans[i], size_m);
    }
    HASH_TABLE.print();
    cout << "\nПоиск по номеру: ";
    string str_f;
    cin >> str_f;
    cout << endl;
    HASH_TABLE.find(str_f, size_m);
    cout << "\nКоллизий: " << HASH_TABLE.colls;
    cout << "\n\n\n";

}