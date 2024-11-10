//
// Created by amiar on 07/11/2024.
//

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <windows.h>

void StopSound() {
    PlaySound(NULL, NULL, 0); // Arrêtez le son
}

void PlaySoundHostel() {
    // Play the music
    PlaySound(TEXT("../musics/HostelMusic.wav"), NULL,SND_LOOP |  SND_ASYNC);
}

void PlaySoundShop() {
    PlaySound(TEXT("../musics/ShopMusic.wav"), NULL,SND_LOOP |  SND_ASYNC);

}

void PlaySoundCave() {
    PlaySound(TEXT("../musics/MineMusic.wav"), NULL, SND_LOOP | SND_ASYNC);
}

void PlaySoundCongratsSFX() {
    PlaySound(TEXT("../musics/CongratSFX.wav"), NULL, SND_ASYNC);
}

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;

std::string readFileIntoString(const std::string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << path << "'" << endl;
        // exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

void setCursorPosition(int x, int y) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void draw(int frame) {
    setCursorPosition(0, 0);
    std::string m = readFileIntoString("../texts/frame" + std::to_string(frame));
    std::cout << m;
}

bool isEscPressed() {
    // Check if the key 'ENTER' is pressed
    return (GetAsyncKeyState(VK_ESCAPE) & 0x8000) != 0;
}

void invicibleCheat() {
    cout << "You know that's bad to cheat ? ;]"<<endl;
    Sleep(3000);
    HWND console = GetConsoleWindow();

    MoveWindow(console, 0, 10, 945, 750, TRUE);

    // draw(1);
    system("cls");

    // Start the music
    PlaySound(TEXT("../musics/specialSFX.wav"), NULL, SND_ASYNC);

    // Initialize the animation control variable
    int frame = 1;
    auto start = std::chrono::steady_clock::now();

    while (true) {
        // Check if 'ESC' is pressed to QUIT
        if (isEscPressed()) {
            break;
        }

        // Draw the current frame
        draw(frame);

        // Wait a little before drawing the next one
        std::this_thread::sleep_for(std::chrono::milliseconds(35));

        // Increment frame and reinitialize it when he reaches 51
        frame++;
        if (frame > 51) {
            frame = 1;
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { // if 'ESC' is press , break
            break;
        }
    }

    PlaySound(NULL, NULL, 0); // Stop the sound
    system ("cls");
}