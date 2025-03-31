/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:20:06 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/31 11:25:29 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
	_isGuarding = false;
    std::cout << "ScavTrap " << _name << " is created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
	_isGuarding = false;
    std::cout << "ScavTrap " << _name << " is created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called with source name: " << src._name << "." << std::endl;
    *this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap assignation operator called with right hand side name: " << rhs._name << "." << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        _isGuarding = rhs._isGuarding;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is destroyed." << std::endl;
}

void ScavTrap::guardGate()
{
    if (_hitpoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is already dead and can't enter Gate keeper mode." << std::endl;
        return;
    }
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is out of energy and can't enter Gate keeper mode." << std::endl;
		return;
	}
	if (_isGuarding)
	{
		std::cout << "ScavTrap " << _name << " is already in Gate keeper mode." << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " has entered Gate keeper mode." << std::endl;
    _isGuarding = true;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitpoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is already dead." << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is out of energy and can't attack." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}
