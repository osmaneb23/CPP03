/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:45 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/29 18:25:26 by obouayed         ###   ########.fr       */
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
    std::cout << "ClapTrap copy constructor called with name: " << _name << " and source name: " << src._name << "." << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "ClapTrap assignation operator called with name: " << _name << " and right hand side name: " << rhs._name << "." << std::endl;
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
}
