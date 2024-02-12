#include <iostream>
using namespace std;

int main() {
    // Объявление необходимых переменных
    bool InsideTriangleC = false;
    bool isInCircle = false;
    bool isShaded = false;
    float x, y;

    // Вывод приветственного сообщения
    cout << "Enter (x y): ";
    // Ввод пользовательских координат
    cin >> x >> y;

    // Задаём вершины треугольников по отдельности
    // Треугольник в первой четверти
    float triangle1_ax = 6.0, triangle1_ay = 0.0;
    float triangle1_bx = 0.0, triangle1_by = 6.0;
    float triangle1_cx = 6.0, triangle1_cy = 6.0;
    // Треугольник во второй четверти
    float triangle2_ax = -6.0, triangle2_ay = 0.0;
    float triangle2_bx = 0.0, triangle2_by = 6.0;
    float triangle2_cx = 0.0, triangle2_cy = 0.0;
    // Треугольник в третьей четверти
    float triangle3_ax = -6.0, triangle3_ay = 0.0;
    float triangle3_bx = 0.0, triangle3_by = -6.0;
    float triangle3_cx = -6.0, triangle3_cy = -6.0;
    // Треугольник в четвёртой четверти
    float triangle4_ax = 6.0, triangle4_ay = 0.0;
    float triangle4_bx = 0.0, triangle4_by = -6.0;
    float triangle4_cx = 0.0, triangle4_cy = 0.0;

    // Тесты для определения принадлежности пользовательских координат к какому-либо треугольнику
    // Тест для треугольника в первой четверти
    float test_1_1 = (triangle1_bx - triangle1_ax) * (y - triangle1_ay) - (x - triangle1_ax) * (triangle1_by - triangle1_ay);
    float test_2_1 = (triangle1_cx - triangle1_bx) * (y - triangle1_by) - (x - triangle1_bx) * (triangle1_cy - triangle1_by);
    float test_3_1 = (triangle1_ax - triangle1_cx) * (y - triangle1_cy) - (x - triangle1_cx) * (triangle1_ay - triangle1_cy);
    // Тест для треугольника во второй четверти
    float test_1_2 = (triangle2_bx - triangle2_ax) * (y - triangle2_ay) - (x - triangle2_ax) * (triangle2_by - triangle2_ay);
    float test_2_2 = (triangle2_cx - triangle2_bx) * (y - triangle2_by) - (x - triangle2_bx) * (triangle2_cy - triangle2_by);
    float test_3_2 = (triangle2_ax - triangle2_cx) * (y - triangle2_cy) - (x - triangle2_cx) * (triangle2_ay - triangle2_cy);
    // Тест для треугольника в третьей четверти
    float test_1_3 = (triangle3_bx - triangle3_ax) * (y - triangle3_ay) - (x - triangle3_ax) * (triangle3_by - triangle3_ay);
    float test_2_3 = (triangle3_cx - triangle3_bx) * (y - triangle3_by) - (x - triangle3_bx) * (triangle3_cy - triangle3_by);
    float test_3_3 = (triangle3_ax - triangle3_cx) * (y - triangle3_cy) - (x - triangle3_cx) * (triangle3_ay - triangle3_cy);
    // Тест для треугольника в четвёртой четверти
    float test_1_4 = (triangle4_bx - triangle4_ax) * (y - triangle4_ay) - (x - triangle4_ax) * (triangle4_by - triangle4_ay);
    float test_2_4 = (triangle4_cx - triangle4_bx) * (y - triangle4_by) - (x - triangle4_bx) * (triangle4_cy - triangle4_by);
    float test_3_4 = (triangle4_ax - triangle4_cx) * (y - triangle4_cy) - (x - triangle4_cx) * (triangle4_ay - triangle4_cy);

    // Если пользовательская кооордината принадлежит к какому-либо треугольнику, то InsideTriangle = true, 
    // иначе оставляем переменную InsideTriangle без изменений
    if ((test_1_1 >= 0 && test_2_1 >= 0 && test_3_1 >= 0) || (test_1_1 <= 0 && test_2_1 <= 0 && test_3_1 <= 0))
    {
        isShaded = true;
    }

    else
    {
        if ((test_1_2 >= 0 && test_2_2 >= 0 && test_3_2 >= 0) || (test_1_2 <= 0 && test_2_2 <= 0 && test_3_2 <= 0))
        {
            InsideTriangleC = true;
        }

        else
        {
            if ((test_1_3 >= 0 && test_2_3 >= 0 && test_3_3 >= 0) || (test_1_3 <= 0 && test_2_3 <= 0 && test_3_3 <= 0))
            {
                isShaded = true;
            }

            else
            {
                if ((test_1_4 >= 0 && test_2_4 >= 0 && test_3_4 >= 0) || (test_1_4 <= 0 && test_2_4 <= 0 && test_3_4 <= 0))
                {
                    InsideTriangleC = true;
                }
            }
        }
    }

    // Если пользовательские точки находяться в кругу, то isInCircle = true
    if ((pow(x, 2) + pow(y, 2)) < 1)
    {
        isInCircle = true;
    }

    if ((x == 0 && (-7 < y && y < 7)) || (y == 0 && (-7 < x && x < 7)))
    {
        isShaded = true;
    }

    // Если пользовательская точка находиться в треугольнике, но не в круге или наоборот, то точка находится в закрашенной области
    if (InsideTriangleC != isInCircle)
    {
        isShaded = true;
    }

    // Если пользовательская точка находится в закрашенной области, то выводим соответствующее сообщение, иначе о нахождении в не закарашенной области
    if (isShaded) {
        cout << "Yes. This coordinates do shaded" << endl;
    }
    else {
        cout << "No. This coordinates do not shaded" << endl;
    }

    // Успешное завершение программы
    return 0;
}