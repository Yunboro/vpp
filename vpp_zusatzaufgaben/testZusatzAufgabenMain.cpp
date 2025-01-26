// (c) KJR
#include "tst_testaufgaben.h"
#include "produktmitpreishistory.h"
#include "hochlager.h"
#include "a04.h"
#include "produkt.h"
#include <iostream>
#include <gtest/gtest.h>

using std::cout;
using std::endl;

void a01() {
    // Erstellen Sie auf dem Stack ein Objekt von Typ Produkt
    Produkt stackProdukt("StackProdukt", 10.0);
    // Lassen Sie dann eine Referenz vom Typ IProdukt& auf dieses Objekt verweisen
    IProdukt& stackRef = stackProdukt;
    // Verwenden Sie nun diese Referenz um alle erstellten Methoden aufzurufen
    cout << "Stack Produkt Name: " << stackRef.getName() << endl;
    cout << "Stack Produkt Preis: " << stackRef.getPreis() << endl;
    stackRef.setPreis(12.0);
    cout << "Stack Produkt Neuer Preis: " << stackRef.getPreis() << endl;
    cout << stackRef << endl;

    // Erstellen Sie auf dem Heap ein Objekt von Typ Produkt
    IProdukt* heapProdukt = new Produkt("HeapProdukt", 20.0);
    // Lassen Sie dann einen Pointer vom Typ IProdukt* auf dieses Objekt verweisen
    IProdukt* heapPtr = heapProdukt;
    // Verwenden Sie nun diesen Pointer um alle erstellten Methoden aufzurufen
    cout << "Heap Produkt Name: " << heapPtr->getName() << endl;
    cout << "Heap Produkt Preis: " << heapPtr->getPreis() << endl;
    heapPtr->setPreis(22.0);
    cout << "Heap Produkt Neuer Preis: " << heapPtr->getPreis() << endl;
    cout << *heapPtr << endl;
    cout << endl;
    // Vergessen Sie nicht danach den in Anspruch genommenen Heap-Speicher wieder frei zu geben
    delete heapProdukt;
}

void mymain() {
    a01();
}

int main(int argc, char *argv[])
{
  mymain();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}