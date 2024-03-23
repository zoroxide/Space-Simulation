echo "Compiling File ....."
g++ starfield.cpp olcPixelGameEngine.h -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17
echo "Done Compiling, opening the executable...."
./a.exe

