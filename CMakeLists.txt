cmake_minimum_required(VERSION 3.29)
project(TP_leVillage)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.7.2/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        REQUIRED)

add_executable(TP_leVillage main.cpp
        Weapon.cpp
        Weapon.h
        Item.cpp
        Item.h
        Sword.cpp
        Sword.h
        Wand.cpp
        Wand.h
        Hero.cpp
        Hero.h
        Warrior.cpp
        Warrior.h
        Wizard.cpp
        Wizard.h
        Inventory.cpp
        Inventory.h
        Paladin.cpp
        Paladin.h
        Shield.cpp
        Shield.h
        Potion.cpp
        Potion.h
        PotionHeal.cpp
        PotionHeal.h
        PotionStrength.cpp
        PotionStrength.h
        PotionDefense.cpp
        PotionDefense.h
        Monster.cpp
        Slime.cpp
        Zombie.cpp
        Dragon.cpp
        Village.cpp
        Building.cpp
        Hostel.cpp
        MonsterGenerator.h
        MenuManager.h
        MenuManager.cpp
        HeroMenu.h
        HeroMenu.cpp
        Menu.h
        Menu.cpp
        InventoryMenu.h
        HostelMenu.h
        Mine.cpp
        Mine.h
        PlaySound.h
        PlaySound.cpp
        Shop.cpp
        ShopMenu.h
)
target_link_libraries(TP_leVillage
        Qt::Core
        winmm
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
