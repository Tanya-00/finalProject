#include <iostream>
#include <vector>
#include <string>

using namespace std;

class confectionery {
private:
    string confectioneryName;
    string confectioneryGoods;
public:
    string setConfectioneryName(const string &confectioneryName) {
        confectionery :: confectioneryName = confectioneryName;
    }
    string setConfectioneryGoods(const string &confectioneryGoods) {
        confectionery :: confectioneryGoods = confectioneryGoods;
    }
    string getConfectioneryName() {
        return confectionery :: confectioneryName;
    }
    string getConfectioneryGoods() {
        return confectionery :: confectioneryGoods;
    }
};

class cake : public confectionery {
protected:
    string names;
    string sponge;
    string cream;
    unsigned int price;
public:
    virtual string getNames() const = 0;
    virtual string getSponge() const = 0;
    virtual string getCream() const = 0;
    virtual unsigned int getPrice() const = 0;
};

class pie : public confectionery {
protected:
    string names;
    string dough;
    string filling;
    unsigned int price;
public:
    virtual string getNames() const = 0;
    virtual string getDough() const = 0;
    virtual string getFilling() const = 0;
    virtual unsigned int getPrice() const = 0;
};

class pastry : public confectionery {
protected:
    string names;
    string base;
    string filling;
    unsigned int price;
public:
    virtual string getNames() const = 0;
    virtual string getBase() const = 0;
    virtual string getFilling() const = 0;
    virtual unsigned int getPrice() const = 0;
};

class chocolateCake : public cake {
public:
    chocolateCake() {
        this->names = "Chocolate";
        this->sponge = sponge;
        this->cream = cream;
    }

    string getNames() const override {
        return "Chocolate";
    }

    string getSponge() const override {
        return "chocolate sponge cake soaked in syrup";
    }

    string getCream() const override {
        return "cream based on natural chocolate";
    }

    unsigned int getPrice() const override {
        return 250;
    }
};

class cheesecake : public cake {
public:
    cheesecake() {
        this->names = names;
        this->sponge = sponge;
        this->cream = cream;
    }

    string getNames() const override {
        return "Cheesecake";
    }

    string getSponge() const override {
        return "the cake is based on cookies";
    }

    string getCream() const override {
        return "the cream is based on cream cheese";
    }

    unsigned int getPrice() const override {
        return 250;
    }
};

class classicCake : public cake {
public:
    classicCake() {
        this->names = names;
        this->sponge = sponge;
        this->cream = cream;
    }

    string getNames() const override {
        return "Classic cake";
    }

    string getSponge() const override {
        return "classic sponge cake";
    }

    string getCream() const override {
        return "cream with vanilla";
    }

    unsigned int getPrice() const override {
        return 300;
    }
};

class applePie : public pie {
public:
    applePie() {
        this->names = names;
        this->dough = dough;
        this->filling = filling;
    }

    string getNames() const override {
        return "Apple pie";
    }

    string getDough() const override {
        return "sweet yeast dough";
    }

    string getFilling() const override {
        return "apples sprinkled with cinnamon";
    }

    unsigned int getPrice() const override {
        return 275;
    }
};

class strawberryPie : public pie {
public:
    strawberryPie() {
        this->names = names;
        this->dough = dough;
        this->filling = filling;
    }

    string getNames() const override {
        return "Strawberry pie";
    }

    string getDough() const override {
        return "sweet shortbread dough";
    }

    string getFilling() const override {
        return "fresh strawberry";
    }

    unsigned int getPrice() const override {
        return 300;
    }
};

class fishPie : public pie {
public:
    fishPie() {
        this->names = names;
        this->dough = dough;
        this->filling = filling;
    }

    string getNames() const override {
        return "Fish pie";
    }

    string getDough() const override {
        return "yeast dough with herbs";
    }

    string getFilling() const override {
        return "salmon fillet";
    }

    unsigned int getPrice() const override {
        return 350;
    }
};

class honeyPastry : public pastry {
public:
    honeyPastry() {
        this->names = names;
        this->base = base;
        this->filling = filling;
    }

    string getNames() const override {
        return "Honey pastry";
    }

    string getBase() const override {
        return "honey cakes soaked in honey syrup";
    }

    string getFilling() const override {
        return "butter cream with honey";
    }

    unsigned int getPrice() const override {
       return 50;
    }
};

class fruitBaskets : public pastry {
public:
    fruitBaskets() {
        this->names = names;
        this->base = base;
        this->filling = filling;
    }

    string getNames() const override {
        return "Fruit basket";
    }

    string getBase() const override {
        return "basket of dough";
    }

    string getFilling() const override {
        return "the basket includes the following fruits in syrup: peaches, pears, strawberries and apples";
    }

