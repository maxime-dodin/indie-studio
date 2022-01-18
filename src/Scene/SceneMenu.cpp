/*
** EPITECH PROJECT, 2021
** B-YEP-400-PAR-4-1-indiestudio-clement1.ruat
** File description:
** SceneMenu
*/

#include <chrono>
#include "Raylib.hpp"
#include <fstream>
#include "SceneMenu.hpp"
#include "UiGame/TexteUi.hpp"
#include "Core.hpp"
#include "Button/Button.hpp"

namespace menu {

    SceneMenu::SceneMenu(Setting &settings) : UiScene(settings), _isDancing(false), _isLock(false), isBack(false)
    {
        setInputFunction(Raylib::PRESSED, [&]() {
            _pressed = true;
        });
        setInputFunction(Raylib::SPACE, [&]() {
        _isDancing = true;
        });
        setInputFunction(Raylib::RELEASED, [&]() {
            _pressed = false;
            for (auto &it : _objects)
                if (it->getTypeField().isButton) {
                    auto button = std::dynamic_pointer_cast<button::Button>(it);
                    if (button->isInside(_mousePos)) {
                        _state = std::find(_menuText.begin(), _menuText.end(), button->getText()) - _menuText.begin();
                        return;
                    }
                }
        });
        _objects.emplace_back(std::make_shared<UiObject>(coords(), std::make_pair(0, 0), _bgPath, 1.0f));
        _objects.emplace_back(std::make_shared<Animator>(coords(5, 0, 11), coords(1, 1, 1), std::make_pair(menu::assetsPath.at(3), menu::assetsPath.at(0)), menu::assetsPath.at(1)));
        _objects.back()->setScale(0.03f);
        for (std::size_t i = 0; i != QUIT + 1; ++i)
            _objects.emplace_back(std::make_shared<button::Button>(_menuPos.at(i), button::_buttonSize, button::_buttonNavigPath, _menuText[i], 20, 2, std::make_pair(RGB(), RGB(0, 0, 0))));
        _objects.emplace_back(std::make_shared<TexteUI>(coords(670, 100), std::make_pair(0, 0), "DOOM TANK", 90, 1, std::make_pair(RGB(0, 0, 0), RGB())));
    }

    SceneMenu::~SceneMenu()
    {
        _objects.clear();
    }

    bool SceneMenu::canOpen()
    {
        std::ifstream file(".tank.txt");
        std::ifstream map(".destructibleList.txt");
        std::ifstream ia(".tankAi.txt");

        if(file.good() && map.good() && ia.good())
            return true;
        return false;
    }

    void SceneMenu::eventScene(Raylib &lib)
    {
        lib.displayMusic(core::MAP_MUSIC.at(core::soundPath::MENU), _settings._musicVol);
        for (auto it = _objects.begin(); it != _objects.end();) {
            if (it->get()->getTypeField().isAnimator) {
                if (_isDancing && !_isLock) {
                    _objects.emplace_back(std::make_shared<Animator>(coords(5, 0, 11), coords(1, 1, 1), std::make_pair(menu::assetsPath.at(3), menu::assetsPath.at(0)), menu::assetsPath.at(2)));
                    _objects.back()->setScale(0.03f);
                    it = _objects.erase(it);
                    _isLock = true;
                    continue;
                }
                auto anim = std::dynamic_pointer_cast<Animator>(*it);
                if (isBack) {
                    anim->addFrameCount(-1);
                    if (anim->getFrameActual() == 0) {
                        anim->setAnimPath(assetsPath.at(1));
                        _isDancing = false;
                        _isLock = false;
                        isBack = false;
                    }
                }
                else
                    anim->addFrameCount(1);
                if (anim->getFrameActual() >= lib.getFrameMax(assetsPath.at(1)))
                    isBack = true;
            }
            it++;
        }
    }

    Scenes SceneMenu::endScene(Raylib &lib) noexcept
    {
        if (_state == 1) {
            if (canOpen() == true) {
                _settings.load = true;
            } else {
                _settings._statementLoad = true;
            }
        }
        return (_returnScene.at(static_cast<menu_e>(_state)));
    }
}