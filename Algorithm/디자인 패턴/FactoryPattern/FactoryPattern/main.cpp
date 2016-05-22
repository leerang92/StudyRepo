#include "PizzaStore.h"
#include "NYPizzaStore.h"
#include "Pizza.h"
#include "CKPizzaStore.h"
#include "CKStyleCheesePizza.h"

void main() {
	CPizzaStore *nyStore = new CNYPizzaStore();
	CPizzaStore *ckStore = new CCKPizzaStore();
	
	CPizza *pizza = nyStore->orderPizza("cheese");
	cout << "Hong ordered a " << pizza->getName() << endl;

	cout << endl;

	CPizza *pizza2 = ckStore->orderPizza("cheese");
	cout << "Lee ordered a " << pizza2->getName() << endl;
}