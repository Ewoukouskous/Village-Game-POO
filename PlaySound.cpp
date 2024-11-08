//
// Created by amiar on 07/11/2024.
//
#include <windows.h>


void StopSound() {
    PlaySound(NULL, NULL, 0); // Arrêtez le son
}


void PlaySoundHostel() {
    // Démarrer la lecture de la musique
    PlaySound(TEXT("HostelMusic.wav"), NULL,SND_LOOP |  SND_ASYNC);
}

void PlaySoundShop() {
    PlaySound(TEXT("ShopMusic.wav"), NULL,SND_LOOP |  SND_ASYNC);

}

void PlaySoundCave() {
    PlaySound(TEXT("MineMusic.wav"), NULL, SND_LOOP | SND_ASYNC);
}

void PlaySoundCongratsSFX() {
    PlaySound(TEXT("CongratSFX.wav"), NULL, SND_ASYNC);
}