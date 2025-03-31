/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:27:02 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/31 11:36:13 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is created." << std::endl;
}

FragTrap::FragTrap(FragTrap const & src): ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called with source name: " << src._name << "." << std::endl;
    *this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    std::cout << "FragTrap assignation operator called with right hand side name: " << rhs._name << "." << std::endl;
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " is destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (_hitpoints == 0)
    {
        std::cout << "FragTrap " << _name << " is already dead and can't high five." << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "FragTrap " << _name << " is out of energy and can't high five." << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
