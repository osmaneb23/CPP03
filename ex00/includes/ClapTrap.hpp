/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:50 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/29 19:30:38 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    private:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		
    public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &rhs);
		~ClapTrap();
		
		std::string		getName() const;
		unsigned int	getHitpoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
		
        void			attack(const std::string &target);
        void			takeDamage(unsigned int amount);
        void			beRepaired(unsigned int amount);
};

#endif