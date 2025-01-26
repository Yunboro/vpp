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

void a02_1() {
    ProduktMitPreisHistory _pph1{"Raspi", 23.78};
    ProduktMitPreisHistory _pph2 = _pph1;
    std::cout << "pph2.getCounter(): " << _pph2.getCounter() << std::endl;
    std::cout << "pph1.getCounter(): " << _pph1.getCounter() << std::endl;
    _pph2.setPreis(25.49);
    std::cout << "pph1.getPreis(): " << _pph1.getPreis() << std::endl;
    std::cout << "pph2.getPreis(): " << _pph2.getPreis() << std::endl;
}

void a02_2() {
    // Objekt auf dem Stack erstellen
    ProduktMitPreisHistory stackObj("Produkt1", 100.0);
    IProdukt& stackRef = stackObj;

    // Methoden über die Referenz aufrufen
    std::cout << "Stack Object Name: " << stackRef.getName() << std::endl;
    std::cout << "Stack Object Initial Price: " << stackRef.getPreis() << std::endl;
    stackRef.setPreis(120.56);
    stackRef.setPreis(123.56);
    stackRef.setPreis(143.5);
    stackRef.setPreis(133.2);
    std::cout << stackRef << std::endl;

    // Objekt auf dem Heap erstellen
    ProduktMitPreisHistory* heapObj = new ProduktMitPreisHistory("Produkt2", 69.0);
    IProdukt* heapPtr = heapObj;

    // Methoden über den Pointer aufrufen
    std::cout << "Heap Object Name: " << heapPtr->getName() << std::endl;
    std::cout << "Heap Object Initial Price: " << heapPtr->getPreis() << std::endl;
    heapPtr->setPreis(220.0);
    heapPtr->setPreis(120.56);
    heapPtr->setPreis(123.56);
    heapPtr->setPreis(143.5);
    heapPtr->setPreis(127.2);
    heapPtr->setPreis(133.2);
    std::cout << *heapPtr << std::endl;

    // Heap-Speicher freigeben
    delete heapObj;
}

void mymain() {
    //a01();
    //a02_1();
    //a02_2();
}

int main(int argc, char *argv[]) {
    mymain();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}