#include "InventoryItem.h"

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

InventoryItem::InventoryItem(int sku, string desc, double money, string uom,double lead, int quant = 0){

	SKU = sku;
	Description = desc;
	Price = money;
	UOM = uom;
	QuantityOnHand = quant;
	LeadTime = lead;

}
InventoryItem::~InventoryItem(){}
string InventoryItem::GetPartInfo() {
	string returnstring = "SKU: " + to_string(SKU) + "\n Description : "+ Description;
	return returnstring;
}
double InventoryItem::GetPrice() { return Price; }
int	InventoryItem::GetSKU() { return SKU; }
bool InventoryItem::InStock() { return (QuantityOnHand>0); }
bool InventoryItem::Available(int dat) { 
	// Get the current time point
	//auto now = std::chrono::system_clock::now();

	// Convert the time point to a time_t object
	//std::time_t time = std::chrono::system_clock::to_time_t(now);

	// Convert the time_t object to a string in the format "YYYY-MM-DD"
	//char date[11];
	//std::strftime(date, sizeof(date), "%Y-%m-%d", std::localtime(&time));
	//TO DO:  MAKE LEAD TIME A COMPATIBLE COMPARISON WITH DATE THEN SUBTRACT THEM AND COMPARE THEM AND RETURN THE BOOLEAN BELOW
	return (QuantityOnHand > 0)/* || (currentdate>Leadtime)*/; }
//*********************************************************** this needs fixed above
bool InventoryItem::operator >(InventoryItem& const other) {
	if (SKU > other.SKU)
		return true;
	else
		return false;
}
bool InventoryItem::operator <(InventoryItem& const other) {
	if (SKU < other.SKU)
		return true;
	else
		return false;
}
bool InventoryItem::operator ==(InventoryItem& const other) {
	if (SKU == other.SKU)
		return true;
	else
		return false;
}
ostream& operator <<(ostream& out, const InventoryItem& other) {
	out<< "SKU: " << other.SKU << "\n Description : " << other.Description << "\n Price : " << other.Price << "\n UOM : " << other.UOM << "\n Quantity On Hand : " << other.QuantityOnHand << "\n Lead Time : " << other.LeadTime << endl;
	return out;
}
