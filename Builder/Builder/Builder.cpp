#include <iostream>
#include <memory>

using namespace std;

class PizzaProduct {
private:
	string m_dough;
	string m_sauce;
	string m_topping;
public:
	void setSauce(const string souce) {
		m_sauce = souce;
	}
	void setDough(const string dough) {
		m_dough = dough;
	}
	void setTopping(const string topping){
		m_topping = topping;
	}
	void taste() {
		cout << " Souce :" << m_sauce << " Dough :" << m_dough << " Topping :" << m_topping << endl;
	}
};

class Pizza_Builder {
protected:
	unique_ptr<PizzaProduct > m_product; //this should be protected
public:
	void CreateProduct() {
		m_product = make_unique<PizzaProduct >();
	}
	virtual void buildSauce() = 0;
	virtual void buildDough() = 0;
	virtual void buildTopping() = 0;
	PizzaProduct* getPizza() {
		return m_product.release();
	}
};

class Margherita_ConcreteBuilder : public Pizza_Builder
{
public:
	virtual ~Margherita_ConcreteBuilder() {};

	virtual void buildDough() override {
		m_product->setDough(" cross ");
	}
	virtual void buildSauce() override {
		m_product->setSauce(" tomato ");
	}
	virtual void buildTopping() override	{
		m_product->setTopping(" mozzarela+basil ");
	}
};

class Spicy_ConcreteBuilder : public Pizza_Builder
{
public:
	virtual ~Spicy_ConcreteBuilder() {};

	virtual void buildDough() override {
		m_product->setDough(" pan baked ");
	}
	virtual void buildSauce() override {
		m_product->setSauce(" tomato+chilli ");
	}
	virtual void buildTopping() override {
		m_product->setTopping(" pepperoni+salami ");
	}
};

//This is Director
class Cook_Director
{
public:
	void tastePizza()
	{
		m_pizzaBuilder->getPizza()->taste();
	}
	void makePizza(Pizza_Builder* pb)
	{
		m_pizzaBuilder = pb;
		m_pizzaBuilder->CreateProduct(); //Creating product
		m_pizzaBuilder->buildDough();
		m_pizzaBuilder->buildSauce();
		m_pizzaBuilder->buildTopping();
	}
private:
	Pizza_Builder* m_pizzaBuilder;
};

int main()
{
	Cook_Director 				cook;             //director
	Margherita_ConcreteBuilder 	margheritaBuilder; //concreate class
	Spicy_ConcreteBuilder    	spicyPizzaBuilder; //concreate class

	cook.makePizza(&margheritaBuilder);
	cook.tastePizza();

	cook.makePizza(&spicyPizzaBuilder);
	cook.tastePizza();

	return 0;
}