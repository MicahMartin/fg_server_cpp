# Godot fighting game simulation server example

### handles all game logic and uses godot basically like a 3d renderer. 
A lot of FG developers use this technique when integrating with a big boy engine (handle simulation yourself and use engine to render)

a lot of the logic in this repo is outdated. see https://github.com/MicahMartin/InputParser for updated virtual controller 

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_INSTALL_PREFIX=./install -G Ninja

cmake --build build

see cmake for info on what you need to put in your gdproject
