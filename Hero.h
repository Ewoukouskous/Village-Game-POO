//
// Created by amiar on 23/10/2024.
//

#ifndef HERO_H
#define HERO_H

#include "Inventory.h"
#include "Sword.h"
#include "Wand.h"
#include "Shield.h"
#include "PotionHeal.h"
#include "PotionStrength.h"
#include "PotionDefense.h"
#include "Building.h"

class Building;

class Monster;

// La classe abstraite 'Hero' a pour enfant :
// - 'Warrior' : Peut uniquement équiper une arme 'Sword', pas de 'Shield'
// et possède 50% en plus de 'm_attack'
//
// - 'Paladin' : Peut uniquement équiper une arme 'Sword' et un 'Shield'
//
// - 'Wizard' : Peut uniquement équiper une arme 'Wand', pas de 'Shield'
// et a une chance d'esquive de 20% ('m_dodge = 20')

using namespace std;

class Hero {
// Par défaut les héros ont pour attribut:
private:
    string m_name; // un nom
    int m_health; // = 100
    int m_gold; // = 50

    // Les attributs pouvant être changé par en fonction de la classe:
protected:
    string m_type;
    int m_attack; // Par défaut = 10 | 'Warrior' = +50%
    int m_defense; // = 5
    int m_dodge; // Par défaut = 0 | 'Wizard' = 20
    Weapon* m_weapon = nullptr; // Tous peuvent avoir une arme
    Inventory* m_inventory = nullptr; // Tous ont un inventaire (qui est crée via le constructeur)
    Building* m_currentLocation = nullptr;

public:

    // Pour créer un hero uniquement un nom est nécessaire
    Hero(const string &name);
    virtual ~Hero() {delete m_inventory; delete m_weapon;}
    // Le hero se présente ( Nom + classe)
    void introduceHimself() const;
    // Methode virtuelle pure pour équiper une arme (Les classes aurons certaines restrictions)
    virtual void equipWeapon(Weapon* ptr_weapon) = 0;
    // Range l'arme dans l'inventaire et la désequippe (si il reste de la place)
    void storeWeapon();
    // Supprime et DETRUIT l'arme équipée par le hero
    void dropWeapon();
    // Methode virtuelle pure qui permet d'équiper une arme ou bouclier depuis l'inventaire
    // (Certaines classes ne pourrons pas équiper de bouclier)
    virtual void equipFromInventory(const int indexItem) =0;

    // Ajoute un pointeur d'item dans l'inventaire
    void addToInventory(Item* ptr_item) const;
    // On supprime et detruit un objet de l'inventaire
    void removeFromInventory(int indexItem) const;

    void drinkFromInventory(int indexItem);

    void attackMonster(Monster *monster);

    virtual void beingHit(int mobAttack);

    // Suite de strings contenant toutes les stats du héro
    virtual string showStats() const;

    void travel(Building *ptr_building);

    void leave();


    // SETTERS
    void setHealth(int health) {
        m_health = health;
    }
    void setGold(int gold) {
        m_gold = gold;
    }
    void setAttack(int attack) {
        m_attack = attack;
    }
    void setCurrentLocation(Building *ptr_location) {
        m_currentLocation = ptr_location;
    }

    // Getters
    const string& getName() const {
        return m_name;
    }

    virtual const string& getType() const = 0;

    const int& getHealth() const {
        return m_health;
    }
    virtual int getDefense() const {
        return m_defense;
    }
    const int& getGold() const {
        return m_gold;
    }
    int getAttack() const {
        // L'attaque dépendra de l'arme équipée
        int attack = m_attack;
        if (m_weapon != nullptr) {
            attack += m_weapon->getDamage();
        }
        return attack;
    }

    const int& getDodge() const {
        return m_dodge;
    }

    const string getWeapon() const {
        if (m_weapon == nullptr) {
            return "NULL WEAPON";
        }
        return m_weapon->getName();
    }

    string getInventory() const {
        return m_inventory->getInventoryList();
    }

    Building* getCurrentLocation() const {
        return m_currentLocation;
    }
};

#endif //HERO_H
