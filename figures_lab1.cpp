#include <iostream>
#include <cmath>
#include <vector>

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
    std::vector<Point> dots;
public:
    Lline(){
        number = 0;
    }
    Lline(const Lline &line_){
        number = line_.number;
        for (int i = 0; i < number; i++){
            dots.push_back(line_.dots[i]);
        }
    }
    Lline operator=(const Lline line_){
        if (number > 0){
            dots.clear();
        }
        number = line_.number;
        for (int i = 0; i < number; i++){
            dots.push_back(line_.dots[i]);
        }
        return *this;
    }
    Lline (std::vector<int> dots_){
        if (dots_.size() % 2 != 0){
            std::cout << "ERROR\n";
        }
        else{
            int i = 0;
            while (i < dots_.size()){
                Point cur(dots_[i], dots_[i+1]);
                dots.push_back(cur);
                i = i + 2;
            }
            number = dots.size();
        }
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
    std::vector<Point> dots;
public:
    ZLline(){
        number = 0;
    }
    ZLline(const ZLline &line_){
        number = line_.number;
        for (int i = 0; i < number; i++){
            dots.push_back(line_.dots[i]);
        }
    }
    ZLline operator=(const ZLline line_){
        if (number > 0){
            dots.clear();
        }
        number = line_.number;
        for (int i = 0; i < number; i++){
            dots.push_back(line_.dots[i]);
        }
        return *this;
    }
    ZLline (std::vector<int> dots_){
        if (dots_.size() % 2 != 0){
            std::cout << "ERROR\n";
        }
        else{
            int i = 0;
            while (i < dots_.size()){
                Point cur(dots_[i], dots_[i+1]);
                dots.push_back(cur);
                i = i + 2;
            }
            number = dots.size();
        }
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
        float k = (y1 - y2) / (x1 - x2);
        float b = y1 - k * x1;
        if (y3 - k * x3 + b > 1){
            Point cur1(x1, y1);
            Point cur2(x2, y2);
            Point cur3(x3, y3);
            dots[0] = cur1;
            dots[1] = cur2;
            dots[2] = cur3;
        }
        else{
            std::cout << "ERROR\n";
        }
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
    std::vector<Point> dots;
    int number;
public:
    Polygon (){
        number = 0;
    }
    Polygon (const Polygon &polygon_){
        number = polygon_.number;
        for (int i = 0; i < number; i++){
            dots.push_back(polygon_.dots[i]);
        }
    }
    Polygon operator=(const Polygon polygon_){
        if (number > 0){
            dots.clear();
        }
        number = polygon_.number;
        for (int i = 0; i < number; i++){
            dots.push_back(polygon_.dots[i]);
        }
        return *this;
    }
    Polygon (std::vector<int> dots_){
        if (dots_.size() % 2 != 0){
            std::cout << "ERROR\n";
        }
        else{
            int i = 0;
            while (i < dots_.size()){
                Point cur(dots_[i], dots_[i+1]);
                dots.push_back(cur);
                i = i + 2;
            }
            number = dots.size();
        }
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

}
