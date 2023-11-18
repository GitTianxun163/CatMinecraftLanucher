@echo off

echo mocing
moc src/Application.h -o build/moc_Application.cpp
moc src/Widgets/TitleBar.h -o build/moc_TitleBar.cpp
moc src/Widgets/DailogButton.h -o build/moc_DailogButton.cpp

echo Objecting
g++ -c src/main.cpp -o build/main.o -I %QT_HOME%\include -I include
g++ -c src/Application.cpp -o build/Application.o -I %QT_HOME%\include -I include
g++ -c src/Widgets/TitleBar.cpp -o build/TitleBar.o -I %QT_HOME%\include -I include
g++ -c src/Widgets/DailogButton.cpp -o build/DailogButton.o -I %QT_HOME%\include -I include

echo Resources Complating
windres -i src/Resources/resources.rc -o build/rc.o -F pe-x86-64

echo Linking
g++ build/*.o build/moc_*.cpp %QT_HOME%/lib/*.a -I %QT_HOME%\include -o bin/release_win64/lanucher.exe -Wl,--subsystem,windows -m64

echo Complate Suffuily!