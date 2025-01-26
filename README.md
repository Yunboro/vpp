#### Vertiefte Programmierpraxis 17.01.2025

- static and dynamic cast

- falls Typ zur compile zeit bekannt dann static cast

- mit **dynamic cast** kann man eine Typüberprüfung machen
  
  - auf pointer wekstück zeigen, dass dass dynamic cast kein nullpointer ist

dynamic cast

- Downcasting: Wenn Sie von einer Basisklasse z ueiner abgeleiteten Klasse umwandeln möchten

- Typprüfung: Üebrprüfen ob ein Objekt tatsächlich zu einer best. abgeleiteten Klasse gehört

- Name eines Funktion ist in C schon immer die Anfangsadresse

- [ ] Lambda Parameter gemacht

- [x] kein mutable

Zusatzaufgaben

setPreis(p: double)

fehlt in Klasse Produkt

Objektorientierung, einfache Klasse

Vererbung Big Three

Templates, Verkettete Listen

Funktionale Programmierunge, STL

Klausurnotizen

Gitller Anweisung in der Memberinitialisierungsliste (nach::) werden nicht wie beschrieben gemacht. sondern in der Reihenfolge, wie die Attribute angelegt wurden.

add operator kann man konvertierenden konstruktor haben. dann funktioniert vector+int , denn dann wird int in vector konvertiert

Funktion höherer Ordnung

mutable ? kommt an dem mutable an das t nicht herum. wenn der compiler auch selbst die funktion mutable objekt macht dann muss das lambda entsprechend auch mutbale sein. T wird verändernt. Aufrufoperator ist ja immer const.

- [ ] Lambda Parameter gemacht

- [ ] formatierte Ausgabe von Gleitpunktszahlen 2-3 Punkte

- [ ] sichere Umgang referenz pointer const

- [ ] stern und const, Links und Rechts

- [ ] komplexe deklaration, funtionszeiger

uml diagramm, einfache klasse, standardkonstruktor, konvertierend und nicht

delegierender konstruktor

seuqenzkonstruktor, destruktor#

big three

kein move konstruktor

const correctness, getter sollte const haben

vererbung, virtual, rein virtuelle mit gleich 0

polymoprh und polymorphe typ

überschreiben überladen

erstellung von objekten, mit stl container, wenn es ein "Eckige Klammer"

excpetions auswerfen sollte man können, try - catch, typ wird vorgegeben und was die fehlermeldung sein soll, trohw by value, catch by const reference

verkettete liste einfach

liste vom speicher nehmen

neue liste erstellen auf dem heap

zusatzaufgaben siehe hochlager einfügen/löschen am anfang ende, nach hinten hangeln

ausgabe einer liste

überladen ausgabe operator + -

manche überladen memberfunktion oder als freie funktion (kein friend)

templates, funktionstemplates, klassentempaltes

heute was zur funktionalen programmierung

stl container anlegen, befüllen, durchlaufen/iterieren bereichsbasierte schleife oder iterator

befüllen mit push back oder initializer list

wenn in klasse implementiert inder klasse dann inline

UML Diagramm. Oberklasse und Unterklasse ist ausgegraut. Ausgegraute Klasse. virtual bei Methoden und vererbende Struktoren

Kann auch anders herum sein, dass ausgegraut Oberklasse und Unterklasse markiert.

Einzelne Methoden ausgegraut. Darf man einfach im main verwenden, müssen nicht implementiert werden. Steht jedoch in der Angabe

includes sind alles drinn

keine composites, kein singleton, kein observer

aufteilung header und cpp nicht so wichtig

strichpunkte nicht wichtig

n-te Wurzel aus x berechnen. 1. (mit punkt) sonst wird nur ganzzahlige division gemacht. das kann zu falschen ergebnissen führen

schauen was in math drin ist.

halbes niveeau von den letzeten zusatzaufgaben ist ungefähr angemessen.

E302 am Mittwoch. Nachmittags um 14:15 - 17:30

generate für einen funktor der keinen übergabe parameter hat zum befüllen

äquivalente zum map ist das transform, ruft für jedes objekt auf.

wir brauchen jedoch eher das generate

mini theoriefragen kommen dran

zusatzaufgaben sind auch theoriefragen 

dynamic und static cast - 