    unsigned int getPrice() const override {
        return 55;
    }
};

class creamCone : public pastry {
public:
    creamCone() {
        this->names = names;
        this->base = base;
        this->filling = filling;
    }

    string getNames() const override {
        return "Cream cone";
    }

    string getBase() const override {
        return "puff pastry";
    }

    string getFilling() const override {
        return "custard";
    }

    unsigned int getPrice() const override {
        return 60;
    }
};

class createCake : public confectionery {
protected:
    string names;
    unsigned int price;
public:
    virtual string getNames() const = 0;
    virtual unsigned int getPrice() const = 0;
};


class decorator : public createCake {
protected:
    createCake* cakes;
public:
    decorator(createCake* cake1) {
        this->cakes = cake1;
    }
};

class simpleCake : public createCake {
public:
    simpleCake() {
        this->names = "Simple cake";
    }
    string getNames() const override {
        return "Simple cake ";
    }
    unsigned int getPrice() const override {
        return 200;
    }
};

class chocolate : public decorator {
public:
    chocolate(simpleCake *pCake) : decorator(cakes) {
        this->names = "Chocolate";
    }
    string getNames() const override {
        return this->cakes->getNames() + "with the addition of chocolate";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 60;
    }
    /*void print() {
        cout << names << ", " << price << " ";
    }*/
};

class candiedFruit : public decorator {
public:
    candiedFruit(simpleCake *pCake) : decorator(cakes) {
            this->names = "Candied fruit";
    }
    string getNames() const override {
        return this->cakes->getNames() + "with the addition of candied fruit";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 70;
    }
};

class nutlets : public decorator {
public:
    nutlets(simpleCake *pCake) : decorator(cakes) {
            this->names = "Nutlets";
    }
    string getNames() const override {
        return this->cakes->getNames() + "with the addition of nutlets";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 65;
    }
};

class vanilla : public decorator {
public:
    vanilla(simpleCake *pCake) : decorator(cakes) {
            this->names = "Vanilla";
    }
    string getNames() const override {
        return this->cakes->getNames() + "with the addition of vanilla";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 45;
    }
};

class strawberryCream : public decorator {
public:
    strawberryCream(simpleCake *cCake) : decorator(cakes) {
            this->names = "Strawberry cream";
    }
    string getNames() const override {
        return this->cakes->getNames() + "with strawberry cream";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 70;
    }
};

class chocolateCream : public decorator {
public:
    chocolateCream(simpleCake *cCake) : decorator(cakes) {
            this->names = "Chocolate cream";
    }
    string getNames() const override {
        return this->cakes->getNames() + "with chocolate cream";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 65;
    }
};

class vanillaCream : public decorator {
public:
    vanillaCream(simpleCake *cCake) : decorator(cakes) {
            this->names = "Vanilla cream";
    }
    string getNames() const override {
        return this->cakes->getNames() + "with vanilla cream";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 50;
    }
};

class cottageCheeseCream : public decorator {
public:
    cottageCheeseCream(simpleCake *cCake) : decorator(cakes) {
            this->names = "Cottage cheese cream";
    }
    string getNames() const override {
        return this->cakes->getNames() + "with cottage cheese cream";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 80;
    }
};

class decorateSprinkle : public decorator {
public:
    decorateSprinkle(simpleCake *dCake) : decorator(cakes) {
            this->names = "Decorate sprinkle";
    }
    string getNames() const override {
        return this->cakes->getNames() + "sprinkle decoration";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 60;
    }
};

class decorationWithCreamFlowers : public decorator {
public:
    decorationWithCreamFlowers(simpleCake *dCake) : decorator(cakes) {
            this->names = "Decoration with cream flowers";
    }
    string getNames() const override {
        return this->cakes->getNames() + "decoration with cream flowers";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 80;
    }
};

class decorationChocolate : public decorator {
public:
    decorationChocolate(simpleCake *dCake) : decorator(cakes) {
            this->names = "Decoration chocolate";
    }
    string getNames() const override {
        return this->cakes->getNames() + "decoration with chocolate";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 70;
    }
};

class decorationMarmalade : public decorator {
public:
    decorationMarmalade(simpleCake *dCake) : decorator(cakes) {
            this->names = "Decoration marmalade";
    }
    string getNames() const override {
        return this->cakes->getNames() + "decoration with marmalade";
    }
    unsigned int getPrice() const override {
        return this->getPrice() + 70;
    }
};


class Order {
private:
    vector<const cake*> orderCake;
    vector<const pie*> orderPie;
    vector<const pastry*> orderPastry;
    vector<const createCake*> orderCreateCake;

public:
    void addCake(const cake* cake1) {
        orderCake.push_back(cake1);
    }
    void addPie(const pie* pie1) {
        orderPie.push_back(pie1);
    }
    void addPastry(const pastry* pastry1) {
        orderPastry.push_back(pastry1);
    }
    void addCreateCake(const createCake* cake2) {
        orderCreateCake.push_back(cake2);
    }

