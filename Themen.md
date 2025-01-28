# Lernliste für die Klausur: Vertiefte Programmierpraxis (17.01.2025)

## **Themengebiete**
### 1. Typumwandlungen (Casting)
- **Static Cast**  
  - Wird verwendet, wenn der Typ zur Compilezeit bekannt ist.
- **Dynamic Cast**  
  - Ermöglicht Typprüfung (z. B. ob ein Objekt zu einer bestimmten abgeleiteten Klasse gehört).
  - **Downcasting**: Umwandlung von einer Basisklasse zu einer abgeleiteten Klasse.
  - Gibt einen Nullpointer zurück, wenn die Typprüfung fehlschlägt.

---

### 2. Objektorientierung
- **Klassenkonzepte**  
  - Einfache Klassen, Konstruktoren, Destruktoren.
- **Vererbung und Polymorphie**  
  - `virtual` und rein virtuelle Methoden (mit `= 0`).
  - Überschreiben vs. Überladen.
- **Big Three**  
  - Kopierkonstruktor, Zuweisungsoperator, Destruktor.
- Delegierende Konstruktoren.
- **const correctness**  
  - Getter sollten `const` sein.

---

### 3. Lambda-Funktionen
- Lambda-Parameter und `mutable`.
- Aufrufoperator in Lambdas ist `const` – mit `mutable` kann dies überschrieben werden.

---

### 4. C++ Grundlagen
- Komplexe Deklarationen (z. B. Funktionszeiger).
- Umgang mit Referenzen und Zeigern (`*`, `const`).
- Formatierte Ausgabe von Gleitkommazahlen.
- Sichere Speicherverwaltung:
  - Listen vom Speicher nehmen, neue erstellen.

---

### 5. Templates und STL
- **Templates**  
  - Funktionstemplates.  
  - Klassentemplates.
- **STL Container**  
  - Anlegen, Befüllen (z. B. `push_back`, Initializer-Listen).  
  - Iteration (bereichsbasierte Schleifen, Iteratoren).  
- **Äquivalent zu `map`**:  
  - `transform` für Objekte.
- `generate` für Funktoren ohne Übergabeparameter.

---

### 6. Ausnahmebehandlung (Exceptions)
- `try-catch` mit vorgegebenen Typen und Fehlermeldungen.
- **Throw by value, catch by const reference.**

---

### 7. Verkettete Listen
- Einfache verkettete Listen.  
- Einfügen/Löschen am Anfang und Ende.  
- Ausgabe von Listen.  
- Überladen von Ausgabeoperatoren (`+`, `-`).

---

### 8. UML-Diagramme
- Aufbau von Ober- und Unterklassen.  
- Ausgegraute Klassen/Methoden: Hinweis, dass keine Implementierung notwendig ist.

---

### 9. Mathematische Funktionen
- Berechnung der n-ten Wurzel (`x^(1/n)` – Punkt beachten, um falsche Ergebnisse zu vermeiden).
- Nutzung der `math`-Bibliothek.

---

## **Praktische Aufgaben**
### Implementieren:
- Methode `setPreis(double)` für eine Klasse.  
- Liste befüllen und ausgeben (z. B. mit STL-Containern).  
- Funktoren und Lambda-Funktionen anwenden.

### Debugging-Aufgaben:
- Fehler in Member-Initialisierung (Reihenfolge beachten).  
- Fehler beim Casten finden.

---

## **Zusätzliche Hinweise**
- Theoriefragen können zu den Zusatzaufgaben kommen.  
- Alle `#include`-Dateien stehen zur Verfügung.  
- Aufteilung zwischen Header (`.h`) und Implementierungsdatei (`.cpp`) ist nicht essenziell.
