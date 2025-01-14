#include "komponente.h"
 
class Komponente {
    private:
        double x, y;

    public:
        Komponente(double xPos = 0.0, double yPos = 0.0) : x(xPos) , y(yPos) {}

        double getX() { return x;}
        double getY() { return y;}

        void output(std::ostream& os) {
            os << "(" << x << "," << y <<")";
        }

        virtual ~Komponente() {}
        
};