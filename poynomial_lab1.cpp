#include <iostream>

class Polynom{
private:
    int odds[10];
    int power;
public:
    Polynom (int odds_[], int power_){
        power = power_ + 1;
        for (int i = 0; i < power; i++){
            odds[i] = odds_[i];
        }
    }
    Polynom (const Polynom &polynom_){
        power = polynom_.power;
        for (int i = 0; i < power; i++){
            odds[i] = polynom_.odds[i];
        }
    }
    Polynom operator=(const Polynom &polynom_){
        power = polynom_.power;
        for (int i = 0; i < power; i++){
            odds[i] = polynom_.odds[i];
        }
        return *this;
    }
    Polynom operator==(const Polynom &polynom_){
        bool isEqual = true;;
        if (power != polynom_.power){
            isEqual = false;
        }
        else{
            for (int i = 0; i < power; i++){
                if (odds[i] != polynom_.odds[i]){
                    isEqual = false;
                }
            }
        }
        if (isEqual){
            std::cout << "YES" << std::endl;
        }
        else{
            std::cout << "NO" << std::endl;
        }
    }
    Polynom operator!=(const Polynom &polynom_){
        bool isNotEqual = false;;
        if (power != polynom_.power){
            isNotEqual = true;
        }
        else{
            for (int i = 0; i < power; i++){
                if (odds[i] != polynom_.odds[i]){
                    isNotEqual = true;
                }
            }
        }
        if (isNotEqual){
            std::cout << "YES" << std::endl;
        }
        else{
            std::cout << "NO" << std::endl;
        }
    }
    Polynom operator+(Polynom polynom_){
        if (polynom_.power > power){
            for (int i = 0; i < power; i++){
                polynom_.odds[i] += odds[i];
            }
        }
        else{
            for (int i = 0; i < power; i++){
                int help = polynom_.odds[i];
                polynom_.odds[i] = odds[i] + help;
            }
            polynom_.power = power;
        }
        return polynom_;
    }
    Polynom operator+=(const Polynom &polynom_){
        if (power > polynom_.power){
            for (int i = 0; i < polynom_.power; i++){
                odds[i] += polynom_.odds[i];
            }
        }
        else{
            for (int i = 0; i < polynom_.power; i++){
                int help = odds[i];
                odds[i] = polynom_.odds[i] + help;
            }
            power = polynom_.power;
        }
        return *this;
    }
    Polynom operator-(const Polynom &polynom_){
        int h_odds[10];
        int h_power = power;
        for (int i = 0; i < h_power; i++){
            h_odds[i] = odds[i];
        }

        if (h_power > polynom_.power){
            for (int i = 0; i < polynom_.power; i++){
                h_odds[i] -= polynom_.odds[i];
            }
        }
        else{
            for (int i = h_power; i < polynom_.power; i++){
                h_odds[i] = 0;
            }
            for (int i = 0; i < polynom_.power; i++){
                h_odds[i] -= polynom_.odds[i];
            }
            h_power = polynom_.power;
        }
        Polynom h_poly(h_odds, h_power-1);
        return h_poly;
    }
    Polynom operator-(){
        for (int i = 0; i < power; i++){
            odds[i] = -odds[i];
        }
        return *this;
    }
    Polynom operator-=(const Polynom &polynom_){
        if (power > polynom_.power){
            for (int i = 0; i < polynom_.power; i++){
                odds[i] -= polynom_.odds[i];
            }
        }
        else{
            for (int i = power; i < polynom_.power; i++){
                odds[i] = 0;
            }
            for (int i = 0; i < polynom_.power; i++){
                odds[i] -= polynom_.odds[i];
            }
            power = polynom_.power;
        }
        return *this;
    }
    Polynom operator*(int value){
        for (int i = 0; i < power; i++){
            odds[i] *= value;
        }
        return *this;
    }
    Polynom operator/(int value){
        if (value == 0){
            std::cout << "Error /0!" << std::endl;
        }
        else{
            for (int i = 0; i < power; i++){
                odds[i] /= value;
            }
        }
        return *this;
    }
    Polynom operator*=(int value){
        for (int i = 0; i < power; i++){
            odds[i] *= value;
        }
        return *this;
    }
    Polynom operator/=(int value){
        if (value == 0){
            std::cout << "Error /0!" << std::endl;
        }
        else{
            for (int i = 0; i < power; i++){
                odds[i] /= value;
            }
        }
        return *this;
    }
    Polynom operator>> (int value){
        for (int i = 0; i < power; i++){
            odds[i] >>= value;
        }
        return *this;
    }
    Polynom operator<< (int value){
        for (int i = 0; i < power; i++){
            odds[i] <<= value;
        }
        return *this;
    }
    Polynom operator[](int value){
        std::cout << "Coeff " << value << " is " << odds[value - 1] << std::endl;
    }
    void Show(){
        for (int i = power - 1; i > -1; i--){
            if (odds[i] != 0){

                std::cout << odds[i] << "x^" << i << " ";
            }
        }
        std::cout << std::endl;
    }
    ~Polynom(){};
};

int main(){
    int coeff[5] = {3, 4, 7, 6, 8};
    int coeff1[3] = {2, 9, 4};
    int p1 = 2;
    int p = 4;
    Polynom poly_1(coeff, p);
    Polynom poly_2(coeff1, p1);
    Polynom poly_3 = poly_2 - poly_1;
    poly_1.Show();
    poly_2.Show();
    poly_3.Show();
    Polynom poly_4(poly_1);
    poly_4 += poly_2;
    poly_4.Show();
    Polynom poly_5 = poly_2;
    poly_5 -= poly_3;
    poly_5.Show();
    Polynom poly_6(poly_1);
    poly_6 = poly_6 << 2;
    poly_6.Show();
    Polynom poly_7 = - poly_1;
    poly_7.Show();
    return 0;
}