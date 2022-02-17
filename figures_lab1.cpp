#include <iostream>
#include <cmath>

class Point{
protected:
    int x;
    int y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(int x_, int y_){
        x = x_;
        y = y_;
    }
    Point(const Point &point){
        x = point.x;
        y = point.y;
    }
    Point operator=(const Point point){
        x = point.x;
        y = point.y;
        return *this;
    }
    int GetX(){
        return x;
    }
    int GetY(){
        return y;
    }
    ~Point(){}
};

class Lline : public Point{
private:
    int number;
    Point dots[20];
public:
    Lline(){
        number = 0;
    }
    Lline(const Lline &line_){
        number = line_.number;
        for (int i = 0; i < number; i++){
            dots[i] = line_.dots[i];
        }
    }
    Lline operator=(const Lline line_){
        number = line_.number;
        for (int i = 0; i < number; i++){
            dots[i] = line_.dots[i];
        }
        return *this;
    }
    void AddPoint(int _x, int _y){
        Point cur(_x, _y);
        dots[number] = cur;
        number++;
    }
    void Getl(){
        for (int i = 0; i < number; i++){
            std::cout << dots[i].GetX() << " " << dots[i].GetY() << std::endl;
        }
        std::cout << std::endl;
    }
    void Perimetr(){
        float result = 0;
        for (int i = 1; i < number; i++){
            float dx = pow(dots[i].GetX() - dots[i-1].GetX(), 2);
            float dy = pow(dots[i].GetY() - dots[i-1].GetY(), 2);
            result += sqrt(dx + dy);
        }
        std::cout << result << std::endl;
    }
    ~Lline(){};
};

class ZLline : public Point{
private:
    int number;
    Point dots[20];
public:
    ZLline(){
        number = 0;
    }
    ZLline(const ZLline &line_){
        number = line_.number;
        for (int i = 0; i < number; i++){
            dots[i] = line_.dots[i];
        }
    }
    ZLline operator=(const ZLline line_){
        number = line_.number;
        for (int i = 0; i < number; i++){
            dots[i] = line_.dots[i];
        }
        return *this;
    }
    void AddPoint(int _x, int _y){
        Point cur(_x, _y);
        dots[number] = cur;
        number++;
    }
    void Getl(){
        for (int i = 0; i < number; i++){
            std::cout << dots[i].GetX() << " " << dots[i].GetY() << std::endl;
        }
        std::cout << std::endl;
    }
    void Perimetr(){
        float result = 0, dx, dy;
        for (int i = 1; i < number; i++){
            dx = pow(dots[i].GetX() - dots[i-1].GetX(), 2);
            dy = pow(dots[i].GetY() - dots[i-1].GetY(), 2);
            result += sqrt(dx + dy);
        }
        dx = pow(dots[0].GetX() - dots[number-1].GetX(), 2);
        dy = pow(dots[0].GetY() - dots[number-1].GetY(), 2);
        result += sqrt(dx + dy);
        std::cout << result << std::endl;
    }
    ~ZLline(){};
};

class Triangle : public Point{
private:
    Point dots[3];
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
        Point cur1(x1, y1);
        Point cur2(x2, y2);
        Point cur3(x3, y3);
        dots[0] = cur1;
        dots[1] = cur2;
        dots[2] = cur3;
    }
    Triangle(const Triangle &triangle_){
        for (int i = 0; i < 3; i++){
            dots[i] = triangle_.dots[i];
        }
    }
    Triangle operator=(const Triangle triangle_){
        for (int i = 0; i < 3; i++){
            dots[i] = triangle_.dots[i];
        }
        return *this;
    }
    float TPerimetr(){
        float result, dx, dy;
        for (int i = 1; i < 3; i++){
            dx = pow(dots[i].GetX() - dots[i-1].GetX(), 2);
            dy = pow(dots[i].GetY() - dots[i-1].GetY(), 2);
            result += sqrt(dx + dy);
        }
        dx = pow(dots[0].GetX() - dots[2].GetX(), 2);
        dy = pow(dots[0].GetY() - dots[2].GetY(), 2);
        result += sqrt(dx + dy);
        return result;
    }
    float TSquare(){
        float half_preimetr, a, b, c;
        a = sqrt(pow(dots[1].GetX() - dots[0].GetX(), 2) + pow(dots[1].GetY() - dots[0].GetY(), 2));
        b = sqrt(pow(dots[2].GetX() - dots[1].GetX(), 2) + pow(dots[2].GetY() - dots[1].GetY(), 2));
        c = sqrt(pow(dots[0].GetX() - dots[2].GetX(), 2) + pow(dots[0].GetY() - dots[2].GetY(), 2));
        half_preimetr = (a+b+c)/2;
        return sqrt(half_preimetr*(half_preimetr - a)*(half_preimetr - b)*(half_preimetr - c));
    }
    void GetT(){
        for (int i = 0; i < 3; i++){
            std::cout << dots[i].GetX() << " " << dots[i].GetY() << std::endl;
        }
        std::cout << std::endl;
    }
    ~Triangle(){};
};

