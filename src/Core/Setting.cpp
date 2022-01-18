/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** Setting
*/

#include "Setting.hpp"

Setting::Setting(int widthScreen, int heightScreen, const std::size_t &fps, float musicVol, float soundVol)
    : _musicVol(musicVol), _soundVol(soundVol), _widthScreen(widthScreen), _heightScreen(heightScreen), _fps(fps),
    _keysPlayerOne({Raylib::Z, Raylib::S, Raylib::Q, Raylib::D, Raylib::A, Raylib::E, Raylib::SPACE}),
    _keysPlayerTwo({Raylib::UP, Raylib::DOWN, Raylib::LEFT, Raylib::RIGHT, Raylib::I, Raylib::O, Raylib::P}),
    _keysPlayerThree({Raylib::JRU, Raylib::JRD, Raylib::JRL, Raylib::JRR, Raylib::JLL, Raylib::JLR, Raylib::JA})
{
    _keysPlayers[0] = _keysPlayerOne;
    _keysPlayers[1] = _keysPlayerTwo;
    _keysPlayers[2] = _keysPlayerThree;
}

Setting::Setting(const Setting &settings)
    : Setting(settings._widthScreen, settings._heightScreen, settings._fps, settings._musicVol, settings._soundVol)
{
}