/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:30:48 by obouayed          #+#    #+#             */
/*   Updated: 2025/03/29 18:12:52 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

int main()
{
    std::cout << "\n=== TESTING CONSTRUCTORS ===\n" << std::endl;
    
    // Test default constructor
    ScavTrap defaultTrap;
    
    // Test parameterized constructor
    ScavTrap scavtrap1("SC4V-TP");
    
    // Test copy constructor
    ScavTrap scavtrap2(scavtrap1);
    
    std::cout << "\n=== TESTING BASIC FUNCTIONALITY ===\n" << std::endl;
    
    // Test attack function - note this uses ScavTrap's version
    scavtrap1.attack("Bandit");
    
    // Test takeDamage function - inherited from ClapTrap
    scavtrap1.takeDamage(30);
    
    // Test beRepaired function - inherited from ClapTrap
    scavtrap1.beRepaired(15);
    
    // Test unique ScavTrap ability
    scavtrap1.guardGate();
    
    std::cout << "\n=== TESTING ENERGY DEPLETION ===\n" << std::endl;
    
    // Attack multiple times to deplete energy
    for (int i = 0; i < 50; i++) {
        if (i % 10 == 0)
            std::cout << "Attack attempt " << (i + 1) << ": ";
        scavtrap2.attack("Target Dummy");
        if (i % 10 == 9)
            std::cout << std::endl;
    }
    
    // Try actions with no energy
    std::cout << "\nAttempting to attack with no energy:" << std::endl;
    scavtrap2.attack("Enemy");
    
    std::cout << "\n=== TESTING LETHAL DAMAGE ===\n" << std::endl;
    
    // Create a new ScavTrap for damage testing
    ScavTrap defender("Defender");
    
    // Deal a lot of damage
    std::cout << "Dealing massive damage:" << std::endl;
    defender.takeDamage(150);
    
    // Try actions while dead
    defender.attack("Someone");
    defender.beRepaired(10);
    defender.guardGate();
    
    return (0);
}

