#include <iostream>

// Хранение данных - структура
struct Point
{
    // Поля
    int x;
    int y;
};

// Когда мы работаем с данными - класс
class Circle
{ 
    // Поля
    float m_r;
    Point m_p;

public:
    // Методы
    // Конструктор, нет возвращаемого значения, название совпадает с именем класса,
    // вызывается всегда при создании обьекта
    Circle(float r, Point p)
    {
        std::cout << "Constr" << std::endl;
        m_r = r; // Или (*this).r или this->r
        p = p;
    }

    ~Circle()
    {
        std::cout << "Destr" << std::endl;
    }

    // Сеттеры
    void setR(float r)
    {
        if (r < 0)
        {
            std::cout << "Negative radius!" << std::endl;
            return;
        }
        m_r = r;
    }

    // Геттеры
    float getR()
    {
        return m_r;
    }

    float Square()
    {
        return acos(-1) * m_r * m_r;
    }
};

void f(Circle c)
{
    std::cout << c.Square() << std::endl;
}

class RectPlus
{
    int m_a, m_b, m_c;
    std::string m_color;

public:
    // Конструктор по умолчанию
    // RectPlus() {} ИЛИ RectPlus() = default;
    RectPlus() = default;
    RectPlus(int a, int b, int c)
    {
        setA(a);
        setB(b);
        setC(c);
    }

    void setA(int a)
    {
        if (a < 0)
        {
            std::cout << "Negative A" << std::endl;
        }
        m_a = a;
    }
    void setB(int b)
    {
        if (b < 0)
        {
            std::cout << "Negative B" << std::endl;
        }
        m_b = b;
    }
    void setC(int c)
    {
        if (c < 0)
        {
            std::cout << "Negative C" << std::endl;
        }
        m_c = c;
    }

    int Volume()
    {
        return m_a * m_b * m_c;
    }
};

class Matrix
{
    int m_n, m_m;
    int** m_mat;

public:
    Matrix(int n, int m)
    {
        setN(n);
        setM(m);
        m_mat = new int* [n];
        for (int i = 0; i < n; i++)
        {
            m_mat[i] = new int[m];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < m_n; i++)
        {
            delete[] m_mat[i];
        }
        delete[] m_mat;
    }

    void setN(int n)
    {
        if (n <= 0)
        {
            std::cout << "Negative N" << std::endl;
            exit(-1);
        }
        m_n = n;
    }
    void setM(int m)
    {
        if (m <= 0)
        {
            std::cout << "Negative M" << std::endl;
            exit(-1);
        }
        m_m = m;
    }

    void Read()
    {
        for (int i = 0; i < m_n; i++)
        {
            for (int j = 0; j < m_m; j++)
            {
                std::cin >> m_mat[i][j];
            }
        }
    }
};

int main()
{
    Matrix mat(2, 2);
    mat.Read();

    RectPlus rec;
    rec.setA(1);
    rec.setB(2);
    rec.setC(3);
    std::cout << rec.Volume() << std::endl;

    // Точка 1
    Point p1 = { 2,3 };
    p1.x;
    p1.y;

    // Точка 2
    Point p2 = { 4,5 };

    // Создается на стеке
    Circle c1(1, p1); // Circle - класс, c1 - обьект/экземпляр класса
    c1.setR(-10);

    std::cout << c1.getR() << std::endl;
    std::cout << c1.Square() << std::endl;

    // Можно вызвать деструктор таким образом, но у переменных, созданных на стеке,
    // диструктор вызывается автоматически
    c1.~Circle();

    return 0;
}