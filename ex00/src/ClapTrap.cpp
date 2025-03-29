/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:45 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/29 19:31:00 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " is created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " is created." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "ClapTrap copy constructor called with source name: " << src._name << "." << std::endl;
    _name = src._name;
    _hitpoints = src._hitpoints;
    _energyPoints = src._energyPoints;
    _attackDamage = src._attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "ClapTrap assignation operator called with right hand side name: " << rhs._name << "." << std::endl;
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitpoints = rhs._hitpoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is destroyed." << std::endl;
}

std::string ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getHitpoints() const
{
	return (_hitpoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

void ClapTrap::attack(const std::string &target)
{
    if (_hitpoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and can't attack." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitpoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Ouch!" << std::endl;
    if (amount >= _hitpoints)
    {
        _hitpoints = 0;
        std::cout << "Oh no! ClapTrap " << _name << " died!" << std::endl;
    }
    else
    {
        _hitpoints -= amount;
        std::cout << "ClapTrap " << _name << " has " << _hitpoints << " hitpoints left." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitpoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy and can't repair." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " regains " << amount << " hitpoint(s)!" << std::endl;
    _hitpoints += amount;
    std::cout << "ClapTrap " << _name << " now has " << _hitpoints << " hitpoints." << std::endl;
	_energyPoints--;
}