    /*void printOrderCreateCake() {
        unsigned int finalPrice = 0;
        int orderCreateCake = orderCreateCake.size();
    }*/

    void printOrderCake() {
        unsigned int finalPrice = 0;
        int orderCakes = orderCake.size();
        for(int i = 0; i <orderCake.size(); i++) {
            cout << i + 1 << ". " <<
                orderCake[i]->getNames() << ", " <<
                orderCake[i]->getSponge() << ", " <<
                orderCake[i]->getCream()  << ". Price for cake - " <<
                orderCake[i]->getPrice() << endl;
            finalPrice = finalPrice + orderCake[i]->getPrice();
        }
        cout << "Final price for cake " << finalPrice << endl;
    }

    void printOrderPie() {
        unsigned int finalPrice = 0;
        int orderPies = orderPie.size();
        for(int i = 0; i <orderPie.size(); i++) {
            cout << i + 1 << ". " <<
                 orderPie[i]->getNames() << ", " <<
                 orderPie[i]->getDough() << ", " <<
                 orderPie[i]->getFilling() << ". Price for pie - " <<
                 orderPie[i]->getPrice() << endl;
            finalPrice = finalPrice + orderCake[i]->getPrice();
        }
        cout << "Final price for pie " << finalPrice << endl;
    }

    void printOrderPastry() {
        unsigned int finalPrice = 0;
        int orderPastrys = orderPastry.size();
        for(int i = 0; i <orderPastry.size(); i++) {
            cout << i + 1 << ". " <<
                 orderPastry[i]->getNames() << ", " <<
                 orderPastry[i]->getBase() << ", " <<
                 orderPastry[i]->getFilling() << ". Price for cake - " <<
                 orderPastry[i]->getPrice() << endl;
            finalPrice = finalPrice + orderPastry[i]->getPrice();
        }
        cout << "Final price for pastry " << finalPrice << endl;
    }
};



int main() {
    cout << "Menu:" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Cakes in the range:" << endl;
    cout << "1. Chocolate cake" << endl;
    cout << "2. Cheesecake" << endl;
    cout << "3. Classic cake" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Pies in assortment:" << endl;
    cout << "4. Apple pie" << endl;
    cout << "5. Strawberry pie" << endl;
    cout << "6. Fish pie" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Confectionery products in assortment:" << endl;
    cout << "7. Honey pastry" << endl;
    cout << "8. Fruit basket" << endl;
    cout << "9. Cream cone" << endl;
    cout << "10. If you want create your cake";

    Order order;

    cout << "Enter the number of your choice" << endl;
    int choice = 0;
    cin >> choice;

    switch (choice) {
        case 1: {
            order.addCake(new chocolateCake());
            order.printOrderCake();
        }
            break;
        case 2: {
            order.addCake(new cheesecake());
            order.printOrderCake();
        }
            break;
        case 3: {
            order.addCake(new classicCake());
            order.printOrderCake();
        }
            break;
        case 4: {
            order.addPie(new applePie());
            order.printOrderPie();
        }
            break;
        case 5: {
            order.addPie(new strawberryPie());
            order.printOrderPie();
        }
            break;
        case 6: {
            order.addPie((new fishPie()));
            order.printOrderPie();
        }
            break;
        case 7: {
            order.addPastry(new honeyPastry());
            order.printOrderPastry();
        }
            break;
        case 8: {
            order.addPastry(new fruitBaskets());
            order.printOrderPastry();
        }
            break;
        case 9: {
            order.addPastry(new creamCone());
            order.printOrderPastry();
        }
            break;
        case 10: {
            unsigned int base;
            cake *newCake;
            cout << "Choose the cake base:" << endl;
            cout << "1. Chocolate sponge with strawberry cream" << endl;
            cout << "2. Caramel" << endl;
            cout << "3. Candied fruit" << endl;
            cout << "4. Nutlets" << endl;
            cout << "5. Vanilla" << endl;

            cin >> base;
            switch (base) {
                case 1: {
                    order.addCreateCake(new strawberryCream(
                            reinterpret_cast<simpleCake *>(new chocolate(new simpleCake()))));
                }
                    break;
                case 2: {
                    order.addCreateCake(new candiedFruit(new simpleCake()));
                }
                    break;
                case 3: {
                    order.addCreateCake(new nutlets(new simpleCake()));
                }
                    break;
                case 4: {
                    order.addCreateCake(new vanilla(new simpleCake()));
                }
                    break;
            }
        }
    }

    return 0;
}