class Trapezoid : public Point{
private:
    Point dots[4];
public:
    Trapezoid (int x1, int y1, int x2, int y2, int l_a, int l_b){
        Point cur1(x1, y1);
        Point cur2(x2, y2);
        dots[0] = cur1;
        dots[1] = cur2;
        Point cur3(x1 + l_a, y1);
        Point cur4(x2 + l_b, y2);
        dots[2] = cur3;
        dots[3] = cur4;
    }
    Trapezoid (const Trapezoid &trapezoid_){
        for (int i = 0; i < 4; i++){
            dots[i] = trapezoid_.dots[i];
        }
    }
    Trapezoid operator=(const Trapezoid trapezoid_){
        for (int i = 0; i < 4; i++){
            dots[i] = trapezoid_.dots[i];
        }
        return *this;
    }
    float TRPerimetr(){
        float result, a, b;
        a = sqrt(pow(dots[1].GetX() - dots[0].GetX(), 2) + pow(dots[1].GetY() - dots[0].GetY(), 2));
        b = sqrt(pow(dots[2].GetX() - dots[3].GetX(), 2) + pow(dots[2].GetY() - dots[3].GetY(), 2));
        return a + b + dots[2].GetX() - dots[0].GetX() + dots[3].GetX() - dots[1].GetX();
    }
    float TRSquare(){
        float h, a, b;
        h = abs(dots[0].GetY() - dots[1].GetY());
        a = dots[2].GetX() - dots[0].GetX();
        b = dots[3].GetX() - dots[1].GetX();
        return (a + b) * h / 2;
    }
    ~Trapezoid(){};
};

class Polygon : public Point{
private:
    Point dots[20];
    int number;
public:
    Polygon (){
        number = 0;
    }
    Polygon (const Polygon &polygon_){
        number = polygon_.number;
        for (int i = 0; i < number; i++){
            dots[i] = polygon_.dots[i];
        }
    }
    Polygon operator=(const Polygon polygon_){
        number = polygon_.number;
        for (int i = 0; i < number; i++){
            dots[i] = polygon_.dots[i];
        }
        return *this;
    }
    void AddPPoint(int x_, int y_){
        Point cur(x_, y_);
        dots[number] = cur;
        number++;
    }
    float PPerimetr(){
        float result = 0, dx, dy;
        for (int i = 1; i < number; i++){
            dx = pow(dots[i].GetX() - dots[i-1].GetX(), 2);
            dy = pow(dots[i].GetY() - dots[i-1].GetY(), 2);
            result += sqrt(dx + dy);
        }
        dx = pow(dots[0].GetX() - dots[number-1].GetX(), 2);
        dy = pow(dots[0].GetY() - dots[number-1].GetY(), 2);
        result += sqrt(dx + dy);
        return result;
    }
    float PSquare(){
        float result = 0;
        for (int i = 0; i < number - 1; i++){
            result += dots[i].GetX() * dots[i+1].GetY() - dots[i].GetY() * dots[i+1].GetX();
        }
        result += dots[number-1].GetX() * dots[0].GetY() - dots[number-1].GetY() * dots[0].GetX();
        return abs(result/2);
    }
    ~Polygon (){};
};

class RPolygon : public Point{
private:
    Point centre;
    int peaks_number;
    int side_length;
public:
    RPolygon (int x_, int y_, int p_number, int s_length){
        Point cur(x_, y_);
        centre = cur;
        peaks_number = p_number;
        side_length = s_length;
    }
    RPolygon (const RPolygon &rpolygon){
        centre = rpolygon.centre;
        peaks_number = rpolygon.peaks_number;
        side_length = rpolygon.side_length;
    }
    RPolygon operator=(const RPolygon rpolygon){
        centre = rpolygon.centre;
        peaks_number = rpolygon.peaks_number;
        side_length = rpolygon.side_length;
        return *this;
    }
    float RPPerimetr(){
        return peaks_number * side_length;
    }
    float RPSquare(){
        return side_length / (2 * sin(3.14 / peaks_number)) * cos(3.14 / peaks_number) * peaks_number * side_length / 2;
    }
    ~RPolygon(){};
};

int main(int argc, char* argv[]){
    Point my_point(2, 2);
    Point zdraste(my_point);
    std::cout << my_point.GetX() << " " << my_point.GetY() << std::endl;
    std::cout << zdraste.GetX() << " " << zdraste.GetY() << std::endl;
    Lline first;
    ZLline first_;
    first.AddPoint(1, 2);
    first.AddPoint(3, 3);
    first.AddPoint(10, 9);

    first_.AddPoint(1, 2);
    first_.AddPoint(3, 3);
    first_.AddPoint(10, 9);
    first.Getl();
    first.Perimetr();
    first_.Perimetr();
    Lline second = first;
    second.Getl();
    std::cout << "\n";
    Triangle my_first_triangle(1, 1, 10, 10, 11, 1);
    Triangle my_second_triangle = my_first_triangle;
    std::cout << my_first_triangle.TPerimetr() << std::endl;
    my_first_triangle.GetT();
    std::cout << my_first_triangle.TSquare() << std::endl;
    Trapezoid my_first_trapezoid(4, 6, 1, 1, 4, 10);
    Trapezoid my_second_trapezoid = my_first_trapezoid;
    std::cout << my_first_trapezoid.TRPerimetr() << std::endl;
    std::cout << my_first_trapezoid.TRSquare() << std::endl;
    Polygon my_first_polygon;
    my_first_polygon.AddPPoint(1, 1);
    my_first_polygon.AddPPoint(6, 1);
    my_first_polygon.AddPPoint(6, 6);
    my_first_polygon.AddPPoint(1, 6);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << my_first_polygon.PSquare() << std::endl;
    std::cout << my_first_polygon.PPerimetr() << std::endl;
    std::cout << std::endl;
    RPolygon my_first_rpolygon(5, 5, 4, 6);
    std::cout << my_first_rpolygon.RPPerimetr() << std::endl;
    std::cout << my_first_rpolygon.RPSquare() << std::endl;
}
