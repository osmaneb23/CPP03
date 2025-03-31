/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:50:19 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/31 12:32:39 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
    _name = "default";
    _hitpoints = FragTrap::getHitpoints();
    _energyPoints = ScavTrap::getEnergyPoints();
    _attackDamage = FragTrap::getAttackDamage();
    std::cout << "DiamondTrap " << _name << " is created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
    _name = name;
    _hitpoints = FragTrap::getHitpoints();
    _energyPoints = ScavTrap::getEnergyPoints();
    _attackDamage = FragTrap::getAttackDamage();
    std::cout << "DiamondTrap " << _name << " is created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
    std::cout << "DiamondTrap copy constructor called with source name: " << src._name << "." << std::endl;
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
    std::cout << "DiamondTrap assignation operator called with right hand side name: " << rhs._name << "." << std::endl;
    if (this != &rhs)
    {
        ScavTrap::operator=(rhs);
        _name = rhs._name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " is destroyed." << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
