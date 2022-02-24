#include <iostream>
#include <vector>

class Polynom{
private:
    std::vector<int> odds;
public:
    Polynom (std::vector<int> odds_){
        for (int i = 0; i < odds_.size(); i++){
            odds.push_back(odds_[i]);
        }
    }
    Polynom (const Polynom &polynom_){
        for (int i = 0; i < polynom_.odds.size(); i++){
            odds.push_back(polynom_.odds[i]);
        }
    }
    Polynom operator=(const Polynom &polynom_){
        if (odds.size() == 0){
            for (int i = 0; i < polynom_.odds.size(); i++){
                odds.push_back(polynom_.odds[i]);
            }
        }
        else{
            odds.clear();
            for (int i = 0; i < polynom_.odds.size(); i++){
                odds.push_back(polynom_.odds[i]);
            }
        }
        return *this;
    }
    bool operator==(const Polynom &polynom_){
        bool isEqual = true;
        if (odds.size() != polynom_.odds.size()){
            isEqual = false;
        }
        else{
            for (int i = 0; i < odds.size(); i++){
                if (odds[i] != polynom_.odds[i]){
                    isEqual = false;
                }
            }
        }
        return isEqual;
    }
    bool operator!=(const Polynom &polynom_){
        bool isEqual = true;
        if (odds.size() != polynom_.odds.size()){
            isEqual = false;
        }
        else{
            for (int i = 0; i < odds.size(); i++){
                if (odds[i] != polynom_.odds[i]){
                    isEqual = false;
                }
            }
        }
        return !isEqual;
    }
    Polynom operator+(Polynom polynom_){
        if (polynom_.odds.size() > odds.size()){
            for (int i = 0; i < odds.size(); i++){
                polynom_.odds[i] += odds[i];
            }
        }
        else{
            for (int i = polynom_.odds.size(); i < odds.size(); i++){
                polynom_.odds.push_back(0);
            }
            for (int i = 0; i < odds.size(); i++){
                int help = polynom_.odds[i];
                polynom_.odds[i] = odds[i] + help;
            }
        }
        return polynom_;
    }
    Polynom operator+=(const Polynom &polynom_){
        if (odds.size() > polynom_.odds.size()){
            for (int i = 0; i < polynom_.odds.size(); i++){
                odds[i] += polynom_.odds[i];
            }
        }
        else{
            for (int i = odds.size(); i < polynom_.odds.size(); i++){
                odds.push_back(0);
            }
            for (int i = 0; i < polynom_.odds.size(); i++){
                int help = odds[i];
                odds[i] = polynom_.odds[i] + help;
            }
        }
        return *this;
    }
    Polynom operator-(const Polynom &polynom_){
        std::vector<int> h_odds;
        for (int i = 0; i < odds.size(); i++){
            h_odds.push_back(odds[i]);
        }

        if (odds.size() > polynom_.odds.size()){
            for (int i = 0; i < polynom_.odds.size(); i++){
                h_odds[i] -= polynom_.odds[i];
            }
        }
        else{
            for (int i = odds.size(); i < polynom_.odds.size(); i++){
                h_odds.push_back(0);
            }
            for (int i = 0; i < polynom_.odds.size(); i++){
                h_odds[i] -= polynom_.odds[i];
            }
        }
        Polynom h_poly(h_odds);
        return h_poly;
    }
    Polynom &operator-(){
        for (int i = 0; i < odds.size(); i++){
            odds[i] = -odds[i];
        }
        return *this;
    }
    Polynom operator-=(const Polynom &polynom_){
        if (odds.size() > polynom_.odds.size()){
            for (int i = 0; i < polynom_.odds.size(); i++){
                odds[i] -= polynom_.odds[i];
            }
        }
        else{
            for (int i = odds.size(); i < polynom_.odds.size(); i++){
                odds.push_back(0);
            }
            for (int i = 0; i < polynom_.odds.size(); i++){
                odds[i] -= polynom_.odds[i];
            }
        }
        return *this;
    }
    Polynom operator*(const Polynom& polynom_){
        std::vector<int> h_odds(polynom_.odds.size() + odds.size());
        for (int i = 0; i < polynom_.odds.size(); i++){
            for (int j = 0; j < odds.size(); j++){
                h_odds[i+j] += polynom_.odds[i] * odds[j];
            }
        }
        Polynom h_poly(h_odds);
        return h_poly;
    }
    Polynom operator/(int value){
        if (value == 0){
            std::cout << "Error /0!" << std::endl;
        }
        else{
            for (int i = 0; i < odds.size(); i++){
                odds[i] /= value;
            }
        }
        return *this;
    }
    Polynom operator*=(const Polynom& polynom_){
        std::vector<int> h_odds(polynom_.odds.size() + odds.size());
        for (int i = 0; i < polynom_.odds.size(); i++){
            for (int j = 0; j < odds.size(); j++){
                h_odds[i+j] += polynom_.odds[i] * odds[j];
            }
        }
        odds.clear();
        for (int i = 0; i < h_odds.size(); i++){
            odds.push_back(h_odds[i]);
        }
        return *this;
    }
    Polynom operator/=(int value){
        if (value == 0){
            std::cout << "Error /0!" << std::endl;
        }
        else{
            for (int i = 0; i < odds.size(); i++){
                odds[i] /= value;
            }
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream &os, const Polynom polynom_);

    Polynom operator[](int value){
        std::cout << "Coeff " << value << " is " << odds[value - 1] << std::endl;
    }
    ~Polynom(){};
};

std::ostream& operator<<(std::ostream &os, const Polynom polynom_){
    for (int i = polynom_.odds.size() - 1; i > -1; i--){
        if (polynom_.odds[i] != 0){
            os << polynom_.odds[i] << "x^" << i << " ";
        }
    }
    return os;
}

std::istream& operator>>(std::istream &in, Polynom &polynom_){
    int power_;
    int current;
    std::vector<int> odds_;
    in >> power_;
    for (int i = 0; i < power_ + 1; i++){
        in >> current;
        odds_.push_back(current);
    }
    polynom_ = Polynom(odds_);
    return in;
}

int main(int argc, const char* argv[]){
    std::vector<int> coeff = {1, 1};
    std::vector<int> coeff1 = {-3, 1};
    Polynom poly(coeff);
    Polynom poly_1(coeff1);
    poly *= poly_1;
    poly *= poly;
    std::cout << poly;
    return 0;
}
