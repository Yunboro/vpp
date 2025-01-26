# (c) KJR
# CMake file fuer den bereitgestellten Google-Test fuer die 
# zusammenfassenden Aufgaben (alle Sourcen sind bereits eingetragen
# und die Pfade fuer Windows sind gesetzt)
# generisches CMakeLists.txt File fuer die Uebersetzung von cpp-Programmen
# NUR  Google-Test verwenden 
# Alles notwendige fuer Komponenten aus Qt ist auskommentiert
# !!!!!!! Entsprechende Pfade fuer das eigene System anpassen !!!!!!

# Minimale CMake Version
cmake_minimum_required(VERSION 3.15) 

# Allgemeine Einstellungen fuer die unterschiedlichen
# Betriebssysteme
if(WIN32)
   message("------> System ist Win32")
   # fuer Windows sollten folgende Pfade und Variablen
   # gesetzt werden, diese an Ihr System anpassen
   set(CMAKE_CXX_COMPILER "C:/Qt/Tools/mingw1120_64/bin/g++.exe")
   #set(CMAKE_CXX_COMPILER "C:/Qt/Tools/mingw810_64/bin/g++.exe")
   
   # !!!! Wenn Sie den MinGW Compiler verwenden stelle Sie 
   # sicher dass  die Umgebungsvariable 
   # CMAKE_GENERATOR auf MinGW Makefiles gesetzt ist
   # oder rufen Sie in der Konsole cmake im Verzeichnis  build auf mit der Anweisung
   # cmake -G  "MinGW Makefiles" ..
   # danach in der Konsole mingw32-make
   # Leider kann man mit den folgenden Versuchen die nicht 
   # hier fest setzen, die Einstellung kommt zu spaet.      
   # et(ENV{CMAKE_GENERATOR} "MinGW Makefiles")
   #set (CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
 
   # fuer Google-Test
   set(GOOGLETEST_DIR "C:/Qt/googletest")

   # fuer Komponenten aus Qt
   list(APPEND CMAKE_PREFIX_PATH "C:/Qt/6.2.3/mingw_64/lib/cmake")
   
elseif(APPLE)
   message("------> System ist Apple")
   # Kann ich selber nicht ausprobieren, Einstellungen sind gegoogelt

   # fuer Google-Test
   #set(GOOGLETEST_DIR "/Applications/Qt/Googletest/googletest-main")
   set(GOOGLETEST_DIR "/Users/UserName/Qt/googletest-main")
   
   # fuer Komponenten aus Qt
   #list(APPEND CMAKE_PREFIX_PATH "/Users/UserName/Qt/6.7.0/macos/lib/cmake")
   #list(APPEND CMAKE_PREFIX_PATH "/Users/UserName/Qt/6.7.0/macos/bin")
   #list(APPEND CMAKE_PREFIX_PATH "/Applications/Qt/5.9.2/clang_64/lib/cmake")
   #list(APPEND CMAKE_PREFIX_PATH "Applications/Qt/5.9.2/clang_64/bin")

   # CMAKE_GENERATOR sollte auf Unix Makefiles gesetzt sein
   # auch in CMake Extensions fuer Visual Studio Code‚
elseif(UNIX)
    message(" -----> System ist UNIX")
    # fuer Unix/Linux sollten folgende Pfade und Variablen
   # gesetzt werden, diese an Ihr System anpassen

    # fuer Google-Test
    set(GOOGLETEST_DIR "/opt/googletest-main")
    
    # fuer Komponenten aus Qt
    list(APPEND CMAKE_PREFIX_PATH "/opt/Qt/5.12.11/gcc_64/lib/cmake")
endif()

# Zur Kontrolle Ausgabe des gesetzten Generators
message("--------> generator is set to ${CMAKE_GENERATOR}")

# Setzen des C++ Standards und dass eine Debug-Version erstellt wird
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# Setzen des Projekt-Namens und der Programmiersprache auf C++
project(aufgabentest LANGUAGES CXX)

# cpp-Dateien und Header-Dateien die zum Projekt gehoeren hier angeben
# bis auf die cpp-Datei mit main()
set(PROJECT_SOURCES
        a04.h a04.cpp
		hochlager.h hochlager.cpp
		iprodukt.h iprodukt.cpp
		produkt.h produkt.cpp
		produktmitpreishistory.h produktmitpreishistory.cpp
		tst_testaufgaben.h
)

# Variablen fuer Google-Test 
# wenn oben GOOGLETEST_DIR richtig gesetzt wurde 
# sind hier KEINE Aenderungen notwendig
if (EXISTS ${GOOGLETEST_DIR})
    set(GTestSrc ${GOOGLETEST_DIR}/googletest)
    set(GMockSrc ${GOOGLETEST_DIR}/googlemock)

else ()
    message( FATAL_ERROR "No googletest src dir found - set GOOGLETEST_DIR to enable!")
endif ()
set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
include_directories(${GTestIncludes})

# fuer Linux
find_package(Threads REQUIRED)

# Qt6 Komponenten finden 
#find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
# Falls noch Qt5 verwendet wird
#find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Test aktivieren 
add_test(NAME aufgabentest COMMAND v3test)

# Angabe aller Executables, die erstellt werden sollen zusammen mit
# der Quell-Datei fuer main()
add_executable(aufgabentest testZusatzAufgabenMain.cpp ${PROJECT_SOURCES} ${GTestFiles})

# Angabe aller Bibliotheken (libraries, die beim Linken verwendet werden sollen)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

# Fuer Qt6
#target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
#target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

# Fuer Qt5
#target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)
#target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)


